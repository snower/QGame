#include "ggame.h"

GGame::GGame()
{
    this->width=0;
    this->height=0;
    this->menu=NULL;
    this->Init();
}

GGame::~GGame(){
    if(this->gScreen!=NULL){
        delete this->gScreen;
    }
}

void GGame::Init(){
    this->gScreen=NULL;
    this->gScreenCache=NULL;
    this->gLayerManager=NULL;
    this->gCrashManager=NULL;
    this->gMouseManager=NULL;
    this->gCacheManager=NULL;

    this->menu=NULL;
    this->toolsBar=NULL;
    this->statusBar=NULL;

    this->SetScreen(new GScreen());
    this->SetScreenCache(new GScreenCache(this->gScreen->width(),this->gScreen->height()));
    this->SetLayerManager(new GLayerManager());
    this->SetCrashManager(new GCrashManager());
    this->SetMouseManager(new GMouseEventManager(this));
    this->SetCacheManager(new GCacheManager(this));
}

void GGame::SetScreen(GScreen *gScreen){
    if(gScreen==NULL) return;
    if(this->gScreen!=NULL){
        delete this->gScreen;
    }
    this->gScreen=gScreen;
    this->gScreen->SetGame(this);
    this->gScreen->SetOrientation(GScreen::ScreenOrientationLockLandscape);
    this->gScreen->ShowExpanded();
    this->width=this->gScreen->width();
    this->height=this->gScreen->height();
}

void GGame::SetScreenCache(GScreenCache *gScreenCache){
    if(gScreenCache==NULL) return;
    if(this->gScreenCache!=NULL){
        delete this->gScreenCache;
    }
    this->gScreenCache=gScreenCache;
    this->gScreenCache->SetGame(this);
    this->gScreenCache->start();
}

void GGame::SetLayerManager(GLayerManager *gLayerManager){
    if(gLayerManager==NULL) return;
    if(this->gLayerManager!=NULL){
        delete this->gLayerManager;
    }
    this->gLayerManager=gLayerManager;
    this->gLayerManager->SetGame(this);
    this->gLayerManager->AddLayer(new GLayer(this));
    this->gLayerManager->AddLayer(new GLayer(this));
    this->gLayerManager->AddLayer(new GLayer(this));
}

void GGame::SetCrashManager(GCrashManager *gCrashManager){
    if(gCrashManager==NULL) return;
    if(this->gCrashManager!=NULL){
        delete this->gCrashManager;
    }
    this->gCrashManager=gCrashManager;
}

void GGame::SetMouseManager(GMouseEventManager *gMouseManager){
    if(gMouseManager==NULL) return;
    if(this->gMouseManager!=NULL){
        delete this->gMouseManager;
    }
    this->gMouseManager=gMouseManager;
    this->gMouseManager->start();
}

void GGame::SetCacheManager(GCacheManager *gCacheManager){
    if(gCacheManager==NULL) return;
    if(this->gCacheManager!=NULL){
        delete this->gCacheManager;
    }
    this->gCacheManager=gCacheManager;
}

GScreen* GGame::GetScreen(){
    return this->gScreen;
}

GScreenCache* GGame::GetScreenCache(){
    return this->gScreenCache;
}

GLayerManager* GGame::GetLayerManager(){
    return this->gLayerManager;
}

GCrashManager* GGame::GetCrashManager(){
    return this->gCrashManager;
}

GMouseEventManager* GGame::GetMouseManager(){
    return this->gMouseManager;
}

GCacheManager* GGame::GetCacheManager(){
    return this->gCacheManager;
}

void GGame::SetMenu(GMenu *menu){
    if(this->menu!=NULL) this->gLayerManager->RemoveLayer(this->menu->GetLayer());
    this->gLayerManager->InsertLayer(menu->GetLayer(),1);
    this->menu=menu;
}

GMenu* GGame::GetMenu(){
    return this->menu;
}

void GGame::SetToolsBar(GToolsBar *toolsBar){
    if(this->toolsBar!=NULL) this->gLayerManager->RemoveLayer(this->toolsBar->GetLayer());
    this->gLayerManager->InsertLayer(toolsBar->GetLayer(),0);
    this->toolsBar=toolsBar;
}

GToolsBar* GGame::GetToolsBar(){
    return this->toolsBar;
}

void GGame::SetStatusBar(GStatusBar *statusBar){
    if(this->statusBar!=NULL) this->gLayerManager->RemoveLayer(this->statusBar->GetLayer());
    this->gLayerManager->InsertLayer(statusBar->GetLayer(),2);
    this->statusBar=statusBar;
}

GStatusBar* GGame::GetStatusBar(){
    return this->statusBar;
}
