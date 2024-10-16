#include "app.h"
#include "state_manager.h"

#include "assets/asset_manager.h"

void App::OnCleanup()
{
    AssetManager::Shutdown();
    StateManager::Shutdown();

    SDL_DestroyWindow(screen);
    screen = nullptr;
    SDL_Quit();
}