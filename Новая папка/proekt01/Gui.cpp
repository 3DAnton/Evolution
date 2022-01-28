#include <SFML/Graphics.hpp>
#include "Gui.h"





void draw(std::vector<std::vector<Object::ObjectType>> result)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");     ///  поле
    sf::CircleShape Crc1;

    int x = 0, y = 0, k = 0;


    Crc1.setRadius(30);                                 ///  радиус
    Crc1.setPointCount(6);                              ///  граница
    Crc1.setOutlineColor(sf::Color(70, 70, 70));        ///  цвет гр    /* поле */
    Crc1.setOutlineThickness(5);                        ///  толщина границы 
    Crc1.setFillColor(sf::Color(120, 120, 120));        ///  цвет внутри

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[0].size(); j++)
            {
                if (result[i][j] == Object::ObjectType::NUN)
                    Crc1.setFillColor(sf::Color(70, 120, 120));
                if (result[i][j] == Object::ObjectType::VOID)
                    Crc1.setFillColor(sf::Color(70, 120, 20));
                if (result[i][j] == Object::ObjectType::BOT)
                    Crc1.setFillColor(sf::Color(70, 120, 20));
                if (result[i][j] == Object::ObjectType::FOOD)
                    Crc1.setFillColor(sf::Color(70, 120, 120));
                if (result[i][j] == Object::ObjectType::POISON)
                    Crc1.setFillColor(sf::Color(70, 120, 120));
                if (result[i][j] == Object::ObjectType::WALL)
                    Crc1.setFillColor(sf::Color(70, 0, 120)); //???
                if (i % 2 == 1)
                    x = j * 59 + 30;

                if (i % 2 == 0)
                    x = j * 59;

                Crc1.setPosition(x, y);
                window.draw(Crc1);
            }
            y = i * 50;
            Crc1.setFillColor(sf::Color(120, 120, 120));
        }
        window.display();
    }

};

Gui::Gui() {};
Gui::~Gui() {};
