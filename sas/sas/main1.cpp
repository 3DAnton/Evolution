#include <SFML/Graphics.hpp>

#include <vector>

//#include "Map.h"
//#include "Object.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");     ///  поле
    sf::CircleShape Crc1;

    int x = 0, y = 0;

    Crc1.setRadius(45);                                                    ///  радиус
    Crc1.setPointCount(6);                                                 ///  граница
    Crc1.setOutlineColor(sf::Color(245, 245, 245));                           ///  цвет гр
    Crc1.setOutlineThickness(5);                                           ///  толщина границы 
    Crc1.setFillColor(sf::Color(120, 120, 120));                           ///  цвет внутри


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < 14; i++) {
            for (int j = 0; j < 22; j++)
            {
                if (i % 2 == 0)
                {
                    x = j * 85 + 40;
                }
                else
                {
                    x = j * 85;
                }
                Crc1.setPosition(x, y);
                window.draw(Crc1);
            }
            y = i * 67;
        }
        window.display();
    }

    /*
    Map m;
    const std::vector<std::vector<Object*>> aaaa= m.getPresentation();
    aaaa[7][8]->m = 7;
    */
    return 0;

}