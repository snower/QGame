#ifndef GLAYERMANAGER_H
#define GLAYERMANAGER_H

#include "tools/gvector.h"
#include "element/glayer.h"

class GGame;

class GLayerManager
{
public:
    GLayerManager();

    void SetGame(GGame *gGame=NULL);
    void AddLayer(GLayer *layer);
    void InsertLayer(GLayer *layer,int index);
    GLayer* GetLayer(int index);
    void RemoveLayer(void *data);
    void RemoveAll();
    int GetCount();
    GVector* GetLayers();

public:

protected:
    GGame *gGame;
    GVector layers;
};

#endif // GLAYERMANAGER_H
