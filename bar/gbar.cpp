#include "gbar.h"
#include "../ggame.h"
#include "../tools/gvectoriterator.h"

GBar::GBar(GGame *gGame,int x,int y,int width,int height,Position p) : GMover(this->layer=new GLayer(gGame))
{
    this->gGame=gGame;
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->pos=p;
    this->layer->Append(this);
}

void GBar::Triggered(){

}

GLayer* GBar::GetLayer(){
    return this->layer;
}

void GBar::SetLayer(GLayer *layer){
    if(layer==NULL) return;
    if(this->layer!=NULL) delete this->layer;
    this->layer=layer;
}

void GBar::AddAction(GBarAction *barAction){
    this->Append(barAction);
    this->UpdatePosition();
}

void GBar::UpdatePosition(){
    GVectorIterator iterator(this->GetElements());
    int c=0,s=0;
    switch(this->pos){
    case left:
        while(iterator.HasNext()){
            GBarAction *item=(GBarAction*)iterator.Next();
            c+=item->interval;
            item->SetMx(c);
            c+=item->GetWidth();
        }
        break;
    case center:
        c=0;
        while(iterator.HasNext()){
            GBarAction *item=(GBarAction*)iterator.Next();
            c+=item->GetWidth()+item->interval;
        }
        iterator.ToFront();
        s=(this->gGame->width-c)/2;
        c=0;
        while(iterator.HasNext()){
            GBarAction *item=(GBarAction*)iterator.Next();
            c+=item->interval;
            item->SetMx(s+c);
            c+=item->GetWidth();
        }
        break;
    case right:
        while(iterator.HasNext()){
            GBarAction *item=(GBarAction*)iterator.Next();
            c+=item->GetWidth()+item->interval;
            item->SetMx(this->gGame->width-c);
        }
        break;
    }
    if(c>this->gGame->width) this->width=c;
    else this->width=this->gGame->width;
}

void GBar::mousePressEvent(GMouseEvent *event){
    if(event->isAll){
        this->oldPoint=event->event->pos();
    }
}

void GBar::mouseMoveEvent(GMouseEvent *event){
    if(event->isAll){
        int s=event->event->x()-this->oldPoint.x();
        if(this->GetX()<0 && s>0) this->SetX(this->GetX()+s);
        if(this->GetX()+this->GetWidth()>this->gGame->width && s<0) this->SetX(this->GetX()+s);
        if(this->GetX()>0) this->SetX(0);
        if(this->GetX()+this->GetWidth()<this->gGame->width && this->GetWidth()>this->gGame->width) this->SetX(this->gGame->width-this->GetWidth());
        this->oldPoint=event->event->pos();
    }
}
