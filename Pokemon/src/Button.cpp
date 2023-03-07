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
