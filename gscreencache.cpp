#include <QColor>
#include "gscreencache.h"
#include "ggame.h"
#include "tools/gvectoriterator.h"

GScreenCache::GScreenCache(int width,int height) : QThread()
{
    this->width=width;
    this->height=height;
    this->Init();
}

GScreenCache::~GScreenCache(){
}

void GScreenCache::Init(){
    this->cache=new QImage(this->width,this->height,QImage::Format_ARGB32);
}

void GScreenCache::Paint(QPainter *painter){
    this->mutex.lock();
    if(painter==NULL) return;
    painter->drawImage(0,0,*this->cache);
    this->mutex.unlock();
}

void GScreenCache::run(){
    QPainter painter(this->cache);
    while(true){
        this->mutex.lock();
        painter.fillRect(0,0,this->width,this->height,QColor(255,255,255));
        GVectorIterator iterator(this->gGame->GetLayerManager()->GetLayers());
        iterator.ToBack();
        while(iterator.HasPrevious()){
            GLayer *lt=(GLayer*)iterator.Previous();
            lt->PaintNext(&painter);
            if(!lt->nextPaint) break;
        }
        this->mutex.unlock();
        QThread::msleep(25);
    }
}

void GScreenCache::SetGame(GGame *gGame){
    this->gGame=gGame;
}
