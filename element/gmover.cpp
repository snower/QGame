#include "gmover.h"
#include "../ggame.h"
#include "../tools/gvectoriterator.h"

GMover::GMover(GLayer *parent):GComponent((GComponent*)parent)
{
    this->crashGroupName=-1;
    this->speed=20;
    this->isCrash=false;
    this->isStop=false;
    this->runnable=new GMoverRunnable(this);
}

GMover::~GMover(){
    delete this->runnable;
}

void GMover::run(){
    while(this->ControlNext() && !this->isStop){
        this->runnable->Msleep(this->speed);
    }
}

void GMover::RegisterCrash(int groupName){
    if(this->crashGroupName==groupName && this->isCrash) return;
    this->crashGroupName=groupName;
    this->gGame->GetCrashManager()->RegisterCrash(groupName,this);
    this->isCrash=true;
}

void GMover::UnRegisterCrash(){
    if(this->crashGroupName<0 || !this->isCrash) return;
    this->gGame->GetCrashManager()->UnRegisterCrash(this->crashGroupName,this);
    this->isCrash=false;
}

void GMover::Crash(GMover *mover){

}

void GMover::Start(){
    this->runnable->start();
}

void GMover::Stop(){
    this->isStop=true;
    while(!this->runnable->isFinished()){
        this->runnable->Msleep(10);
    }
}
