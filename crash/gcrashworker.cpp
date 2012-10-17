#include "gcrashworker.h"
#include "gcrashmanager.h"
#include "gcrash.h"

GCrashWorker::GCrashWorker(GCrashManager *manager,int id) : QThread()
{
    this->manager=manager;
    this->id=id;
    this->stoped=false;
    this->start();
}

GCrashWorker::~GCrashWorker(){
}

void GCrashWorker::run(){
    while(!this->stoped){
        this->Ergodic();
        QThread::msleep(2);
    }
}

void GCrashWorker::Ergodic(){
    for(int i=this->id*this->manager->GetMaxWork();i<(this->id+1)*this->manager->GetMaxWork() && i<this->manager->GetQueue()->Size();i++){
        this->IsCrash(this->manager->GetQueue()->At(i));
    }
}

void GCrashWorker::IsCrash(GCrashItem item){
    if(GCrash::IsCrash(item.left,item.right)){
        if(item.left->GetVisible() && !item.left->GetSuspend()) item.left->Crash(item.right);
        if(item.right->GetVisible() && !item.right->GetSuspend()) item.right->Crash(item.left);
    }
}

void GCrashWorker::Stop(){
    this->stoped=true;
    while(!this->isFinished()){
        QThread::msleep(10);
    }
    delete this;
}
