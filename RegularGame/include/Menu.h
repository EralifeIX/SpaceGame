#include "ObjectConstructor.h"
#include "unordered_map"
#include "SFML/Graphics.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#ifndef MENU_H
#define MENU_H


// used in ObjectConstructor to implement menu
class Menu {
public:
    explicit Menu(ObjectConstructor* oc);
    void Update();
    bool IsPaused();
    void Switch();
    void Return();
    void AddScore();
    void DrawScore();
private:
    unsigned int score;
    ObjectConstructor* OC;
    bool paused;
    std::unordered_map<char, sf::Texture> letters;
    void LoadLetters();
    void DrawText(std::string text, sf::Vector2u pos);
};



#endif //MENU_H
