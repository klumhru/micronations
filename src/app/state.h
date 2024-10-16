#ifndef _STATE_H_
#define _STATE_H_

#include <SDL3/SDL.h>

class State
{
public:
    State() {}
    virtual ~State() {}

public:
    virtual void Enter() = 0;
    virtual void OnEvent(SDL_Event *event) = 0;
    virtual void OnLoop() = 0;
    virtual void OnRender(SDL_Renderer *renderer) = 0;
    virtual void Exit() = 0;
};

#endif // _STATE_H_