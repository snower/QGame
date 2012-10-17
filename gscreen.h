#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define FRESH_TIME 70

#include <QtGui/QMainWindow>
#include "gscreencache.h"

class GGame;

class GScreen : public QMainWindow
{
    Q_OBJECT
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit GScreen(QWidget *parent = 0);
    virtual ~GScreen();

    // Note that this will only have an effect on Symbian and Fremantle.
    void SetOrientation(ScreenOrientation orientation);
    void ShowExpanded();
    void SetGame(GGame *gGame=NULL);
    bool StartTimer(int freshTime=FRESH_TIME);

protected:
    virtual void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event );
    virtual void mouseMoveEvent(QMouseEvent* event );
    virtual void mousePressEvent(QMouseEvent* event );
    virtual void mouseReleaseEvent(QMouseEvent* event );

protected:
    GGame *gGame;
    int freshTime;
    int timerId;
};

#endif // MAINWINDOW_H
