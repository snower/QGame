#include "gbaraction.h"
#include "gbar.h"

GBarAction::GBarAction(GBar *bar,int x,int y,int width,int height,int interval) : GItem(bar)
{
    this->bar=bar;
    this->mx=x;
    this->my=y;
    this->width=width;
    this->height=height;
    this->interval=interval;
    this->Init();
}

GBarAction::GBarAction(GBar *bar,int x,int y,int width,int height,int interval,QString string) : GItem(bar)
{
    this->bar=bar;
    this->mx=x;
    this->my=y;
    this->width=width;
    this->height=height;
    this->interval=interval;
    this->string=string;
    this->Init();
}

void GBarAction::Init(){
    this->bgColor=QColor(255,255,0,100);
    this->font=QFont("Times",12,QFont::Bold);
    this->selected=false;
    this->isSelect=true;
    this->xRadius=6;
    this->yRadius=6;
}

GBar* GBarAction::GetBar(){
    return this->bar;
}

void GBarAction::Triggered(){

}

void GBarAction::Paint(QPainter *painter){
    this->PaintBackGround(painter);
    this->PaintForeGround(painter);
    if(this->isSelect && this->selected) this->PaintSelect(painter);
}

void GBarAction::PaintForeGround(QPainter *painter){
    QFont ft=painter->font();
    QPen pt=painter->pen();
    QPen pen(this->color);
    painter->setFont(this->font);
    painter->setPen(pen);
    painter->drawText(this->x+this->mx,this->y+this->my,this->width,this->height,Qt::AlignHCenter | Qt::AlignVCenter,this->string);
    painter->setFont(ft);
    painter->setPen(pt);
}

void GBarAction::PaintBackGround(QPainter *painter){
    QPen ptbg=painter->pen();
    QBrush btbg=painter->brush();
    painter->setPen(QPen(this->bgColor));
    painter->setBrush(QBrush(this->bgColor));
    painter->drawRoundedRect(this->x+this->mx,this->y+this->my,this->width,this->height,this->xRadius,this->yRadius);
    painter->setBrush(btbg);
    painter->setPen(ptbg);
}

void GBarAction::PaintSelect(QPainter *painter){
    QColor ct(255,255,255,100);
    QPen ptbg=painter->pen();
    QBrush btbg=painter->brush();
    painter->setPen(QPen(ct));
    painter->setBrush(QBrush(ct));
    painter->drawRoundedRect(this->x+this->mx,this->y+this->my,this->width,this->height,6,6);
    painter->setBrush(btbg);
    painter->setPen(ptbg);
}

void GBarAction::mousePressEvent(GMouseEvent *event){
    this->pressPoint=event->event->pos();
    this->selected=true;
}

void GBarAction::mouseReleaseEvent(GMouseEvent *event){
    if(event->event->x()-this->pressPoint.x()<15 && event->event->y()-this->pressPoint.y()<15){
        this->Triggered();
    }
    this->selected=false;
}

void GBarAction::mouseMoveEvent(GMouseEvent *event){
    this->selected=false;
}

void GBarAction::SetString(QString string){
    this->string=string;
}

void GBarAction::UpdateString(QString string){
    this->string=string;
}

