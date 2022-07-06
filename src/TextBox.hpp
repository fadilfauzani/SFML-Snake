#ifndef __TEXTBOX__H__
#define __TEXTBOX__H__
#include <SFML/Graphics.hpp>
using MessageContainer = std::vector<std::string>;
class Textbox{
    public:
        Textbox();
        Textbox(int l_visible, int l_charSize, 
        int l_width, sf::Vector2f l_screenPos);
        ~Textbox();
        void Setup(int l_visible, int l_charSize, 
        int l_width, sf::Vector2f l_screenPos);
        void Add(std::string l_message);
        void Clear();
        void Render(sf::RenderWindow& l_wind);
        int length();
        void pop();
    private:
        MessageContainer m_messages;
        int m_numVisible;
        sf::RectangleShape m_backdrop;
        sf::Font m_font;
        sf::Text m_content;
};
#endif  //!__TEXTBOX__H__