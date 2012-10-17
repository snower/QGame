#include "gmouseevent.h"

GMouseEvent::GMouseEvent()
{
    this->event=NULL;
    this->isAll=false;
    this->type=GMouseEvent::Press;
}

GMouseEvent::GMouseEvent(QMouseEvent *event){
    this->event=new QMouseEvent(event->type(),event->pos(),event->globalPos(),event->button(),event->buttons(),event->modifiers());
    this->isAll=false;
    this->type=GMouseEvent::Press;
}

GMouseEvent::~GMouseEvent(){
    //if(this->event!=NULL) delete this->event;
}
