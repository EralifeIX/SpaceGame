#include "../include/Bullet.h"

#include "../include/Menu.h"
#include "../include/ObjectConstructor.h"
#include "../include/Player.h"

Bullet::Bullet(sf::Vector2f spawnpos)
{
    if(std::rand() % 2){
        if(!m_texture.loadFromFile("../assets/bullet.png"))
            std::cerr<<"Bullet texture is absent";
}
    else{
        if(!m_texture.loadFromFile("../assets/bullet2.png"))
            std::cerr<<"Bullet texture is absent";
        }

    m_position = {spawnpos.x + 100, spawnpos. y};
    timeAlive = 0;
}
//may be custom bullets, wich will react to events
void Bullet::Update(sf::Event event, const float& frametime)
{

    m_position.x += bulletSpeed * frametime;
    if(timeAlive <= 1.65)
        timeAlive += frametime;
    else
        Terminate();
    isCollision();
}

void Bullet::Render(const std::shared_ptr<Window> window)
{
    sf::Sprite sprite(m_texture);
    sprite.setScale(6,8);
    sprite.rotate(90);
    sprite.setPosition(m_position);
    window->Draw(sprite);
}

sf::Vector2f Bullet::getPosition()
{
    return m_position;
}

void Bullet::isCollision() {

    for(const std::shared_ptr<GameObject>& object : OC->GetObjects())
    {   //distance is hypotenuse
        sf::Vector2f targetPos = object->getPosition();
        float distance = sqrt(pow(m_position.x - targetPos.x, 2) + pow(m_position.y - targetPos.y, 2));
        if(distance == 0) // catch self-destroy
            continue;
        if(distance <= 99)
        {
            object->Terminate();
            Terminate();
            OC->GetMenu()->AddScore();
        }
    }
}

void Bullet::SetOC(ObjectConstructor* oc)
{
    OC = oc;
}

bool Bullet::IsDone()
{
    return terminated;
}
void Bullet::Terminate()
{
    terminated = true;
}












