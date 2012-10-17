#ifndef GSOURCE_H
#define GSOURCE_H

#include <QObject>
#include <QTimer>
#include <QString>
#include <QImage>
#include <QSound>
#include <QMovie>

class GCacheManager;

class GSource : public QObject
{
    Q_OBJECT
public:
    GSource(GCacheManager *cacheManager,QString name,int outTime);
    ~GSource();

    void updateTimer();

public slots:
    void TimeOut();

signals:
    void timeOut(GSource *source);

public:
    union Source{
        QImage *img;
        QSound *sound;
        QMovie *movie;
    } source;

    QString name;

private:
    QTimer timer;
    int outTime;
    GCacheManager *cacheManager;
};

#endif // GSOURCE_H
