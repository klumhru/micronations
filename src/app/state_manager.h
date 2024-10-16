#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include <vector>

#include "state.h"

class StateManager
{
public:
    StateManager();
    ~StateManager();

    void PushState(State *state);
    void PopState();
    void ChangeState(State *state);
    void ClearStates();

    void OnEvent(SDL_Event *event);
    void OnLoop();
    void OnRender(SDL_Renderer *renderer);

    static bool Initialize();
    static bool Shutdown();

    static StateManager &GetInstance()
    {
        if (instance == nullptr)
        {
            instance = std::unique_ptr<StateManager>(new StateManager());
        }
        return *instance;
    }

private:
    std::vector<std::unique_ptr<State>> states;

    static std::unique_ptr<StateManager> instance;
};

#endif // _STATE_MANAGER_H_