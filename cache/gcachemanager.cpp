#include "gcachemanager.h"

GCacheManager::GCacheManager(GGame *gGame)
{
    this->gGame=gGame;
}

bool GCacheManager::RegisterSource(QString name, SourceType st, int outTime){
    this->sources[name]=(int)this->LoadSource(name,st,outTime);
    return true;
}

void* GCacheManager::GetSource(QString name, SourceType st,int outTime){
    if(!this->sources.contains(name)){
       this->sources[name]=(int)this->LoadSource(name,st,outTime);
    }
    return this->GetOfSource((GSource*)this->sources[name],st);
}

void* GCacheManager::GetOfSource(GSource *s, SourceType st){
    s->updateTimer();
    switch(st){
    case Image:
        return s->source.img;
    case Sound:
        return s->source.sound;
    case Movie:
        return s->source.movie;
    }
    return NULL;
}


GSource* GCacheManager::LoadSource(QString name, SourceType st,int outTime){
    GSource *source=new GSource(this,name,outTime);
    switch(st){
    case Image:
        source->source.img=this->LoadImage(name);
        break;
    case Sound:
        source->source.sound=this->LoadSound(name);
        break;
    case Movie:
        source->source.movie=this->LoadMovie(name);
        break;
    }
    return source;
}

QImage* GCacheManager::LoadImage(QString name){
    QImage *img=new QImage();
    if(!img->load(name)) return NULL;
    return img;
}

QSound* GCacheManager::LoadSound(QString name){
    return new QSound(name);
}

QMovie* GCacheManager::LoadMovie(QString name){
    return new QMovie(name);
}

void GCacheManager::RemoveSource(GSource *source){
    this->sources.remove(source->name);
    delete source;
}
