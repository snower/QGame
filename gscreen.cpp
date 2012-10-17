#include <QtCore/QCoreApplication>
#include <QPainter>
#include "gscreen.h"
#include "ggame.h"

GScreen::GScreen(QWidget *parent)
    : QMainWindow(parent)
{
    this->timerId=0;
    this->StartTimer();
}

GScreen::~GScreen()
{
}

void GScreen::SetOrientation(ScreenOrientation orientation)
{
#if defined(Q_OS_SYMBIAN)
    // If the version of Qt on the device is < 4.7.2, that attribute won't work
    if (orientation != ScreenOrientationAuto) {
        const QStringList v = QString::fromAscii(qVersion()).split(QLatin1Char('.'));
        if (v.count() == 3 && (v.at(0).toInt() << 16 | v.at(1).toInt() << 8 | v.at(2).toInt()) < 0x040702) {
            qWarning("Screen orientation locking only supported with Qt 4.7.2 and above");
            return;
        }
    }
#endif // Q_OS_SYMBIAN

    Qt::WidgetAttribute attribute;
    switch (orientation) {
#if QT_VERSION < 0x040702
    // Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
    case ScreenOrientationLockPortrait:
        attribute = static_cast<Qt::WidgetAttribute>(128);
        break;
    case ScreenOrientationLockLandscape:
        attribute = static_cast<Qt::WidgetAttribute>(129);
        break;
    default:
    case ScreenOrientationAuto:
        attribute = static_cast<Qt::WidgetAttribute>(130);
        break;
#else // QT_VERSION < 0x040702
    case ScreenOrientationLockPortrait:
        attribute = Qt::WA_LockPortraitOrientation;
        break;
    case ScreenOrientationLockLandscape:
        attribute = Qt::WA_LockLandscapeOrientation;
        break;
    default:
    case ScreenOrientationAuto:
        attribute = Qt::WA_AutoOrientation;
        break;
#endif // QT_VERSION < 0x040702
    };
    setAttribute(attribute, true);
}

void GScreen::ShowExpanded()
{
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_SIMULATOR)
    showFullScreen();
#elif defined(Q_WS_MAEMO_5)
    showMaximized();
#else
    show();
#endif
}

void GScreen::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    this->gGame->GetScreenCache()->Paint(&painter);
}

void GScreen::SetGame(GGame *gGame){
    this->gGame=gGame;
}

bool GScreen::StartTimer(int freshTime){
    if(this->timerId!=0){
        this->killTimer(this->timerId);
    }
    this->timerId=this->startTimer(freshTime);
    this->freshTime=freshTime;
    if(this->timerId==0) return false;
    return true;
}

void GScreen::timerEvent(QTimerEvent *event){
    this->repaint();
}

void GScreen::mousePressEvent(QMouseEvent *event){
    this->gGame->GetMouseManager()->PushEvent(GMouseEvent(event));
}

void GScreen::mouseReleaseEvent(QMouseEvent *event){
    GMouseEvent e(event);
    e.type=GMouseEvent::Release;
    this->gGame->GetMouseManager()->PushEvent(e);
}

void GScreen::mouseMoveEvent(QMouseEvent *event){
    GMouseEvent e(event);
    e.type=GMouseEvent::Move;
    this->gGame->GetMouseManager()->PushEvent(e);
}

void GScreen::mouseDoubleClickEvent(QMouseEvent *event){
    GMouseEvent e(event);
    e.type=GMouseEvent::DoubleClick;
    this->gGame->GetMouseManager()->PushEvent(e);
}
