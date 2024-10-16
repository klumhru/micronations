#include "assets/texture.h"
#include "logging/easylogging++.h"
#include <SDL3_image/SDL_image.h>

Texture::Texture()
{
    type = Asset::Type::Asset_Texture;
    texture = nullptr;
    width = 0;
    height = 0;
}

Texture::~Texture()
{
    Free();
}

bool Texture::Load(const std::string &filename)
{
    if (renderer == nullptr)
    {
        LOG(FATAL) << "Renderer is null";
        return false;
    }
    if ((texture = IMG_LoadTexture(this->renderer, filename.c_str())) == nullptr)
    {
        LOG(ERROR) << "Failed to load texture from " << filename << ": " << SDL_GetError();
        return false;
    }

    if (!SDL_GetTextureSize(texture, &width, &height))
    {
        LOG(ERROR) << "Failed to get texture size " << filename << ": " << SDL_GetError();
        SDL_DestroyTexture(texture);
        return false;
    }
    return true;
}

bool Texture::Load(SDL_Renderer *renderer, const std::string &filename)
{
    Free();
    if (renderer == nullptr)
    {
        LOG(FATAL) << "Renderer is null";
        return false;
    }

    this->renderer = renderer;

    return Load(filename);
}

bool Texture::Clear()
{
    Free();
    return true;
}

void Texture::Render(float x, float y)
{
    Render(x, y, width, height);
}

void Texture::Render(float x, float y, float w, float h)
{
    if (texture == nullptr)
    {
        LOG(ERROR) << "Texture is null";
        return;
    }

    SDL_FRect dstRect = {x, y, w, h};

    SDL_RenderTexture(renderer, texture, nullptr, &dstRect);
}

void Texture::Free()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    this->renderer = nullptr;
}