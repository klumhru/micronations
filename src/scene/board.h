#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

#include "tile.h"

class Board
{
public:
    Board();
    ~Board();

    void SetSize(int width_, int height_);

    void Generate();

private:
    int width;
    int height;

    std::vector<std::shared_ptr<Tile>> tiles;

    void Clear();
};

#endif // _BOARD_H_