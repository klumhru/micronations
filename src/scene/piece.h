#ifndef _PIECE_H_
#define _PIECE_H_

#include "sprite.h"
#include "game/player.h"

class Piece
{
public:
    Piece();
    ~Piece();

private:
    std::shared_ptr<Player> player;
};

#endif // _PIECE_H_