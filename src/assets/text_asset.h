#ifndef _TEXT_ASSET_H_
#define _TEXT_ASSET_H_

#include <string>
#include <SDL3/SDL.h>
#include "assets/asset.h"

class TextAsset : public Asset
{
public:
    TextAsset();
    ~TextAsset();

    bool Load(SDL_Renderer *_, const std::string &filename) { return Load(filename); }
    bool Load(const std::string &filename) override;
    bool Clear() override;

    const std::string &GetText() const { return text; }

private:
    std::string text;
};

#endif // _TEXT_ASSET_H_