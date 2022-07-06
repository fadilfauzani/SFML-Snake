#include "Game.hpp"
#include <iostream>
Game::Game(): m_window("Snake", sf::Vector2u(800, 600)),
 m_snake(m_world.GetBlockSize()),m_world(sf::Vector2u(800,600))
{
 m_textbox.Setup(5,14,350,sf::Vector2f(225,0));
 m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));

}
Game::~Game(){}
void Game::HandleInput(){
    // std :: cout << "Handle input" << std::endl;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) 
    && m_snake.GetPhysicalDirection() != Direction::Down)
    {
    m_snake.SetDirection(Direction::Up);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) 
    && m_snake.GetPhysicalDirection() != Direction::Up)
    {
    m_snake.SetDirection(Direction::Down);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
    && m_snake.GetPhysicalDirection() != Direction::Right)
    {
    m_snake.SetDirection(Direction::Left);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) 
    && m_snake.GetPhysicalDirection() != Direction::Left)
    {
    m_snake.SetDirection(Direction::Right);
    }
}

void Game::Update(){
    
    float timestep = 1.0f / m_snake.GetSpeed();
    // std :: cout << "Elapsed: " << m_elapsed.asSeconds() << std::endl;
    // std::cout << "Timestep: " << timestep << std::endl;
    if(m_elapsed.asSeconds() >= timestep){
        m_snake.Tick();
        // std :: cout << m_snake.GetPosition().x << "," << m_snake.GetPosition().y << std::endl;
        
        m_world.Update(m_snake, m_textbox);
        m_world.popboard(m_textbox);
        m_world.showText(m_snake, m_textbox);
        m_elapsed -= sf::seconds(timestep);
        if(m_snake.HasLost()){
            m_snake.Reset();
            m_world.RespawnApple();
        }
    }
}

void Game::Render(){
    m_window.BeginDraw();
    m_world.Render(m_window.GetRenderWindow());
    m_snake.Render(m_window.GetRenderWindow());
    m_textbox.Render(m_window.GetRenderWindow());
    m_window.EndDraw();
}
Window* Game::GetWindow(){ return &m_window; }
void Game::RestartClock(){ m_elapsed += m_clock.restart(); }
