#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "assets/texture.h"

class Sprite
{
public:
    Sprite(std::shared_ptr<Texture> &texture_) : texture(texture_) {};
    ~Sprite();

private:
    // Transform
    float x;
    float y;
    float w;
    float s;

    // Texture
    std::shared_ptr<Texture> texture;
};

#endif // _SPRITE_H_