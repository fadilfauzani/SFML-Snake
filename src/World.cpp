#include "World.hpp"
#include <iostream>
World::World(sf::Vector2u l_windSize){
    m_blockSize = 16;
    m_windowSize = l_windSize;
    RespawnApple();
    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize / 2);
    loadMaps("Test");
    loadMaps("skull");
    loadMaps("testtt");
    selectMap(0);
}
World::~World(){}


void World::RespawnApple(){
 int maxX = (m_windowSize.x / m_blockSize) -1 ;
 int maxY = (m_windowSize.y / m_blockSize) -1 ;
 m_item = sf::Vector2i(
 rand() % maxX + 1, rand() % maxY + 1);
 m_appleShape.setPosition(
    m_item.x * m_blockSize,
    m_item.y * m_blockSize);
if (CheckCollision(sf::Vector2i(m_item.x, m_item.y))){
    RespawnApple();
}
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
    OutOfBorder(l_player);
    


 if(l_player.GetPosition() == m_item){
    
    l_player.Extend();
    l_player.IncreaseScore();
    l_player.IncreaseLives();
    RespawnApple();
 }
 int gridSize_x = m_windowSize.x / m_blockSize;
 int gridSize_y = m_windowSize.y / m_blockSize;
 if(CheckCollision(l_player.GetPosition())){ //check world colition
    l_player.Lose();
 }
}
bool World::CheckCollision(sf::Vector2i l_pos){
    for(int i = 0; i < m_bounds.size(); ++i){
        if(l_pos.x == m_bounds[i].getPosition().x / m_blockSize -1 && l_pos.y == m_bounds[i].getPosition().y / m_blockSize -1){
            return 1;
        }
    }
    return 0;
}

void World::Render(sf::RenderWindow& l_window){
    // printBounds(maps["Test"]);
    for(int i = 0; i < m_bounds.size(); ++i){
        m_bounds[i].setFillColor(sf::Color(150,0,0));
        // std::cout << "HEre" << std::endl;
        l_window.draw(m_bounds[i]);
    }
    l_window.draw(m_appleShape);
}
int World::GetBlockSize(){ return m_blockSize; }

void World::Add_Bounds(std::vector<sf::RectangleShape>& b, sf::Vector2f l_pos){
    sf::RectangleShape bound;
    bound.setSize(sf::Vector2f(m_blockSize, m_blockSize));
    bound.setOrigin(bound.getSize());
    bound.setPosition(l_pos.x * m_blockSize, l_pos.y * m_blockSize);
    b.push_back(bound);
}

void World::OutOfBorder(Snake& l_player){
    if(l_player.GetPosition().x < 0){
        l_player.SetPosition(sf::Vector2i( m_windowSize.x / m_blockSize - 1, l_player.GetPosition().y));
    }
    if(l_player.GetPosition().x > (m_windowSize.x / m_blockSize - 1)){
        l_player.SetPosition(sf::Vector2i(0, l_player.GetPosition().y));
    }
    if(l_player.GetPosition().y < 0){
        l_player.SetPosition(sf::Vector2i(l_player.GetPosition().x, m_windowSize.y / m_blockSize - 1));
    }
    if(l_player.GetPosition().y > m_windowSize.y / m_blockSize - 1){
        l_player.SetPosition(sf::Vector2i(l_player.GetPosition().x, 0));
    }
}

// void World::saveBounds(){
//     std::string dir = MAP_DIR;
//     std::ofstream bindings;
//     // std::cout<<"HERE" << World::m_filename;
//     bindings.open(dir + "Test");
//     std::vector<std::string> bounds;
//     if (!bindings.is_open()){
//         std::cout << "! Failed loading bound." << std::endl;
//         return;
//     }
//     int gridSize_x = m_windowSize.x / m_blockSize;
//     int gridSize_y = m_windowSize.y / m_blockSize;
//     for (int i = 0; i < gridSize_y; ++i){
//         bounds.push_back("");
//         for (int j = 0; j < gridSize_x; ++j)
//         {
//             bounds[i] = bounds[i] + "=";
//         }
//         bounds[i] = bounds[i] + "\n";
//     }
//     for (int i = 0; i < m_bounds.size(); ++i){
//         std::cout<<"HERE";
//         bounds[m_bounds[i].getPosition().y / m_blockSize ][m_bounds[i].getPosition().x / m_blockSize] = '#';
//     }
//     for (int i = 0; i < gridSize_y; ++i){
//         bindings << bounds[i];
//     }
//     bindings.close();
// }
void World::loadMaps(std::string filename){
    std::string dir = MAP_DIR;
    std::ifstream in;
    in.open(dir + filename);
    std::vector<std::string> bounds;
    std::vector<sf::RectangleShape> bound;

    if (!in.is_open()){
        std::cout << "! Failed loading bound." << std::endl;
        return;
    }
    int gridSize_x = m_windowSize.x / m_blockSize;
    int gridSize_y = m_windowSize.y / m_blockSize;
    for (int i = 0; i < gridSize_y; ++i){
        std::string line;
        getline(in, line);
        bounds.push_back(line);
    }
    for (int i = 0; i < gridSize_y; ++i){
        for (int j = 0; j < gridSize_x; ++j)
        {
            if (bounds[i][j] == '#'){
                Add_Bounds(bound, sf::Vector2f(j+1, i+1));
            }
        }
    }
    // printBounds(bound);
    maps.push_back(bound);
    in.close();
}
void World::selectMap(int i){
    m_bounds = maps[i];
}
void World::printBounds(std::vector<sf::RectangleShape> bounds){
    // std::cout << "HEre";
    for (int i = 0; i < bounds.size(); ++i){
        std::cout << bounds[i].getPosition().x << " " << bounds[i].getPosition().y << std::endl;
    }
    std::flush(std::cout);
}