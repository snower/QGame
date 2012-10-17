#include "gitem.h"
#include "../tools/gvectoriterator.h"

GItem::GItem(GMover *parent) : GComponent(parent){
    this->mx=0;
    this->my=0;
}

GItem::GItem(GItem *parent) : GComponent(parent){
    this->mx=0;
    this->my=0;
}

void GItem::PaintNext(QPainter *painter){
    this->x=this->parent->GetX();
    this->y=this->parent->GetY();
    if(!this->visible) return;
    this->Paint(painter);
    GVectorIterator iterator(&this->elements);
    iterator.ToBack();
    while(iterator.HasPrevious()){
        ((GItem*)iterator.Previous())->PaintNext(painter);
    }
}

bool GItem::isContain(GMouseEvent *event){
    if(event->event->x()>=(this->x+this->mx) && event->event->x()<=(this->x+this->mx+this->width) && event->event->y()>=(this->y+this->my) && event->event->y()<=(this->y+this->my+this->height)) return true;
    return false;
}

int GItem::GetMx(){
    return this->mx;
}

int GItem::GetMy(){
    return this->my;
}

void GItem::SetMx(int x){
    this->mx=x;
}

void GItem::SetMy(int y){
    this->my=y;
}
