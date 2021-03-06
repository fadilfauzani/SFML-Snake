#ifndef __WINDOW__H__
#define __WINDOW__H__
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventManager.hpp"
class Window{
    public:
        Window();
        Window(const std::string& l_title,const sf::Vector2u& l_size);
        ~Window();
        void BeginDraw(); // Clear the window.
        void EndDraw(); // Display the changes.
        void Update();
        bool IsDone();
        bool IsFullscreen();
        sf::Vector2u GetWindowSize();
        void Draw(sf::Drawable& l_drawable);
        sf::RenderWindow& GetRenderWindow();
        bool IsFocused();
        EventManager* GetEventManager();
        void ToggleFullscreen(EventDetails* l_details);
        void Close(EventDetails* l_details);
        void CloseHelper();
    private:
        void Setup(const std::string& l_title, const sf::Vector2u& l_size);
        void Destroy();
        void Create();
        sf::RenderWindow m_window;
        sf::Vector2u m_windowSize;
        std::string m_windowTitle;
        bool m_isDone;
        bool m_isFullscreen;
        EventManager m_eventManager;
        bool m_isFocused;
};
#endif  //!__WINDOW__H__