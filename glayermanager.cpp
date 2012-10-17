#include "glayermanager.h"

GLayerManager::GLayerManager()
{
}

void GLayerManager::SetGame(GGame *gGame){
    this->gGame=gGame;
}

void GLayerManager::AddLayer(GLayer *layer){
    this->layers.Append(layer);
}

void GLayerManager::InsertLayer(GLayer *layer, int index){
    this->layers.Insert(layer,index);
}

GLayer* GLayerManager::GetLayer(int index){
    return (GLayer*)this->layers.At(index);
}

void GLayerManager::RemoveLayer(void *data){
    this->layers.Remove(data);
}

void GLayerManager::RemoveAll(){
    this->layers.RemoveAll();
}

int GLayerManager::GetCount(){
    return this->layers.Size();
}

GVector* GLayerManager::GetLayers(){
    return &this->layers;
}
