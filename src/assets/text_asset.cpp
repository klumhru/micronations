#include "text_asset.h"

#include <fstream>

#include "logging/easylogging++.h"

TextAsset::TextAsset()
{
    type = Asset::Type::Asset_Text;
}

TextAsset::~TextAsset()
{
}

bool TextAsset::Load(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        LOG(ERROR) << "Failed to open file: " << filename;
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        text += line + "\n";
    }

    file.close();
    return true;
}

bool TextAsset::Clear()
{
    text.clear();
    return true;
}