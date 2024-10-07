#include <iostream>
#include <thread>
#include <chrono>
#include "../RegularGame/include/ObjectConstructor.h"
#include "../RegularGame/include/Player.h"
#include "../RegularGame/include/Bullet.h"
#include "include/Menu.h"

int main()
{
    ObjectConstructor objects;
    constexpr unsigned int frameTime = 130;
    const std::chrono::milliseconds frameDuration(frameTime);
    sf::Clock EnemySpawnClock;
    sf::Time EnemySpawnDuration = sf::seconds(1.5f);

    while (!objects.GetWindow()->IsDone() && !objects.IsGame())
    {
        sf::Event event;
        objects.GetWindow()->GetRenderWindow().pollEvent(event);
        objects.GetWindow()->Update();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                objects.GetMenu()->Switch();

        if (event.type == sf::Event::Closed)
            objects.GetWindow()->Done();

        // Pause menu if Esc is pressed
        while(objects.GetMenu()->IsPaused())
        {
            std::this_thread::sleep_for(frameDuration);
            sf::Event event;
            objects.GetWindow()->GetRenderWindow().pollEvent(event);
            objects.GetWindow()->Update();

            if (event.type == sf::Event::Closed){
                objects.GetWindow()->Done();
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    objects.GetMenu()->Switch();

            objects.GetMenu()->Update();
            objects.GetWindow()->GetRenderWindow().display();
        }

        if(EnemySpawnClock.getElapsedTime() >= EnemySpawnDuration)
        {
            objects.SpawnEnemy();
            EnemySpawnClock.restart();
        }

        for (auto& gameObject : objects.GetObjects())
        {
            gameObject->Update(event, 0.15);
            gameObject->Render(objects.GetWindow());
        }
        objects.GetMenu()->Update();
        objects.RemoveTerminated();
        objects.GetWindow()->GetRenderWindow().display();

        std::this_thread::sleep_for(frameDuration);
    }
    std::cout << "Game Over";
    objects.GetWindow()->GetRenderWindow().close();
    return 0;
}
