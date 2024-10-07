//
// Created by eralife on 7/7/24.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include "Window.h"
class GameObject
{
public:
    GameObject() = default;
    virtual void Update(sf::Event event, const float& frametime) = 0;
    virtual void Render(const std::shared_ptr<Window> window) = 0;
    virtual bool IsDone() = 0;
    virtual void Terminate() = 0;
    virtual sf::Vector2f getPosition() = 0;
};

#endif //GAMEOBJECT_H
