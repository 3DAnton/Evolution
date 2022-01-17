#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape octagon(1000.f);
    sf::CircleShape shape(1000.f);
    sf::CircleShape octagon(60.f, 8);
    octagon.setPosition(380, 0);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
        window.draw(octagon); // отрисовка октагона
    }
    return 0;
}
