#include "Button.h"

Button::Button() {
	static SDL_Texture *t = IMG_LoadTexture(ren, "assent/FightButton.png");
	tex = t; 

	srect.h = 600;
	srect.w = 800;
	srect.x = 0;

	drect.h = 50;
	drect.w = 250;
}

Button::~Button() {
}

void Button::update(Mouse& mouse) {
	if (SDL_HasIntersection(&drect, &mouse.point)) {
		isSelected = true;
		drect.h = 55;
		drect.w = 280;
	}
	else {
		isSelected = false;
		drect.h = 50;
		drect.w = 250;
	}
}

void Button::draws() {
	SDL_RenderCopy(ren, tex, &srect, &drect);
}

TTF_Font* font = TTF_OpenFont("Font/PokemonHollow.ttf", 24);
SDL_Color white = { 255,0,255 };





void DrawText(string text, int x, int y) {
    SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), white);
        SDL_Texture* Texture = SDL_CreateTextureFromSurface(ren, surf);
        SDL_Rect rect2 = { x,y,surf->w ,surf->h };
        SDL_FreeSurface(surf);
        SDL_RenderCopy(ren, Texture, NULL, &rect2);
        SDL_DestroyTexture(Texture);
    
}

  DrawText("Hello, world!", 50, 50);
