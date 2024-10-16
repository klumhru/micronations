#ifndef _SCENE_STATE_H_
#define _SCENE_STATE_H_

#include <unordered_map>

#include "app/state.h"
#include "scene/tile.h"
#include "scene/scene.h"

class SceneState : public State
{
public:
    SceneState();
    ~SceneState();

    void Enter() override;
    void OnEvent(SDL_Event *event) override;
    void OnLoop() override;
    void OnRender(SDL_Renderer *renderer) override;
    void Exit() override;

private:
    bool running;
    int width;
    int height;

private:
    void Build();
    void Destroy();

    static std::string hexKey(int q, int r)
    {
        return std::to_string(q) + "," + std::to_string(r);
    }

    void CreateTile(int q, int r, const std::string &filename);
    void DestroyTile(int q, int r);

    std::unordered_map<std::string, std::shared_ptr<Tile>> tiles;

    // Nodes must be shared pointers so they can be shared as parents using weak pointers
    std::shared_ptr<Scene> scene;
};

#endif // _SCENE_STATE_H_