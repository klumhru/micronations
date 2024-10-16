#include "game_state.h"

#include "app/state_manager.h"
#include "scene/scene_state.h"

GameState::GameState()
{
    running = true;
}

GameState::~GameState()
{
}

void GameState::Enter()
{
    StateManager::GetInstance().PushState(new SceneState());
}

void GameState::OnEvent(SDL_Event *event)
{
}

void GameState::OnLoop()
{
}

void GameState::OnRender(SDL_Renderer *renderer)
{
}

void GameState::Exit()
{
}