#include "asset_manager.h"

AssetManager AssetManager::instance = AssetManager();

AssetManager::~AssetManager()
{
}

bool AssetManager::Initialize(const std::string &assetPath, SDL_Renderer *renderer)
{
    instance.assetPath = assetPath;
    instance.renderer = renderer;
    return true;
}

bool AssetManager::Shutdown()
{
    // Clear all assets
    for (auto &asset : instance.assets)
    {
        asset.second->Clear();
    }
    instance.assets.clear();
    return true;
}