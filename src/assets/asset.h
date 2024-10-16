#ifndef _ASSET_H_
#define _ASSET_H_

#include <string>

/// @brief Base class for all assets
class Asset
{
public:
    /// @brief Constructor
    Asset() {}

    /// @brief Destructor
    virtual ~Asset() {}

    /// @brief Get the filename of the asset
    /// @return The filename of the asset
    const std::string &GetFilename() const { return filename; }

    enum class Type
    {
        Asset_Texture,
        Asset_Font,
        Asset_Sound,
        Asset_Text,
    };

    /// @brief Get the type of the asset
    /// @return The type of the asset
    Asset::Type GetType() const { return type; }

    /// @brief Load the asset
    /// @param filename The filename of the asset
    /// @return True if the asset was loaded successfully, false otherwise
    virtual bool Load(const std::string &filename) = 0;
    virtual bool Clear() = 0;

protected:
    /// @brief The filename of the asset
    std::string filename;

    /// @brief The type of the asset
    Type type;
};

#endif // _ASSET_H_