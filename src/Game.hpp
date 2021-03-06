#ifndef __GAME__H__
#define __GAME__H__
#include "World.hpp"
#include "Snake.hpp"
#include "Window.hpp"
#include "TextBox.hpp"

class Game{
    public:
        Game();
        ~Game();
        void Update();
        void Render();
        // void HandleInput();
        Window* GetWindow();
        sf::Time GetElapsed();
        void RestartClock();
        void setSDirUp(EventDetails* l_details);
        void setSDirLe(EventDetails* l_details);
        void setSDirRi(EventDetails* l_details);
        void setSDirDo(EventDetails* l_details);
    private:
        World m_world;
        Snake m_snake;
        Window m_window;
        sf::Clock m_clock;
        sf::Time m_elapsed;
        Textbox m_textbox;

};

#endif  //!__GAME__H__