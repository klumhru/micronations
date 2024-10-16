#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include "app/state.h"

class GameState : public State
{
public:
    GameState();
    ~GameState();

    void Enter() override;
    void OnEvent(SDL_Event *event) override;
    void OnLoop() override;
    void OnRender(SDL_Renderer *renderer) override;
    void Exit() override;

private:
    bool running;
};

#endif // _GAME_STATE_H_