#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <SDL3/SDL.h>
#include <string>

#include "asset.h"

/// @brief Texture class
/// @details This class is used to load and render textures
class Texture : public Asset
{
public:
    Texture();
    ~Texture();

    bool Load(const std::string &filename);
    bool Load(SDL_Renderer *renderer, const std::string &filename);
    bool Clear();
    void Render(float x, float y);

    int GetWidth() { return width; }
    int GetHeight() { return height; }

private:
    void Render(float x, float y, float w, float h);

private:
    void Free();
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    float width;
    float height;
};

#endif // _TEXTURE_H_