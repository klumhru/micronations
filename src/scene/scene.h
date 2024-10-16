#ifndef _SCENE_H_
#define _SCENE_H_

#include "scene/node.h"

class Scene : public Node
{
public:
protected:
    void OnUpdate(float delta) override;
    void OnRender(SDL_Renderer *renderer) override {}
};

#endif // _SCENE_H_