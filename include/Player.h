#ifndef PLAYER_H
#define PLAYER_H

#include "Graphics.hpp"
#include"Audio.hpp"
#include "Window.h"
#include "ObjectConstructor.h"
#include "GameObject.h"
#include <chrono>
#include <memory>

using namespace std::chrono;

class Player : public GameObject {
public:
    Player();
    void Update(sf::Event event, const float& frametime) override;
    void Render(const std::shared_ptr<Window> window) override;
    sf::Vector2f getPosition() override;
    bool IsDone() override;
    void Terminate() override;

    void SetOC(ObjectConstructor* oc);

private:
    float speed = 325; //default speed
    ObjectConstructor* OC = nullptr; //Object constructor to get game data
    sf::Vector2f m_pos;
    sf::Texture m_playerTexture;
    sf::SoundBuffer buffer;
    sf::Sound ShotSound;
    steady_clock::time_point lastShotTime;
    duration<float> timeBetweenShots = 0.45s;

};



#endif //PLAYER_H
