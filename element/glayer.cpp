#include "glayer.h"
#include "../tools/gvectoriterator.h"
#include "gmover.h"

GLayer::GLayer(GGame* gGame) : GElement(gGame)
{
    this->nextPaint=true;
    this->nextAction=true;
}

GGame* GLayer::GetGame(){
    return this->gGame;
}

void GLayer::Remove(GElement *element){
    ((GMover*)element)->Stop();
    this->elements.Remove(element);
}

void GLayer::RemoveAll(){
    GVectorIterator iterator(&this->elements);
    while(iterator.HasNext()){
        ((GMover*)iterator.Next())->Stop();
    }
    this->elements.RemoveAll();
}
