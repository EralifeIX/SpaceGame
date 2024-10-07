#include "../include/ObjectConstructor.h"
#include "../include/Enemy.h"
#include "../include/Menu.h"
#include "../include/Player.h"

ObjectConstructor::ObjectConstructor()
{
    m_window = std::make_shared<Window>("Space Wars", sf::Vector2u(1280, 720));
    m_window->GetRenderWindow().setKeyRepeatEnabled(false);
    auto newPlayer = std::make_shared<Player>();
    newPlayer->SetOC(this);
    m_menu = std::make_shared<Menu>(this);
    m_game_objects.push_front(std::move(newPlayer));
}

void ObjectConstructor::GameOver(){
    terminated = true;
}
bool ObjectConstructor::IsGame(){
    return terminated;
}

std::list<std::shared_ptr<GameObject>> ObjectConstructor::GetObjects(){
    return m_game_objects;
}
void ObjectConstructor::AddObject(const std::shared_ptr<GameObject>& gameObject) {
    m_game_objects.push_front(std::move(gameObject));
}

void ObjectConstructor::RemoveTerminated(){
    m_game_objects.remove_if([](const std::shared_ptr<GameObject>& obj) { return obj->IsDone(); });
}

std::shared_ptr<Window> ObjectConstructor::GetWindow(){
    return m_window;
}

std::shared_ptr<Menu> ObjectConstructor::GetMenu(){
    return m_menu;
}

void ObjectConstructor::SpawnEnemy()
{
    auto newEnemy = std::make_shared<Enemy>();
    newEnemy->SetOC(this);
    m_game_objects.push_front(std::move(newEnemy));
}



