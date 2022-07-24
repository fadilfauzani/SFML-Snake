#ifndef __WORLD__H__
#define __WORLD__H__
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "TextBox.hpp"
#include "macros.hpp"
#include <map>
using Maps = std::vector<std::vector<sf::RectangleShape>>;
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
        bool CheckCollision(sf::Vector2i l_pos);
        void Add_Bounds(std::vector<sf::RectangleShape>& b, sf::Vector2f l_pos);
        void OutOfBorder(Snake& l_player);
        void saveBounds();
        void loadMaps(std::string filename);
        void selectMap(int i);
        void printBounds(std::vector<sf::RectangleShape> bounds);
    private:
        sf::Vector2u m_windowSize;
        sf::Vector2i m_item;
        int m_blockSize;
        sf::CircleShape m_appleShape;
        Maps maps;
        std::vector<sf::RectangleShape> m_bounds;
};
#endif  //!__WORLD__H__