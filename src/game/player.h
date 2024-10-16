#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player
{
public:
    Player(std::string name_ = "Anonymous", int score_ = 0) : name(name_), score(score_) {}
    ~Player();

private:
    std::string name;
    int score;
};

#endif // _PLAYER_H_