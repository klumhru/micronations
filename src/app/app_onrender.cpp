#include "app.h"
#include "state_manager.h"

void App::OnRender()
{
    SDL_RenderClear(renderer);
    StateManager::GetInstance().OnRender(this->renderer);
    SDL_RenderPresent(renderer);
}
