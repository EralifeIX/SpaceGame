#ifndef BULLET_H
#define BULLET_H
#include <Audio.hpp>
#include "GameObject.h"
#include "Graphics.hpp"
#include "Window.h"
#include "ObjectConstructor.h"
#include <iostream>
#include <random>
#include <memory>

class Bullet : public GameObject{
public:
    Bullet(sf::Vector2f spawnpos);
    void Update(sf::Event event, const float& frametime) override;
    void Render(const std::shared_ptr<Window> window) override;

    sf::RectangleShape GetRect();
    void SetOC(ObjectConstructor* oc);
    void isCollision();
    sf::Vector2f getPosition() override;
    bool IsDone();
    void Terminate() override;
private:
    bool terminated = false;
    ObjectConstructor* OC = nullptr;
    sf::Vector2f m_position;
    sf::Texture m_texture;
    sf::Sound SpawnSound;
    float bulletSpeed = 500;
    float timeAlive;
};



#endif //BULLET_H
