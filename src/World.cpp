#include "World.hpp"
#include <iostream>
World::World(sf::Vector2u l_windSize){
    m_blockSize = 16;
    m_windowSize = l_windSize;
    RespawnApple();
    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize / 2);
    for(int i = 1; i <= m_windowSize.x / m_blockSize; ++i)
    {   

        // sf::RectangleShape bound;
        // bound.setSize(sf::Vector2f(m_blockSize, m_blockSize));
        // bound.setOrigin(bound.getSize() );
        // float randx = ((rand() % (m_windowSize.x) + m_blockSize) / m_blockSize) * m_blockSize;
        // float randy = ((rand() % (m_windowSize.y) + m_blockSize) / m_blockSize) * m_blockSize;
        // bound.setPosition(sf::Vector2f( randx, randy ));
        Add_Border(sf::Vector2f( i, 1 ));
        Add_Border(sf::Vector2f( 1, i ));
        Add_Border(sf::Vector2f( m_windowSize.x / m_blockSize, i ));
        Add_Border(sf::Vector2f( i , m_windowSize.y / m_blockSize  ));

        // m_bounds.push_back(bound);
        // // std::cout << bound.getOrigin().x << "," <<  bound.getOrigin().y << std::endl;
        std::cout << l_windSize.x << std::endl;

    }
}
World::~World(){}


void World::RespawnApple(){
 int maxX = (m_windowSize.x / m_blockSize) - 2;
 int maxY = (m_windowSize.y / m_blockSize) - 2;
 m_item = sf::Vector2i(
 rand() % maxX + 1, rand() % maxY + 1);
 m_appleShape.setPosition(
    m_item.x * m_blockSize,
    m_item.y * m_blockSize);
}
void World::showText(Snake& l_player, Textbox& l_textbox){
    std::string l_content;
    l_textbox.Add("Score : " + std::to_string(l_player.GetScore()));
    l_textbox.Add("Length : " + std::to_string(l_player.GetLives()));
}
void World::popboard(Textbox& l_textbox){
    if (l_textbox.length() > 2){
        // std::cout << l_textbox.length() << std::endl;
        l_textbox.pop();
        l_textbox.pop();
    }
}
void World::Update(Snake& l_player, Textbox& l_textbox){
 if(l_player.GetPosition() == m_item){
    
    l_player.Extend();
    l_player.IncreaseScore();
    l_player.IncreaseLives();
    RespawnApple();
 }
 int gridSize_x = m_windowSize.x / m_blockSize;
 int gridSize_y = m_windowSize.y / m_blockSize;
 if(CheckCollision(l_player)){ //check world colition
    l_player.Lose();
 }
}
bool World::CheckCollision(Snake& l_player){
    for(int i = 0; i < m_bounds.size(); ++i){
        if(l_player.GetPosition().x == m_bounds[i].getPosition().x / m_blockSize -1 && l_player.GetPosition().y == m_bounds[i].getPosition().y / m_blockSize -1){
            return 1;
        }
    }
    return 0;
}
void World::Render(sf::RenderWindow& l_window){
 for(int i = 0; i < m_bounds.size(); ++i){
        m_bounds[i].setFillColor(sf::Color(150,0,0));
 l_window.draw(m_bounds[i]);
//  std::cout << m_bounds[i].getPosition().x / m_blockSize<< "," << m_bounds[i].getPosition().y / m_blockSize<< std::endl;
 }
 l_window.draw(m_appleShape);
}
int World::GetBlockSize(){ return m_blockSize; }

void World::Add_Border(sf::Vector2f l_pos){
    sf::RectangleShape bound;
    bound.setSize(sf::Vector2f(m_blockSize, m_blockSize));
    bound.setOrigin(bound.getSize());
    bound.setPosition(l_pos.x * m_blockSize, l_pos.y * m_blockSize);
    m_bounds.push_back(bound);
}