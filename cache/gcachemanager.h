#ifndef GCACHEMANAGER_H
#define GCACHEMANAGER_H

#include <QObject>
#include <QMap>
#include "gsource.h"

class GGame;

class GCacheManager : public QObject
{
    Q_OBJECT
public:

    enum SourceType{
        Image,Sound,Movie
    };

    GCacheManager(GGame *gGame);

    bool RegisterSource(QString name,SourceType st=Image,int outTime=0);
    void* GetSource(QString name,SourceType st=Image,int outTime=15000);

private:
    void* GetOfSource(GSource *s,SourceType st);
    GSource* LoadSource(QString name,SourceType st,int outTime);
    QImage* LoadImage(QString name);
    QSound* LoadSound(QString name);
    QMovie* LoadMovie(QString name);

public slots:
    void RemoveSource(GSource *source);

private:
    GGame *gGame;
    QMap<QString,int> sources;
};

#endif // GCACHEMANAGER_H
