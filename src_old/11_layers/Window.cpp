#include "Window.hpp"
#include <iostream>
#define P(s) std::cout<<s<<std::endl;
Window::Window(const std::string& windowName) : window(sf::VideoMode(1920, 1080), windowName, sf::Style::Titlebar)
{
    window.setVerticalSyncEnabled(true);
}

void Window::Update()
{
    sf::Event event;
    if (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Window::BeginDraw()
{
    window.clear(sf::Color::Transparent);
}

void Window::Draw(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::EndDraw()
{
    window.display();
}

sf::Vector2u Window::GetCentre() const
{
    sf::Vector2u size = window.getSize();
    P("x:" << size.x * 0.5 << "::y:" << size.y * 0.5)
    return sf::Vector2u(size.x * 0.5, size.y * 0.5);
}

bool Window::IsOpen() const
{
    return window.isOpen();
}

sf::FloatRect Window::GetViewSpace() const  {

    sf::Vector2f viewCenter(window.getView().getCenter());
    sf::Vector2f viewSize(window.getView().getSize());
    sf::Vector2f viewSizeHalf(viewSize.x / 2, viewSize.y / 2);
    sf::FloatRect viewSpace(viewCenter - viewSizeHalf, viewSize);
    
    return viewSpace;
}