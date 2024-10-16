#include "app.h"
#include "state_manager.h"
#include "logging/easylogging++.h"
#include "assets/asset_manager.h"
#include "game/game_state.h"

bool App::OnInit()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return false;
    }

    if ((screen = SDL_CreateWindow(
             "Micro Missions",
             720, 1280,
             SDL_WINDOW_OPENGL)) == NULL)
    {
        LOG(FATAL) << "Failed to create window";
        return false;
    }

    if ((renderer = SDL_CreateRenderer(screen, NULL)) == NULL)
    {
        LOG(FATAL) << "Failed to get renderer";
        return false;
    }

    if (!AssetManager::Initialize("../assets", renderer))
    {
        LOG(FATAL) << "Failed to initialize asset manager";
        return false;
    }

    if (!StateManager::Initialize())
    {
        LOG(FATAL) << "Failed to initialize state manager";
        return false;
    }
    StateManager::GetInstance().PushState(new GameState());

    return true;
}