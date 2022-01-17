#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape Crc3;
    Crc3.setRadius(60);
    Crc3.setPointCount(6);
    Crc3.setOutlineColor(sf::Color(128, 0, 128));
    Crc3.setOutlineThickness(5);//толщина границы 
    Crc3.setPosition(380, 40);
    Crc3.setFillColor(sf::Color(175, 238, 238));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Crc3);
        window.display();
    }
    return 0;
}
