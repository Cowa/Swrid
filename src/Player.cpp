#include "../include/Player.h"

Player::Player()
{
    name_ = "Lambda";
    money_ = 0;
}

Player::Player(string name, int money, vector<int> highscore)
{
    name_ = name;
    money_ = money;
    highscore_ = highscore;
}

Player::~Player()
{
    //dtor
}

/**********
* GETTERS *
**********/
string Player::getName()
{
    return name_;
}

int Player::getMoney()
{
    return money_;
}

vector<int> Player::getHighscore()
{
    return highscore_;
}

/**********
* SETTERS *
**********/
void Player::setMoney(int money)
{
    money_ = money;
}

void Player::setHighscore(vector<int> highscore)
{
    highscore_ = highscore;
}
void Player::setName(string name)
{
    name_ = name;
}
