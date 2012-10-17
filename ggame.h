#ifndef GGAME_H
#define GGAME_H

#include "gscreen.h"
#include "crash/gcrashmanager.h"
#include "mouse/gmouseeventmanager.h"
#include "cache/gcachemanager.h"
#include "bar/gmenu.h"
#include "bar/gtoolsbar.h"
#include "bar/gstatusbar.h"

class GGame
{
public:
    GGame();
    ~GGame();

    void SetScreen(GScreen *gScreen=NULL);
    void SetScreenCache(GScreenCache *gScreenCache=NULL);
    void SetLayerManager(GLayerManager *gLayerManager=NULL);
    void SetCrashManager(GCrashManager *gCrashManager=NULL);
    void SetMouseManager(GMouseEventManager *gMouseManager=NULL);
    void SetCacheManager(GCacheManager *gCacheManager=NULL);
    GScreen* GetScreen();
    GScreenCache* GetScreenCache();
    GLayerManager* GetLayerManager();
    GCrashManager* GetCrashManager();
    GMouseEventManager* GetMouseManager();
    GCacheManager* GetCacheManager();

    void SetMenu(GMenu *menu);
    GMenu* GetMenu();
    void SetToolsBar(GToolsBar *toolsBar);
    GToolsBar* GetToolsBar();
    void SetStatusBar(GStatusBar *statusBar);
    GStatusBar* GetStatusBar();

protected:
    void Init();

public:
    int width;
    int height;

protected:
    GScreen *gScreen;
    GScreenCache *gScreenCache;
    GLayerManager *gLayerManager;
    GCrashManager *gCrashManager;
    GMouseEventManager *gMouseManager;
    GCacheManager* gCacheManager;
    GMenu *menu;
    GToolsBar *toolsBar;
    GStatusBar* statusBar;
};

#endif // GGAME_H
