#include "app.h"
#include "state_manager.h"

void App::OnLoop()
{
    StateManager::GetInstance().OnLoop();
}
