#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gui.h"

#define FONT_PATH                   "Banty Bold.ttf"
#define HEXAGON_DX                  0.f
#define HEXAGON_DY                  50.f
#define TEXT_DX                     -18.f
#define TEXT_DY                     -20.f
#define TEXT_SINGLE_DX              10.f
#define HEXAGON_SIZE                25.f
#define HEXAGON_OTLINE_THICKNESS    5.f
#define SHOW_CELLS_COORDINATES

void Gui::draw(std::vector<std::vector<Object::ObjectType>> result)
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
            /*if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                case (sf::Keyboard::Key::Z):
                {
                    std::cout << "ASD";
                }
                }
            }*/
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Font font;//шрифт 
        
        if (!font.loadFromFile("font.ttf"))
        {
            std::cout << "Font load error!\n";
        }
       
        //font.loadFromFile("111.ttf");//передаем нашему шрифту файл шрифта 
        sf::Text text("asdfjkashdjkf", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
        text.setStyle(sf::Text::Bold);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
        text.setFillColor(sf::Color::White);
       // text.setPosition(10, 10);//задаем позицию текста, центр камеры
       

        window.clear();
        
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[0].size(); j++)
            {

                if (result[i][j] == Object::ObjectType::VOID)
                    Crc1.setFillColor(sf::Color(120, 120, 120));    //  пусто + !!!!


                if (result[i][j] == Object::ObjectType::BOT)       // бот    +
                    Crc1.setFillColor(sf::Color(250, 250, 20));


                if (result[i][j] == Object::ObjectType::FOOD)        // еда    +
                    Crc1.setFillColor(sf::Color(12, 180, 12));


                if (result[i][j] == Object::ObjectType::POISON)     // яд     
                    Crc1.setFillColor(sf::Color(250, 0, 0));


                if (result[i][j] == Object::ObjectType::WALL)        // стена
                    Crc1.setFillColor(sf::Color(70, 70, 70));


                if (result[i][j] == Object::ObjectType::NUN)         // 0
                    Crc1.setFillColor(sf::Color(0, 0, 0));



                if (i % 2 == 1)
                    x = j * 59 + 30;

                if (i % 2 == 0)
                    x = j * 59;

                Crc1.setPosition(x, y);
                window.draw(Crc1);
#ifdef SHOW_CELLS_COORDINATES

                text.setScale(sf::Vector2f(0.5, 0.5));
                text.setPosition(x+26,y+26);
                text.setString(std::to_string(i) + " " + std::to_string(j));
                window.draw(text);
                text.setScale(sf::Vector2f(1, 1));
#endif // SHOW_CELLS_COORDINATES
            }
            y = i * 50;
           
        }
        window.draw(text);//рисую этот текст
        window.display();
    }

};

Gui::Gui() {};
Gui::~Gui() {};
