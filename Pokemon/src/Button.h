#include "Mouse.h"

class Button {
public:
	SDL_Texture *tex;
	SDL_Rect srect, drect;
	bool isSelected = false;

	Button();
	virtual ~Button();

	void update(Mouse&);
	void draws();
};