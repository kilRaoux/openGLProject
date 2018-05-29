#pragma once
#include <SDL.h>
class InputManager
{
public:
	InputManager();
	~InputManager();
	void update();
	bool terminer() const;
	bool getKey(const SDL_Scancode key) const;
	void bind(const SDL_Scancode key, void(*command)(InputManager*));
	float getXRel() const;
	float getYRel() const;
	bool mouseMove() const;
private:
	static void nullFoo(InputManager *in);
	SDL_Event m_events;
	bool m_keys[SDL_NUM_SCANCODES];
	void(*m_callbackKey[SDL_NUM_SCANCODES])(InputManager*);
	bool m_buttonMouse[8];
	int m_x, m_y, m_xRel, m_yRel;
	bool m_terminer;
};

