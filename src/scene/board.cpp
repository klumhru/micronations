#include "board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::SetSize(int width_, int height_)
{
    width = width_;
    height = height_;
}

void Board::Generate()
{
    Clear();

    for (int r = 0; r < height; r++)
    {
        for (int q = 0; q < width; q++)
        {
            auto tile = std::make_shared<Tile>();
            tile->SetPosition(q, r);
            tiles.push_back(tile);
        }
    }
}

void Board::Clear()
{
    tiles.clear();
}