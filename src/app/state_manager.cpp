#include "state_manager.h"

std::unique_ptr<StateManager> StateManager::instance = nullptr;

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
}

bool StateManager::Initialize()
{
    GetInstance();
    return true;
}

bool StateManager::Shutdown()
{
    instance.reset();
    return true;
}

void StateManager::PushState(State *state)
{
    states.push_back(std::unique_ptr<State>(state));
    states.back()->Enter();
}

void StateManager::PopState()
{
    // Call Exit on the top state
    states.back()->Exit();

    states.pop_back();
}

void StateManager::ChangeState(State *state)
{
    ClearStates();
    PushState(state);
}

void StateManager::ClearStates()
{
    for (auto &state : states)
    {
        state->Exit();
    }
    states.clear();
}

void StateManager::OnEvent(SDL_Event *event)
{
    for (auto &state : states)
    {
        state->OnEvent(event);
    }
}

void StateManager::OnLoop()
{
    for (auto &state : states)
    {
        state->OnLoop();
    }
}

void StateManager::OnRender(SDL_Renderer *renderer)
{
    for (auto &state : states)
    {
        state->OnRender(renderer);
    }
}
