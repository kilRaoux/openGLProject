#include "InputManager.h"



InputManager::InputManager() :
	m_x(0), m_y(0), m_xRel(0), m_yRel(0), m_terminer(false)
{
	m_events = SDL_Event();
	for (int i(0); i < SDL_NUM_SCANCODES; i++) {
		m_keys[i] = false;
		m_callbackKey[i] = nullFoo;
	}


	for (int i(0); i < 8; i++)
		m_buttonMouse[i] = false;
}


InputManager::~InputManager()
{
}

void InputManager::update()
{
	m_xRel = 0;
	m_yRel = 0;

	while (SDL_PollEvent(&m_events))
	{
		switch (m_events.type)
		{
		case SDL_KEYDOWN:
			m_keys[m_events.key.keysym.scancode] = true;
			break;

		case SDL_KEYUP:
			m_keys[m_events.key.keysym.scancode] = false;

		case SDL_MOUSEBUTTONDOWN:
			m_buttonMouse[m_events.button.button] = true;
			break;
			
		case SDL_MOUSEBUTTONUP:
			m_buttonMouse[m_events.button.button] = false;
			break;

		case SDL_MOUSEMOTION:
			m_x = m_events.motion.x;
			m_y = m_events.motion.y;

			m_xRel = m_events.motion.xrel;
			m_yRel = m_events.motion.yrel;
			break;
		
		case SDL_WINDOWEVENT:
			if (m_events.window.event == SDL_WINDOWEVENT_CLOSE)
				m_terminer = true;
			break;
		
		
		
		}
	}
}

bool InputManager::terminer() const
{
	return m_terminer;
}

bool InputManager::getKey(const SDL_Scancode key) const
{
	return m_keys[key];
}

void InputManager::nullFoo(InputManager * on)
{
}

void InputManager::bind(const SDL_Scancode key, void(*command)(InputManager*))
{
}

float InputManager::getXRel() const
{
	return m_xRel;
}

float InputManager::getYRel() const
{
	return m_yRel;
}

bool InputManager::mouseMove() const
{
	if (m_xRel == 0 && m_yRel == 0)
		return false;

	else
		return true;
}
