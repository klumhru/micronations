#include "scene_state.h"

#include "rapidjson/document.h"
#include "logging/easylogging++.h"
#include "assets/asset_manager.h"
#include "assets/text_asset.h"

void SceneState::Build()
{
    // Create the scene
    rapidjson::Document map;
    // For now we just hardcode loading the map in assets/scenes/default.json
    // In the future we will load this dynamically
    std::string filename = "scenes/default.json";
    auto text = AssetManager::GetInstance().Get<TextAsset>(filename);
    if (text == nullptr)
    {
        LOG(ERROR) << "Failed to load map: " << filename;
        return;
    }
    auto json = text->GetText();
    if (text)
    {
        map.Parse(text->GetText().c_str());
        if (map.HasParseError())
        {
            LOG(ERROR) << "Failed to parse map: " << filename << ": " << map.GetParseError();
            // Log error
            return;
        }
        if (map.IsObject())
        {
            if (map.HasMember("width") && map["width"].IsInt())
            {
                width = map["width"].GetInt();
            }
            if (map.HasMember("height") && map["height"].IsInt())
            {
                height = map["height"].GetInt();
            }
            if (map.HasMember("tiles") && map["tiles"].IsArray())
            {
                auto q = 0, r = 0;
                for (auto &tile : map["tiles"].GetArray())
                {
                    if (tile.IsObject())
                    {
                        if (q % width == 0)
                        {
                            q = 0;
                            r++;
                        }
                        if (tile.HasMember("sprite") && tile["sprite"].IsString())
                        {
                            CreateTile(q, r, tile["sprite"].GetString());
                        }
                        q++;
                    }
                }
            }
        }
    }
}

void SceneState::Destroy()
{
    // Destroy the scene
    for (auto &tile : tiles)
    {
        scene->RemoveChild(tile.second);
    }
    tiles.clear();
}

void SceneState::CreateTile(int q, int r, const std::string &filename)
{
    std::string key = hexKey(q, r);
    if (tiles.find(key) == tiles.end())
    {
        std::shared_ptr<Tile> tile = std::make_shared<Tile>();
        tile->SetPosition(q, r);
        tile->SetTexture("textures/" + filename);
        scene->AddChild(tile);
        tiles.emplace(key, tile);
        LOG(DEBUG) << "Created tile at " << q << "," << r << " with texture " << filename;
    }
}