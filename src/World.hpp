#ifndef __WORLD__H__
#define __WORLD__H__
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "TextBox.hpp"
class World{
    public:
        World(sf::Vector2u l_windSize);
        ~World();
        int GetBlockSize();
        void RespawnApple();
        void Update(Snake& l_player, Textbox& l_textbox);
        void showText(Snake& l_player,Textbox& l_textbox);
        void Render(sf::RenderWindow& l_window);
        void popboard(Textbox& l_textbox);
        bool CheckCollision(Snake& l_player);
        void Add_Border(sf::Vector2f l_pos);
    private:
        sf::Vector2u m_windowSize;
        sf::Vector2i m_item;
        int m_blockSize;
        sf::CircleShape m_appleShape;
        std::vector<sf::RectangleShape> m_bounds;
};
#endif  //!__WORLD__H__