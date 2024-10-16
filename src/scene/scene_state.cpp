#include "scene_state.h"

SceneState::SceneState()
{
    running = true;
    scene = std::make_shared<Scene>();
}

SceneState::~SceneState()
{
    running = false;
}

void SceneState::Enter()
{
    Build();
}

void SceneState::OnEvent(SDL_Event *event)
{
}

void SceneState::OnLoop()
{
    scene->Update(0.16f);
}

void SceneState::OnRender(SDL_Renderer *renderer)
{
    scene->Render(renderer);
}

void SceneState::Exit()
{
    Destroy();
}
