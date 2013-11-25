#ifndef PLAYER_H
#define PLAYER_H
/**
 * \file Player.H
 * \brief  classe Player
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include <string>
#include <vector>

using namespace std;

/*! \class Player
   * \brief
   *
   *  La classe Player
   *
   */
class Player
{
    public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Player
     *
     */
        Player();
    /*!
     *  \brief Surchage du Constructeur
     *
     *  Surchage du Constructeur de la classe Player
     *  \param string , le nom du joueur
     *  \param Entier, money l'argent du joueur
     *  \param vector<int>, liste des score du joueur
     */
        // constructeur pour "charger" un joueur existant (utilisé par Engine)
        Player(string name, int money, vector<int> highscore);
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Player
     */
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
    /*!
     *  \brief Attribut name
     *
     * nom du joueur
     *
     */
        string name_; // son nom
    /*!
     *  \brief Attribut money
     *
     *  argent du joueur
     *
     */
        int money_; // argent récolté dans toutes ses parties

    /*!
     *  \brief Attribut highscore
     *
     *  liste des meilleurs scores du joueurs
     *
     */
        vector<int> highscore_; // liste des meilleurs scores
};

#endif // PLAYER_H
