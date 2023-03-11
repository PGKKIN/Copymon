#include "Button.h"
#include "Func.h"



int init = SDL_Init(SDL_INIT_EVERYTHING);
int init2 = Mix_Init(0);
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
SDL_Window* window = SDL_CreateWindow("PokemonGo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
SDL_Renderer* ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
SDL_Color white = { 255,0,255 };

double delta = .0001;
double time2 = SDL_GetTicks();

void DrawText(string text, int x, int y) {
    SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), white);
        SDL_Texture* Texture = SDL_CreateTextureFromSurface(ren, surf);
        SDL_Rect rect2 = { x,y,surf->w ,surf->h };
        SDL_FreeSurface(surf);
        SDL_RenderCopy(ren, Texture, NULL, &rect2);
        SDL_DestroyTexture(Texture);
    
}

void P1_Team(vector<Unit> &x){
    cout<<"Your Current Pokemon : " <<"1." <<x[0].name <<endl;
    cout<<"Your Other Pokemon : " ;
    for(int i = 0 ; i < 3 ; i++){
        if(x[i].name != x[0].name){
            cout<<i+1<<"." <<x[i].name <<" ";
        }
   }
   cout<<endl;
}

void Switch(vector<Unit> &x){
    cout<<"Switch The Current Pokemon : "  ;
    int Switch_Number ;
    cin >> Switch_Number ;
    Unit temp = x[0] ;
    x[0] = x[Switch_Number-1] ;
    x[Switch_Number-1] = temp;
}

void swpoP(int x,vector<Unit> &a){
    if(x==0){
        P1_Team(a);
        cout<<"---------------------------------------\n";
        Switch(a); 
        cout<<"---------------------------------------\n";
        P1_Team(a);
        cout<<"---------------------------------------\n";
    }
}

void ChoosePokemon2(vector<Unit>& y, string x[], Unit a, Unit b, Unit c, Unit d, Unit e, Unit f, Unit g, Unit h, Unit i, Unit j,int u) {
        switch (u) {
        case 1:
            y.push_back(a);
            break;
        case 2:
            y.push_back(b);
            break;
        case 3:
            y.push_back(c);
            break;
        case 4:
            y.push_back(d);
            break;
        case 5:
            y.push_back(e);
            break;
        case 6:
            y.push_back(f);
            break;
        case 7:
            y.push_back(g);
            break;
        case 8:
            y.push_back(h);
            break;
        case 9:
            y.push_back(i);
            break;
        case 10:
            y.push_back(j);
            break;

        }
}

