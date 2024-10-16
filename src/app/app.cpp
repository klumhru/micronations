#include "app.h"

#include "absl/log/log.h"
#include "absl/log/log_sink_registry.h"
#include "data/id.pb.h"

App::App(): renderer(nullptr), screen(nullptr) {
    running = true;
    data::Id id;
    id.set_id("foo");

    

    LOG(INFO) << "App created, id: " << id.id();
}

App::~App() = default;

int App::Run()
{
    if (!OnInit())
    {
        running = false;
        // Don't return here, as we want to clean up resources with OnCleanup
    }

    SDL_Event evt;

    while (running)
    {
        while (SDL_PollEvent(&evt))
        {
            OnEvent(&evt);
        }

        OnLoop();
        OnRender();
        SDL_Delay(30);
    }

    OnCleanup();
    return 0;
}
