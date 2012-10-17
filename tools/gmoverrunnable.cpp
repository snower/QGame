#include "gmoverrunnable.h"
#include "../element/gmover.h"

GMoverRunnable::GMoverRunnable(GMover *parent,bool autoRun) :
    QThread()
{
    this->parent=parent;
    if(autoRun) this->start();
}

void GMoverRunnable::run(){
    this->parent->run();
}

void GMoverRunnable::Msleep(int m){
    QThread::msleep(m);
}

void GMoverRunnable::Sleep(int s){
    QThread::sleep(s);
}
