
#include "../include/Window.h"

//Constructors
Window::Window()
{
    Setup("Window", sf::Vector2u(720,1280));
}

Window::Window(const std::string& w_title, const sf::Vector2u& w_size)
{
    Setup(w_title,w_size);
}

Window::Window(const Window& w)
{
    Setup(w.m_windowTitle,w.m_windowSize);
}

Window::~Window(){ Destroy(); }



void Window::Setup(const std::string& w_title, const sf::Vector2u& w_size)
{
    m_background.loadFromFile("../assets/background.png");
    m_windowTitle = w_title;
    m_windowSize = w_size;
    m_isFullscreen = false;
    m_isDone = false;
    Create();
}


void Window::Create()
{
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
}

void Window::Destroy()
{
    m_window.close();
}

void Window::Update()
{
    m_window.clear();
    sf::Event event;
    sf::Sprite sprite(m_background);
    sprite.setScale(20,11.25);
    m_window.draw(sprite);


    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            m_isDone = true;
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
            ToggleFullscreen();
    }

}



//switch screen mode to Full or Reverse it
void Window::ToggleFullscreen()
{
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::BeginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::EndDraw()
{
    m_window.display();
}

void Window::Draw(const sf::Drawable& w_drawable){
    m_window.draw(w_drawable);
}


bool Window::IsDone(){ return m_isDone; }
void Window::Done() { m_isDone = true; }
bool Window::IsFullScreen(){ return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize(){ return m_windowSize; }
sf::RenderWindow& Window::GetRenderWindow() { return m_window; };











