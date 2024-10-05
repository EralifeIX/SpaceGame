#include "../include/Player.h"

#include <iostream>

#include "../include/Bullet.h"
Player::Player()
{
    if(!m_playerTexture.loadFromFile("../assets/ship.png"))
        std::cerr<<"Player texture is missing";
    m_pos = sf::Vector2f(250, 340);
    lastShotTime = steady_clock::now();
    buffer.loadFromFile("../assets/shootSFX.mp3");
    ShotSound.setBuffer(buffer);

}
void Player::Update(sf::Event event, const float& frametime)
{

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_pos.y > 50 )
            m_pos.y -= speed * frametime;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_pos.y < 570 )
            m_pos.y += speed * frametime;

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShotTime + timeBetweenShots <= steady_clock::now()){
            //some shooting logic
            auto newBullet = std::make_shared<Bullet>(m_pos);
            newBullet->SetOC(OC);
            OC->AddObject(newBullet);

            ShotSound.play();
            lastShotTime = steady_clock::now();
        }

}


void Player::Render(const std::shared_ptr<Window> window)
{
    sf::Sprite sprite(m_playerTexture);
    sprite.setScale(6,8);
    sprite.rotate(90);
    sprite.setPosition(m_pos);
    window->Draw(sprite);
}

void Player::SetOC(ObjectConstructor* oc){
    OC = oc;
}

sf::Vector2f Player::getPosition()
{
    return m_pos;
}

bool Player::IsDone()
{
    return false;
}
void Player::Terminate()
{
    // Надо будет вставить анимацию поражения и GameOver
    std::cout << "Game Over";
}