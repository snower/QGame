#include "gelement.h"
#include "../tools/gvectoriterator.h"

GElement::GElement(GGame* gGame) : QObject()
{
    this->gGame=gGame;
    this->visible=true;
    this->suspend=false;
    this->action=true;
}

void GElement::Paint(QPainter *painter){


}

void GElement::PaintNext(QPainter *painter){
    if(!this->visible) return;
    this->Paint(painter);
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->PaintNext(painter);
    }
}

GVector* GElement::GetElements(){
    return &this->elements;
}

void GElement::SetGame(GGame *gGame){
    this->gGame=gGame;
}


void GElement::Append(GElement *element){
    this->elements.Append(element);
}

void GElement::Insert(GElement *element, int index){
    this->elements.Insert(element,index);
}

void GElement::Remove(GElement *element){
    this->elements.Remove(element);
}

void GElement::RemoveAll(){
    this->elements.RemoveAll();
}

GElement* GElement::At(int index){
    return (GElement*)this->elements.At(index);
}

GGame* GElement::GetGame(){
    return this->gGame;
}

void GElement::mousePressEvent(GMouseEvent *event){

}

void GElement::mouseReleaseEvent(GMouseEvent *event){

}

void GElement::mouseMoveEvent(GMouseEvent *event){

}

void GElement::mouseDoubleClickEvent(GMouseEvent *event){
}

void GElement::mousePressNext(GMouseEvent *event){
    if(!this->action) return;
    this->mousePressEvent(event);
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->mousePressNext(event);
    }
    this->mousePressEvent(event);
}

void GElement::mouseReleaseNext(GMouseEvent *event){
    if(!this->action) return;
    this->mouseReleaseEvent(event);
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->mouseReleaseNext(event);
    }
    this->mouseReleaseEvent(event);
}

void GElement::mouseMoveNext(GMouseEvent *event){
    if(!this->action) return;
    this->mouseMoveEvent(event);
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->mouseMoveNext(event);
    }
    this->mouseMoveEvent(event);
}

void GElement::mouseDoubleClickNext(GMouseEvent *event){
    if(!this->action) return;
    this->mouseDoubleClickEvent(event);
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->mouseDoubleClickNext(event);
    }
    this->mouseDoubleClickEvent(event);
}

void GElement::Show(){
    this->visible=true;
    this->suspend=false;
    this->action=true;
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->Show();
    }
}

void GElement::Hide(){
    this->visible=false;
    this->suspend=true;
    this->action=false;
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->Hide();
    }
}

void GElement::Suspend(){
    this->suspend=true;
    this->action=false;
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->Suspend();
    }
}

void GElement::Proceed(){
    this->suspend=false;
    this->action=true;
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GElement*)iterator.Next())->Proceed();
    }
}

bool GElement::GetVisible(){
    return this->visible;
}

bool GElement::GetSuspend(){
    return this->suspend;
}

bool GElement::GetAction(){
    return this->action;
}

void GElement::SetVisible(bool is){
    this->visible=is;
}

void GElement::SetSuspend(bool is){
    this->suspend=is;
}

void GElement::SetAction(bool is){
    this->action=is;
}
