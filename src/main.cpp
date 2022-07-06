#include "Game.hpp"
#include "Window.hpp"
int main(){
    // Program entry point.
    Game game; // Creating our game object.
    while(!game.GetWindow()->IsDone()){
        // Game loop.
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock(); // Restarting our clock.
    }
    return 0;
}