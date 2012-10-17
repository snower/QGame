#include "gcomponent.h"
#include "../tools/gvectoriterator.h"

GComponent::GComponent(GComponent *parent) : GElement(parent->GetGame())
{
    this->x=0;
    this->y=0;
    this->width=0;
    this->height=0;
    this->parent=parent;
}

bool GComponent::Control(){
    return false;
}

bool GComponent::ControlNext(){
    if(this->suspend) return true;
    bool isExit=false;
    isExit=(this->Control()) || isExit;
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        isExit=(((GComponent*)iterator.Next())->ControlNext()) || isExit;
    }
    return isExit;
}

int GComponent::GetX(){
    return this->x;
}

int GComponent::GetY(){
    return this->y;
}

int GComponent::GetWidth(){
    return this->width;
}

int GComponent::GetHeight(){
    return this->height;
}

void GComponent::SetX(int x){
    this->x=x;
}

void GComponent::SetY(int y){
    this->y=y;
}

void GComponent::SetWidth(int w){
    this->width=w;
}

void GComponent::SetHeight(int h){
    this->height=h;
}

void GComponent::mousePressNext(GMouseEvent *event){
    if(!this->action) return;
    if(!this->isContain(event)) return;
    if(!this->elements.Empty()) this->mousePressEvent(event);
    else event->isAll=true;

    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GComponent*)iterator.Next())->mousePressNext(event);
    }
    this->mousePressEvent(event);
}

void GComponent::mouseReleaseNext(GMouseEvent *event){
    if(!this->action) return;
    if(!this->isContain(event)) return;
    if(!this->elements.Empty()) this->mouseReleaseEvent(event);
    else event->isAll=true;

    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GComponent*)iterator.Next())->mouseReleaseNext(event);
    }
    this->mouseReleaseEvent(event);
}

void GComponent::mouseMoveNext(GMouseEvent *event){
    if(!this->action) return;
    if(!this->isContain(event)) return;
    if(!this->elements.Empty()) this->mouseMoveEvent(event);
    else event->isAll=true;

    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GComponent*)iterator.Next())->mouseMoveNext(event);
    }
    this->mouseMoveEvent(event);
}

void GComponent::mouseDoubleClickNext(GMouseEvent *event){
    if(!this->action) return;
    if(!this->isContain(event)) return;
    if(!this->elements.Empty()) this->mouseDoubleClickEvent(event);
    else event->isAll=true;

    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GComponent*)iterator.Next())->mouseDoubleClickNext(event);
    }

    this->mouseDoubleClickEvent(event);
}

bool GComponent::isContain(GMouseEvent *event){
    if(event->event->x()>=this->x && event->event->x()<=(this->x+this->width) && event->event->y()>=this->y && event->event->y()<=(this->y+this->height)) return true;
    return false;
}
