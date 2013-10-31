#include "include/Define.h"
#include "include/Engine.h"

using namespace std;

int main(void)
{
    // On rend l'aléatoire aléatoire
    srand(time(0));

    /***************************
    * Variables liées à la SDL *
    ***************************/
    SDL_Surface *screen; // surface principale
    SDL_Event event;
    FPSmanager frame_manager;
    bool loop = true; // variable pour la boucle globale

    /***************************
    * Initialisation de la SDL *
    ***************************/
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        cout << "SDL Init error" << endl;
        exit(EXIT_FAILURE);
    }
    if((screen = SDL_SetVideoMode(800, 600, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE)) == NULL)
    {
        cout << "SDL Video set error" << endl;
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Swrid Prototype", NULL); // Nom de la fenêtre
    SDL_initFramerate(&frame_manager);
    SDL_setFramerate(&frame_manager, FPS); // on fixe le fps à 30

    /*********************
    * Création du moteur *
    *********************/
    Engine engine(screen, &event, &loop); // on crée le moteur
    engine.init(); // on initialise
    // On nettoie la grille
    while(engine.getGrid()->purge())
    {
            engine.getGrid()->update_gravity();
    }

    /******************
    * Boucle générale *
    ******************/
    while(loop)
    {
        engine.event(); // on gère les événements
        engine.render(); // on prépare l'affichage de l'UI

        SDL_Flip(screen); // on affiche l'écran

        SDL_framerateDelay(&frame_manager); // régulateur de frames
    }

    /***************************
    * Libération de la mémoire *
    ***************************/
    SDL_Quit();

    return EXIT_SUCCESS;
}
