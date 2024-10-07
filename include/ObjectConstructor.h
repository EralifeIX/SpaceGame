#ifndef OBJECTCONSTRUCTOR_H
#define OBJECTCONSTRUCTOR_H

//This class was made to spread and control global data
#include <memory>
#include <list>
#include "GameObject.h"

class Player;
class Bullet;
class Menu;
class ObjectConstructor { // This class used to let game objects communicate each other
public:                   // Like bullets check did they catch enemy, or enemies get to th Base (Plants vs Zombies logic)
    ObjectConstructor();
    std::shared_ptr<Window> GetWindow();
    std::shared_ptr<Menu> GetMenu();
    std::list<std::shared_ptr<GameObject>> GetObjects();
    void AddObject(const std::shared_ptr<GameObject>& gameObject);
    void RemoveTerminated();
    void SpawnEnemy();
    void GameOver();
    bool IsGame();
private:
    bool terminated = false;
    int score = 0;
    std::shared_ptr<Window> m_window;
    std::list<std::shared_ptr<GameObject>> m_game_objects;
    std::shared_ptr<Menu> m_menu;
};



#endif //OBJECTCONSTRUCTOR_H
