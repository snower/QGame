#include "gcrashmanager.h"
#include <QList>

GCrashManager::GCrashManager()
{
    this->queue=NULL;
    this->maxWork=10;
    this->maxWorker=10;
}

void GCrashManager::RegisterCrash(int groupName, GMover *mover){
    if(!this->groups.contains(groupName)){
        GVector vt(false);
        this->groups[groupName]=vt;
    }
    this->groups[groupName].Append(mover);
    this->Ergodic();
    this->RefreshWorker();
}

void GCrashManager::UnRegisterCrash(int groupName,GMover *mover){
    if(this->groups.contains(groupName)){
        this->groups[groupName].Remove(mover);
    }
    this->Ergodic();
    this->RefreshWorker();
}

void GCrashManager::Ergodic(){
    GCrashQueue *q=new GCrashQueue();
    QList<int> list=this->groups.keys();
    for(int i=0,count=list.size();i<count;i++){
        for(int j=i+1;j<count;j++){
            this->ErgodicGroup(q,&this->groups[list[i]],&this->groups[list[j]]);
        }
    }

    this->mutex.lock();
    GCrashQueue *qt=this->queue;
    this->queue=q;
    if(qt!=NULL) delete qt;
    this->mutex.unlock();
}

void GCrashManager::ErgodicGroup(GCrashQueue *queue,GVector *o, GVector *u){
    for(int i=0,co=o->Size();i<co;i++){
        for(int j=0,cu=u->Size();j<cu;j++){
            this->IsCrash(queue,(GMover*)o->At(i),(GMover*)u->At(j));
        }
    }
}

void GCrashManager::IsCrash(GCrashQueue *queue,GMover *left, GMover *right){
    queue->Append(GCrashItem(left,right));
}

GCrashQueue* GCrashManager::GetQueue(){
    return this->queue;
}

void GCrashManager::RefreshWorker(){
    float w=(float)this->queue->Size()/(float)this->maxWork;
    if(w>(int)w) w++;
    while(this->worker.size()<(int)w){
        GCrashWorker *work=new GCrashWorker(this,this->worker.size());
        this->worker.push((int)work);
    }
    while(this->worker.size()>(int)w){
        if(!this->worker.empty()) {
            GCrashWorker *worker=NULL;
            worker=(GCrashWorker*)this->worker.pop();
            worker->Stop();
        }
    }
}

int GCrashManager::GetMaxWork(){
    return this->maxWork;
}
