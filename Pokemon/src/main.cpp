#include "Button.h"

int init = SDL_Init(SDL_INIT_EVERYTHING);
int init2 = Mix_Init(0);
SDL_Window* win = SDL_CreateWindow("PokemonGo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, 0);
SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

double delta = .0001;
double time2 = SDL_GetTicks();

int main(int argc,char **argv) {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music* music = Mix_LoadMUS("Audio/Battle.wav");
    if (!music) {
        cout << "Music Error" << Mix_GetError() << endl;
    }
    Mix_Chunk* sound = Mix_LoadWAV("Audio/Select.wav");
    if (!sound) {
        cout << "sound Error" << Mix_GetError() << endl;
    }

    //Mix_PlayMusic(music, -1);
    Mix_PlayChannel(-1, sound, 0);


    Mouse mouse;
    
    bool running = true;

    SDL_Rect rect{ 100,50,200,132 };
    SDL_Rect rectBackground{ 0,1,1280,720 };

    SDL_Texture* tex = IMG_LoadTexture(ren, "assent/Background.png");
    if (!tex) {
        cout << SDL_GetError() << endl;
    }

    Button FightButton;
    FightButton.srect.y = 0 ;
    FightButton.drect.x = SCREEN_WIDTH/1.2 - FightButton.drect.w/2;
    FightButton.drect.y = 450;


    while (running) {

        mouse.update();
        FightButton.update(mouse);

        delta = (SDL_GetTicks() - time2) / 1000;
        time2 = SDL_GetTicks();

        SDL_Event e;
        
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT :
                    running = false;
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (e.button.button == SDL_BUTTON_LEFT) {
                        if (FightButton.isSelected) {
                            cout << "Pokemon Fight\n";
                            Mix_PlayChannel(-1, sound, 0);
                        }
                    }
                }
                
                     
        }

        SDL_RenderCopy(ren, tex, NULL, &rectBackground);
        FightButton.draws();
        mouse.draw();
        SDL_RenderPresent(ren);
      

    }
    SDL_Quit();
 
    return 0 ;
}