void showpk(vector<Unit> x) {
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ".";
        for (int j = 0; j < 2; j++) {
            vector<string> stat = x[i].getSelect2();
            cout << stat[j] << " ";
        }
        cout << " ";
        for (int k = 0; k < 1; k++) {
            vector<int> stat2 = x[i].getSelect();
            cout << "HP" << stat2[k] << " " << "ATK" << stat2[k + 1] << " " << "DEF" << stat2[k + 2] << " " << "SPEED" << stat2[k + 3] << " ";
        }
        for (int l = 0; l < 7; l += 2) {
            vector<string> stat3 = x[i].getSelect3();
            cout << stat3[l];
            if (l < 6) cout << " Type:" << stat3[l + 1] << " ";
        }
        cout << endl;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
    Unit decoy("None", "x", 0, 0, 0, 0, 0, "x", "x", 0, "x", "x", 0, "x", "x", 0, "x", false);
    Unit poke1("Charizard", "Fire", 200, 50, 50, 100, 200, "Daimonji", "Fire", 75, "DragonClaw", "Dragon", 50, "BrickBreak", "Fighting", 50, "Protect", false);
    Unit poke2("Blastoise", "Water", 200, 25, 75, 78, 200, "HydroPump", "Water", 75, "DarkPaluse", "Dark", 50, "IceBeam", "Ice", 50, "Protect", false);
    Unit poke3("Venusaur", "Grass", 200, 25, 75, 80, 200, "SolarBeam", "Grass", 75, "SeedBomb", "Grass", 65, "Doube-Edge", "Normal", 60, "Protect", false);
    Unit poke4("Snorlax", "Normal", 400, 10, 30, 30, 400, "HyperBeam", "Normal", 90, "Crunch", "Dark", 50, "HammerArm", "Fighting", 50, "Protect", false);
    Unit poke5("Lucario", "Fighting", 175, 75, 50, 90, 175, "CloseCombat", "Fighting", 75, "DragonPaluse", "Dragon", 50, "ExtreamSpeed", "Normal", 60, "Protect", false);
    Unit poke6("Gengar", "Ghost", 200, 75, 25, 110, 200, "DestinyBond", "Ghost", 75, "SukerPunch", "Dark", 50, "FirePunch", "Fire", 50, "Protect", false);
    Unit poke7("Gardevoir", "Fairy", 200, 75, 25, 85, 200, "Moonblast", "Fairy", 75, "MysticalFire", "Fire", 50, "GrassKnot", "Grass", 50, "Protect", false);
    Unit poke8("Garchomp", "Dragon", 200, 50, 50, 102, 200, "DragonRush", "Dragon", 75, "BrickBreak", "Fighting", 50, "FireFang", "Fire", 50, "Protect", false);
    Unit poke9("Abomasnow", "Ice", 300, 30, 30, 60, 300, "Blizzard", "Ice", 75, "WoodHammer", "Grass", 60, "IcePunch", "Ice", 50, "Protect", false);
    Unit poke10("Absol", "Dark", 200, 60, 40, 95, 200, "NightSlash", "Dark", 75, "Curse", "Ghost", 50, "RockSmash", "Fighting", 50, "Protect", false);
   
    int Index = 0;
    vector<Unit> player1_pokemon = { poke1, poke2, poke3 };
    vector<Unit> allpoke = { poke1, poke2, poke3,poke4,poke5,poke6,poke7,poke8,poke9,poke10 };
    string pokemonNames[] = { "Charizard","Blastoise","Venusaur","Snorlax","Lucario","Gengar","Gardevoir","Garchomp","Abomasnow","Absol", };
    
    vector<Unit> selected_pokemon1; //Arrey โปเกมอน;
    vector<Unit> selected_pokemon2; //Arrey โปเกมอน
    
    showpk(allpoke);

    cout << "---------------------------------------\n";//เลือกโปร
    int p1 = 0;
    int p2 = 0;

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music* music = Mix_LoadMUS("Audio/Battle.wav");
    if (!music) {
        cout << "Music Error" << Mix_GetError() << endl;
    }
    Mix_Chunk* sound = Mix_LoadWAV("Audio/Click.wav");
    if (!sound) {
        cout << "sound Error" << Mix_GetError() << endl;
    }

    //Mix_PlayMusic(music, -1);
  
    Mouse mouse;

    SDL_Rect rect{ 100,50,200,132 };
    SDL_Rect rectBackground{ 0,1,640,480 };

    SDL_Texture* tex = IMG_LoadTexture(ren, "Assent/Background.png");

    Button FightButton;
    FightButton.srect.y = 0;
    FightButton.drect.x = 380 - FightButton.drect.w / 2;
    FightButton.drect.y = 400;

    Button2 HealButton;
    HealButton.srect2.y = 0;
    HealButton.drect2.x = 480 - HealButton.drect2.w / 2;
    HealButton.drect2.y = 400;

    Button3 SwichButton;
    SwichButton.srect3.y = 0;
    SwichButton.drect3.x = 580 - SwichButton.drect3.w / 2;
    SwichButton.drect3.y = 400;

    Num1 Num1;
    Num1.srect.y = 0;
    Num1.drect.x = 385 - Num1.drect.w / 2;
    Num1.drect.y = 275;

    Num2 Num2;
    Num2.srect.y = 0;
    Num2.drect.x = 420 - Num2.drect.w / 2;
    Num2.drect.y = 275;

    Num3 Num3;
    Num3.srect.y = 0;
    Num3.drect.x = 480 - Num3.drect.w / 2;
    Num3.drect.y = 275;

    Num4 Num4;
    Num4.srect.y = 0;
    Num4.drect.x = 540 - Num4.drect.w / 2;
    Num4.drect.y = 275;

    Num5 Num5;
    Num5.srect.y = 0;
    Num5.drect.x = 600 - Num5.drect.w / 2;
    Num5.drect.y = 275;

    Num6 Num6;
    Num6.srect.y = 0;
    Num6.drect.x = 360 - Num6.drect.w / 2;
    Num6.drect.y = 330;

    Num7 Num7;
    Num7.srect.y = 0;
    Num7.drect.x = 420 - Num7.drect.w / 2;
    Num7.drect.y = 330;

    Num8 Num8;
    Num8.srect.y = 0;
    Num8.drect.x = 480 - Num8.drect.w / 2;
    Num8.drect.y = 330;

    Num9 Num9;
    Num9.srect.y = 0;
    Num9.drect.x = 540 - Num9.drect.w / 2;
    Num9.drect.y = 330;

    Num10 Num10;
    Num10.srect.y = 0;
    Num10.drect.x = 600 - Num10.drect.w / 2;
    Num10.drect.y = 330;


    
    int P2_Action = 0;
    int P1_Action = 0;
    int Poke = 0;
    int num1 = 10;
    int num2 = 10;
    int state = 1 ;
    bool select1 = true;
    bool select2 = false;
    bool select3 = true;
    bool Attack = false;

    cout << "Player_1 Team Selection\n";
    cout << "---------------------------------------\n";//เลือกโปร
    bool running = true;
    while (running) {

        Num1.update(mouse);
        Num2.update(mouse);
        Num3.update(mouse);
        Num4.update(mouse);
        Num5.update(mouse);
        Num6.update(mouse);
        Num7.update(mouse);
        Num8.update(mouse);
        Num9.update(mouse);
        Num10.update(mouse);

        mouse.update();
        FightButton.update(mouse);
        HealButton.update2(mouse);
        SwichButton.update3(mouse);

        delta = (SDL_GetTicks() - time2) / 1000;
        time2 = SDL_GetTicks();

        SDL_Event e;
        
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONUP:
                switch (state) {
                    case 1 :
                        if (e.button.button == SDL_BUTTON_LEFT) {
                            if (Num1.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 1);
                                cout << pokemonNames[0] << endl;
                                break;
                            }
                            if (Num2.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 2);
                                cout << pokemonNames[1] << endl;
                                break;
                            }
                            if (Num3.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 3);
                                cout << pokemonNames[2] << endl;
                                break;
                            }

                            if (Num4.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 4);
                                cout << pokemonNames[3] << endl;
                                break;
                            }
                            if (Num5.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 5);
                                cout << pokemonNames[4] << endl;
                                break;
                            }
                            if (Num6.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 6);
                                cout << pokemonNames[5] << endl;
                                break;
                            }
                            if (Num7.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 7);
                                cout << pokemonNames[6] << endl;
                                break;
                            }

                            if (Num8.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 8);
                                cout << pokemonNames[7] << endl;
                                break;
                            }
                            if (Num9.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 9);
                                cout << pokemonNames[8] << endl;
                                break;
                            }

                            if (Num10.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon1, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 10);
                                cout << pokemonNames[9] << endl;
                                break;
                            }
                    default :
                        continue;
                        }
                    case 2 :
                        if (e.button.button == SDL_BUTTON_LEFT) {
                            if (Num1.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 1);
                                cout << pokemonNames[0] << endl;
                                break;
                            }
                            if (Num2.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 2);
                                cout << pokemonNames[1] << endl;
                                break;
                            }
                            if (Num3.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 3);
                                cout << pokemonNames[2] << endl;
                                break;
                            }

                            if (Num4.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 4);
                                cout << pokemonNames[3] << endl;
                                break;
                            }
                            if (Num5.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 5);
                                cout << pokemonNames[4] << endl;
                                break;
                            }
                            if (Num6.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 6);
                                cout << pokemonNames[5] << endl;
                                break;
                            }
                            if (Num7.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 7);
                                cout << pokemonNames[6] << endl;
                                break;
                            }

                            if (Num8.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 8);
                                cout << pokemonNames[7] << endl;
                                break;
                            }
                            if (Num9.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 9);
                                cout << pokemonNames[8] << endl;
                                break;
                            }

                            if (Num10.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                ChoosePokemon2(selected_pokemon2, pokemonNames, poke1, poke2, poke3, poke4, poke5, poke6, poke7, poke8, poke9, poke10, 10);
                                cout << pokemonNames[9] << endl;
                                break;
                            }

                        }    
                    case 4:
                        if (e.button.button == SDL_BUTTON_LEFT) {
                            if (FightButton.isSelected) {
                                Mix_PlayChannel(-1, sound, 0);
                                P1_Action = 1;
                                break;
                            }
                            if (HealButton.isSelected2) {
                                Mix_PlayChannel(-1, sound, 0);
                                P1_Action = 2;
                                break;
                            }if (SwichButton.isSelected3) {
                                Mix_PlayChannel(-1, sound, 0);
                                P1_Action = 3;
                                break;
                            }
                        }
                        
                }
                break;
            }
        }
        

        switch (state) {
            case 1 :
                if (selected_pokemon1.size() == 3) {
                    cout << "-----You 1 have selected the following Pokemon----- " << endl;
                    for (int i = 0; i < selected_pokemon1.size(); i++) {
                        cout << i + 1 << "." << selected_pokemon1[i].name << endl;

                    }
                    cout << endl;
                    cout << "Player_2 Team Selection\n";
                    cout << "---------------------------------------\n";//เลือกโปร
                    state = 2;
                    break;
                }
            case 2 : 
                if (selected_pokemon2.size() == 3) {
                    cout << "-----You 2 have selected the following Pokemon----- " << endl;
                    for (int i = 0; i < selected_pokemon2.size(); i++) {
                        cout << i + 1 << "." << selected_pokemon2[i].name << endl;

                    }
                    cout << endl;
                    state = 3;
                    break;
            
                }
            case 3:
                 if (selected_pokemon1.size() == 3 && selected_pokemon2.size() == 3) {
                        selected_pokemon2[0].showStatusforP2();
                        selected_pokemon1[0].showStatusforP1();
                        state = 4;
                        break;
                 }
            case 4:
                swi
        }





        SDL_RenderCopy(ren, tex, NULL, &rectBackground);
        ///////////////////////
        FightButton.draws();
        HealButton.draws2();
        SwichButton.draws3();
        Num1.draws();
        Num2.draws();
        Num3.draws();
        Num4.draws();
        Num5.draws();
        Num6.draws();
        Num7.draws();
        Num8.draws();
        Num9.draws();
        Num10.draws();
        mouse.draw();
        /////////////////////
        SDL_RenderPresent(ren);

 

    }

    TTF_Quit();
    SDL_Quit();

    return 0;
}
