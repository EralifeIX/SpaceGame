//
// Created by eralife on 7/7/24.
//

#ifndef GAME_H
#define GAME_H
#include <memory>
#include "Window.h"

class Game {
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    std::shared_ptr<Window> GetWindow();

private:
    void MovePlayer();
    Window m_window;

};



#endif //GAME_H
