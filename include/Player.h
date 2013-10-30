#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

class Player
{
    public:
        Player();

        // constructeur pour "charger" un joueur existant (utilisé par Engine)
        Player(string name, int money, vector<int> highscore);
        virtual ~Player();

        // GETTERS
        string getName();
        int getMoney();
        vector<int> getHighscore();

        // SETTERS
        void setMoney(int money);
        void setHighscore(vector<int> highscore);
        void setName(string name);

    private:
        string name_; // son nom
        int money_; // argent récolté dans toutes ses parties
        vector<int> highscore_; // liste des meilleurs scores
};

#endif // PLAYER_H
