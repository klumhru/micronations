#ifndef _ASSET_MANAGER_H_
#define _ASSET_MANAGER_H_

#include <string>
#include <unordered_map>
#include <memory>
#include <SDL3/SDL.h>
#include "asset.h"

class AssetManager
{
public:
    void SetAssetPath(const std::string &path) { assetPath = path; }
    void SetRenderer(SDL_Renderer *renderer) { this->renderer = renderer; }

    template <typename T>
    std::shared_ptr<T> Get(const std::string &filename)
    {
        auto it = assets.find(filename);
        if (it != assets.end())
        {
            return std::static_pointer_cast<T>(it->second);
        }
        auto asset = std::make_shared<T>();
        if (asset->Load(this->renderer, assetPath + "/" + filename))
        {
            assets.emplace(filename, asset);
            return asset;
        }
        return nullptr;
    }

    static bool Initialize(const std::string &assetPath, SDL_Renderer *renderer);
    static bool Shutdown();
    static AssetManager &GetInstance() { return instance; }

private:
    std::string assetPath;
    std::unordered_map<std::string, std::shared_ptr<Asset>> assets;
    SDL_Renderer *renderer;

    AssetManager() : AssetManager("assets") {}
    explicit AssetManager(const std::string &assetPath) : assetPath(assetPath), renderer(nullptr) {};
    ~AssetManager();
    static AssetManager instance;
};

#endif // _ASSET_MANAGER_H_