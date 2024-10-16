#include "app.h"
#include "state_manager.h"

void App::OnEvent(SDL_Event *evt)
{
    if (evt->type == SDL_EVENT_QUIT)
    {
        running = false;
    }
    StateManager::GetInstance().OnEvent(evt);
}
