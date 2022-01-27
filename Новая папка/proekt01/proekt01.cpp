#include "Map.h"
#include "object.h"

#include <SFML/Graphics.hpp>




int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");     ///  поле
    sf::CircleShape Crc1;
    sf::CircleShape Crc2;
    sf::CircleShape Crc3;

    int x = 0, y = 0, k = 0;
   

        Crc1.setRadius(30);                                                    ///  радиус
        Crc1.setPointCount(6);                                                 ///  граница
        Crc1.setOutlineColor(sf::Color(70, 70, 70));                           ///  цвет гр           /* поле */
        Crc1.setOutlineThickness(5);                                           ///  толщина границы 
        Crc1.setFillColor(sf::Color(120,120,120));                             ///  цвет внутри
    
        Crc2.setRadius(20);                                                    ///  радиус
        Crc2.setPointCount(60);                                                ///  граница           /* еда */
        Crc2.setFillColor(sf::Color(30, 160, 20));                             ///  цвет внутри

        Crc3.setRadius(40);                                                    ///  радиус
        Crc3.setPointCount(4);                                                 ///  граница           /* враг */
        Crc3.setFillColor(sf::Color(130, 30, 20));                             ///  цвет внутри
        

        
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) 
                    window.close();
            }

            window.clear();
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 32; j++)
                {
                    if (i % 2 == 1)
                        x = j  * 59 + 30;
                    
                   if (i % 2 == 0)
                        x = j * 59;
                    
                    Crc1.setPosition(x, y);
                    window.draw(Crc1);
                }
                y = i  * 50;
                            }
            window.display();
        }

    return 0;
}



       