#ifndef _TILE_H_
#define _TILE_H_

#include <string>
#include "scene/node.h"
#include "assets/asset_manager.h"
#include "assets/texture.h"

class Tile : public Node
{
public:
    Tile() : Node()
    {
    }
    virtual ~Tile();

    void SetPosition(int q_, int r_)
    {
        q = q_;
        r = r_;
    }

    void SetTexture(const std::string &filename)
    {
        texture = AssetManager::GetInstance().Get<Texture>(filename);
    }

protected:
    void OnUpdate(float delta) override
    {
    }
    void OnRender(SDL_Renderer *renderer) override
    {
        if (texture)
        {
            texture->Render(q * 64, r * 64);
        }
    }

private:
    int q;
    int r;

    std::shared_ptr<Texture> texture;
};

#endif // _TILE_H_