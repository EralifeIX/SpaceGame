
#include "../include/Enemy.h"


Enemy::Enemy()
{
    int random = std::rand() % 3;
    switch (random)
    {
    case 0:
        {
            if(!m_texture.loadFromFile("../assets/enemy1.png"))
                std::cerr << "Enemy texture is missing";
            SetRandomPos();
            enemySpeed = 150;
            break;
        }
    case 1:
        {
            if(!m_texture.loadFromFile("../assets/enemy2.png"))
                std::cerr << "Enemy texture is missing";
            SetRandomPos();
            enemySpeed = 100;
            break;
        }
    case 2:
        {
            if(!m_texture.loadFromFile("../assets/enemy3.png"))
                std::cerr << "Enemy texture is missing";
            SetRandomPos();
            enemySpeed = 200;
            break;
        }
    }
}

void Enemy::Update(sf::Event event, const float& frametime)
{
    m_position.x -= enemySpeed * frametime;
    if(m_position.x <= 250)
        OC->GameOver(); //Player terminated, Game Over
}
void Enemy::Render(const std::shared_ptr<Window> window)
{
    sf::Sprite sprite(m_texture);
    sprite.setScale(6,7);
    sprite.rotate(90);
    sprite.setPosition(m_position);
    window->Draw(sprite);
}


void Enemy::SetRandomPos()
{
    int random = std::rand() % 5;
    switch (random)
    {
    case 0:{
            m_position = sf::Vector2f(1200, 150);
            break;
        }
    case 1:{
            m_position = sf::Vector2f(1200, 250);
            break;
        }
    case 2:{
            m_position = sf::Vector2f(1200, 350);
            break;
        }
    case 3:{
            m_position = sf::Vector2f(1200, 450);
            break;
        }
    case 4:{
            m_position = sf::Vector2f(1200, 550);
            break;
        }
    }
}

sf::Vector2f Enemy::getPosition()
{
    return m_position;
}

void Enemy::Terminate()
{
    terminated = true;
}

bool Enemy::IsDone()
{
    return terminated;
}

void Enemy::SetOC(ObjectConstructor* oc)
{
    OC = oc;
}

