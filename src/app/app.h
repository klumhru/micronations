#ifndef APP_H_
#define APP_H_

#include <SDL3/SDL.h>

class App
{
public:
    App();
    ~App();

    int Run();

public:
    bool OnInit();

    void OnEvent(SDL_Event *evt);

    void OnLoop();

    void OnRender();

    void OnCleanup();

private:
    bool running;
    SDL_Renderer *renderer;
    SDL_Window *screen;
};

#endif // APP_H_