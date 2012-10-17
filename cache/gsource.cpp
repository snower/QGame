#include "gsource.h"
#include "gcachemanager.h"

GSource::GSource(GCacheManager *cacheManager,QString name,int outTime) : QObject()
{
    this->cacheManager=cacheManager;
    this->name=name;
    this->outTime=outTime;
    this->source.img=NULL;
    connect(&this->timer,SIGNAL(timeout()),this,SLOT(TimeOut()));
    connect(this,SIGNAL(timeOut(GSource*)),this->cacheManager,SLOT(RemoveSource(GSource*)));
}

GSource::~GSource(){
    this->timer.stop();
    disconnect(this->cacheManager,SLOT(deleteLater(GSource*)));
}

void GSource::TimeOut(){
    emit this->timeOut(this);
}

void GSource::updateTimer(){
    if(this->outTime!=0) this->timer.start(this->outTime);
}
