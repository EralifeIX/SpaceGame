//
// Created by eralife on 7/13/24.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "ObjectConstructor.h"
#include <memory>
#include <iostream>
#include <random>
#include <chrono>

class Enemy : public GameObject{
public:
    Enemy();
    void Update(sf::Event event, const float& frametime) override;
    void Render(const std::shared_ptr<Window> window) override;
    bool IsDone() override;
    void Terminate() override;
    sf::Vector2f getPosition() override;
    void SetOC(ObjectConstructor* oc);
    void SetRandomPos();

private:
    bool terminated = false;
    ObjectConstructor* OC = nullptr;
    sf::Vector2f m_position;
    sf::Texture m_texture;
    // sf::Sound SpawnSound; I don't have any enemy sound effect
    float enemySpeed = 70;
};



#endif //ENEMY_H
