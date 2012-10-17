#include "gmouseeventmanager.h"
#include "../ggame.h"
#include "../tools/gvectoriterator.h"
#include <QMutexLocker>

GMouseEventManager::GMouseEventManager(GGame *gGame) : QThread()
{
    this->gGame=gGame;
}

void GMouseEventManager::run(){
    while(this->EventHandler()){
        //QThread::msleep(2);
    }
}

void GMouseEventManager::PushEvent(GMouseEvent event){
    this->mutex.lock();
    this->queueEvent.enqueue(event);
    this->mutex.unlock();
    this->start(QThread::HighestPriority);
}

void GMouseEventManager::mousePressNext(GMouseEvent *event){
    GVectorIterator iterator(this->gGame->GetLayerManager()->GetLayers());
    while(iterator.HasNext()){
        GLayer *lt=(GLayer*)iterator.Next();
        lt->mousePressNext(event);
        if(!lt->nextAction) break;
    }
}

void GMouseEventManager::mouseReleaseNext(GMouseEvent *event){
    GVectorIterator iterator(this->gGame->GetLayerManager()->GetLayers());
    while(iterator.HasNext()){
        GLayer *lt=(GLayer*)iterator.Next();
        lt->mouseReleaseNext(event);
        if(!lt->nextAction) break;
    }
}

void GMouseEventManager::mouseMoveNext(GMouseEvent *event){
    GVectorIterator iterator(this->gGame->GetLayerManager()->GetLayers());
    while(iterator.HasNext()){
        GLayer *lt=(GLayer*)iterator.Next();
        lt->mouseMoveNext(event);
        if(!lt->nextAction) break;
    }
}

void GMouseEventManager::mouseDoubleClickNext(GMouseEvent *event){
    GVectorIterator iterator(this->gGame->GetLayerManager()->GetLayers());
    while(iterator.HasNext()){
        GLayer *lt=(GLayer*)iterator.Next();
        lt->mouseDoubleClickNext(event);
        if(!lt->nextAction) break;
    }
}

bool GMouseEventManager::EventHandler(){
    this->mutex.lock();
    if(this->queueEvent.empty()){
        this->mutex.unlock();
        return false;
    }
    GMouseEvent e=this->queueEvent.dequeue();
    this->mutex.unlock();
    switch(e.type){
    case GMouseEvent::Press:
        this->mousePressNext(&e);
        break;
    case GMouseEvent::Release:
        this->mouseReleaseNext(&e);
        break;
    case GMouseEvent::Move:
        this->mouseMoveNext(&e);
        break;
    case GMouseEvent::DoubleClick:
        this->mouseDoubleClickNext(&e);
        break;
    }
    if(e.event!=NULL) delete e.event;
    return true;
}
