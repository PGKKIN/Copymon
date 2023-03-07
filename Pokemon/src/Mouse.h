#ifndef  MOUSE_H
#define MOUSE_H
#include "Global.h"

class Mouse {
public:
	SDL_Texture* tex;
	SDL_Rect rect;
	SDL_Rect point;

	Mouse() {
		tex = IMG_LoadTexture(ren, "assent/Mouse.png");
		rect.w = 30;
		rect.h = 30;
		point.w = 1;
		point.h = 1;
		SDL_ShowCursor(false);
	}

	void update() {
		SDL_GetMouseState(&rect.x, &rect.y);
		point.x = rect.x;
		point.y = rect.y;

	}

	void draw() {
		SDL_RenderCopy(ren, tex, NULL, &rect);
	}
};
#endif // ! MOUSE_H