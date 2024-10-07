#ifndef WINDOW_H
#define WINDOW_H

#include "Graphics.hpp"
#include <string>

class Window {
public:
    Window();
    Window(const std::string& w_title, const sf::Vector2u& w_size);
    Window(const Window& w);
    ~Window();

    void BeginDraw();
    void EndDraw();

    void Update();

    bool IsDone();
    void Done();
    bool IsFullScreen();
    sf::Vector2u GetWindowSize();
    sf::RenderWindow& GetRenderWindow();

    void ToggleFullscreen();

    void Draw(const sf::Drawable& w_drawable);
private:
    void Setup(const std::string& w_title, const sf::Vector2u& w_size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Texture m_background;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone = false;
    bool m_isFullscreen = false;

};



#endif //WINDOW_H
