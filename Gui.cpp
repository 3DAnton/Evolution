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
//#define SHOW_CELLS_COORDINATES    false


void Gui::draw(std::vector<std::vector<Object::ObjectType>> result ,WorldSize* w)
{
    sf::CircleShape Crc1;

    int x = 0, y = 0, k = 0;

    Crc1.setRadius(20);                                 ///  ������
    Crc1.setPointCount(6);                              ///  �������
    Crc1.setOutlineColor(sf::Color(70, 70, 70));        ///  ���� ��          /* ���� */
    Crc1.setOutlineThickness(3);                        ///  ������� ������� 
    Crc1.setFillColor(sf::Color(120, 120, 120));        ///  ���� ������

    sf::Event event;

    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                std::cout << " ASD ";
            }
        }
        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case (sf::Keyboard::Key::Z):
                {
                    bool q = w->make_a_pause;
                    w->make_a_pause = !q;
                    std::cout << "ASDASD" << std::endl;
                    break;
                }
                case (sf::Keyboard::Key::C):
                {
                    bool q = w->need_to_draw;
                    w->need_to_draw = !q;
                    std::cout << "ASDASasD" << std::endl;
                    break;
                }
                
            }
            if (event.type == sf::Event::Closed)
                mWindow.close();
            
        }
        //sf::Font font;//����� 

        //if (!font.loadFromFile("111.ttf"))
        //{
        //    std::cout << "Font load error!\n";
        //}

    }


    sf::View view1;
    mWindow.clear();

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++)
        {

                if (result[i][j] == Object::ObjectType::VOID)
                    Crc1.setFillColor(sf::Color(120, 120, 120));    //  ����� + !!!!


                if (result[i][j] == Object::ObjectType::BOT)         // ���    +
                    Crc1.setFillColor(sf::Color(250, 250, 20));


                if (result[i][j] == Object::ObjectType::FOOD)        // ���    +
                    Crc1.setFillColor(sf::Color(12, 180, 12));


                if (result[i][j] == Object::ObjectType::POISON)     // ��     
                    Crc1.setFillColor(sf::Color(250, 0, 0));


                if (result[i][j] == Object::ObjectType::WALL)        // �����
                    Crc1.setFillColor(sf::Color(70, 70, 70));


                if (result[i][j] == Object::ObjectType::NUN)         // 0
                    Crc1.setFillColor(sf::Color(0, 0, 0));



                if (i % 2 == 1)
                    x = j * 37+19 ;// +19;
                

                if (i % 2 == 0)
                    x = j * 37;
                
                Crc1.setPosition(x, y);
                mWindow.draw(Crc1);
 #ifdef SHOW_CELLS_COORDINATES
                 sf::Text text("asdfjkashjkf", font, 20);             //������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
                 text.setStyle(sf::Text::Bold);                        //������ � ������������ �����. �� ��������� �� "�����":)) � �� ������������
                 text.setFillColor(sf::Color::White);
                 text.setPosition(10, 10);                    //������ ������� ������, ����� ������

                 text.setScale(sf::Vector2f(0.5, 0.5));
                 text.setPosition(x + 10, y + 10);
                 text.setString(std::to_string(i) + " " + std::to_string(j));
                 mWindow.draw(text);
                 text.setScale(sf::Vector2f(1, 1));
#endif // SHOW_CELLS_COORDINATES
            }
            y = (i+1) * 34;
        }
        //  mWindow.draw(text);//����� ���� �����
        mWindow.display();
};

//Gui::Gui(sf::RenderWindow& aWindow) :
Gui::Gui( int x, int y) :
    mWindow(sf::VideoMode(x, y), "EvOlUtIoN")
{ };     ///  ����};
Gui::~Gui() {};