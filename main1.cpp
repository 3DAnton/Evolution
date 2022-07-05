#include "Gui.h";
#include "Map.h";
#include "God.h";
#include "sas.hpp";
#include "windows.h"
#include <SFML/Graphics.hpp>

#include <filesystem>
#include <iostream>

#include <thread>

void first_message(WorldSize* w)
{
	std::cout << "How much world?" << std::endl;
	std::cin >> w->x >> w->y;
	std::cout << "How much bot?" << std::endl;
	std::cin >> w->amount_bot;
	std::cout << "How much poison?" << std::endl;
	std::cin >> w->amount_poison;
	std::cout << "How much food?" << std::endl;
	std::cin >> w->amount_food;
	std::cout << "How much wall?" << std::endl;
	std::cin >> w->amount_wall;
	std::cout << "How mauch bot to evolue?" << std::endl;
	std::cin >> w->amount_boot_evolue;
	std::cout << std::endl;
	std::cout << "Need to cordinates(1-Yes,0-No)"<<std::endl;
	std::cin >> w->need_to_cordinat;

}

void reading_keyboard(sf::Event event, std::string& s,bool&vod_1,bool& vod_2,int& x)
{
	
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Key::Enter:
		{
			vod_1 = false;
			vod_2 = true;
			break;
		}
		case (sf::Keyboard::Key::Num0):
		{
			s.push_back('0');
			x = x * 10;
			break;
		}
		case sf::Keyboard::Key::Num1:
		{
			s.push_back('1');
			x = x * 10 + 1;
			break;
		}
		case sf::Keyboard::Key::Num2:
		{
			s.push_back('2');
			x = x * 10 + 2;
			break;
		}
		case sf::Keyboard::Key::Num3:
		{
			s.push_back('3');
			x = x * 10 + 3;
			break;
		}
		case sf::Keyboard::Key::Num4:
		{
			s.push_back('4');
			x = x * 10 + 4;
			break;
		}
		case sf::Keyboard::Key::Num5:
		{
			s.push_back('5');
			x = x * 10 + 5;
			break;
		}
		case sf::Keyboard::Key::Num6:
		{
			s.push_back('6');
			x = x * 10 + 6;
			break;
		}
		case sf::Keyboard::Key::Num7:
		{
			s.push_back('7');
			x = x * 10 + 7;
			break;
		}
		case sf::Keyboard::Key::Num8:
		{
			s.push_back('8');
			x = x * 10 + 8;
			break;
		}
		case sf::Keyboard::Key::Num9:
		{
			s.push_back('9');
			x = x * 10 + 9;
			break;
		}
		case sf::Keyboard::Key::Numpad0:
		{
			s.push_back('0');
			x = x * 10;
			break;
		}
		case sf::Keyboard::Key::Numpad1:
		{
			s.push_back('1');
			x = x * 10 + 1;
			break;
		}
		case sf::Keyboard::Key::Numpad2:
		{
			s.push_back('2');
			x = x * 10 + 2;
			break;
		}
		case sf::Keyboard::Key::Numpad3:
		{
			s.push_back('3');
			x = x * 10 + 3;
			break;
		}
		case sf::Keyboard::Key::Numpad4:
		{
			s.push_back('4');
			x = x * 10 + 4;
			break;
		}
		case sf::Keyboard::Key::Numpad5:
		{
			s.push_back('5');
			x = x * 10 + 5;
			break;
		}
		case sf::Keyboard::Key::Numpad6:
		{
			s.push_back('6');
			x = x * 10 + 6;
			break;
		}
		case sf::Keyboard::Key::Numpad7:
		{
			s.push_back('7');
			x = x * 10 + 7;
			break;
		}
		case sf::Keyboard::Key::Numpad8:
		{
			s.push_back('8');
			x = x * 10 + 8;
			break;
		}
		case sf::Keyboard::Key::Numpad9:
		{
			s.push_back('9');
			x = x * 10 + 9;
			break;
		}
		case sf::Keyboard::Key::BackSpace:
		{
			s.erase(s.size()-1);
			x = x / 10;
			break;
		}
		}
	}
}

int first_reading(WorldSize* w)
{
	bool vod_x = true, vod_y = false, vod_bot = false, vod_food = false;
	bool vod_poison=false,vod_wall=false;
	bool vod_bot_need_evoule = false,vod_cord=false;
	sf::RenderWindow first_mes(sf::VideoMode(1920, 1080), "My window");
	sf::Event event;

	sf::Font font;//רנטפע 

	if (!font.loadFromFile("111.ttf"))
	{
		std::cout << "Font load error!\n";
	}
	std::string s_x,s_y,s_b,s_f,s_p,s_w,s_m,s_cord;
	while (first_mes.isOpen())
	{
		sf::Event event;
		while ((vod_x)&&(first_mes.pollEvent(event)))
		{
			
			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				w->need_to_error = true;
				break;
			}
			else 
				reading_keyboard(event, s_x, vod_x, vod_y, w->x);
			//std::cout << (w->x)<<std::endl;
			first_mes.clear();
			sf::Text text_x(s_x, font, 20);
			sf::Text text_1("How much world?", font, 20);
			text_1.setPosition(0,0);
			text_x.setPosition(0,20);
			first_mes.draw(text_1);
			first_mes.draw(text_x);
			first_mes.display();
		}

		while ((vod_y) && (first_mes.pollEvent(event)))
		{
			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_y = false;
				w->need_to_error = true;
			}
			else
				reading_keyboard(event, s_y, vod_y, vod_bot, w->y);
			//std::cout << (w->y) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.display();
		}
	
		while ((vod_bot) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_bot = false;
				w->need_to_error = true;
			}
			else
				reading_keyboard(event, s_b, vod_bot, vod_food, w->amount_bot);
			//std::cout << (w->amount_bot) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_bot(s_b, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_bot.setPosition(0, 80);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_bot);
			first_mes.display();
		}
		while ((vod_food) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_food = false;
				w->need_to_error = true;
			}
			else
				reading_keyboard(event, s_f, vod_food, vod_poison, w->amount_food);
			//std::cout << (w->amount_food) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_b(s_b, font, 20);
			sf::Text text_3("How much food?", font, 20);
			sf::Text text_f(s_f, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_b.setPosition(0, 80);
			text_3.setPosition(0, 100);;
			text_f.setPosition(0, 120);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_b);
			first_mes.draw(text_3);
			first_mes.draw(text_f);
			first_mes.display();
		}
		while ((vod_poison) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_poison = false;
				w->need_to_error = true;
			}
			else
				reading_keyboard(event, s_p, vod_poison, vod_wall, w->amount_poison);
			//std::cout << (w->amount_poison) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_b(s_b, font, 20);
			sf::Text text_3("How much food?", font, 20);
			sf::Text text_f(s_f, font, 20);
			sf::Text text_4("How much poison?", font, 20);
			sf::Text text_p(s_p, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_b.setPosition(0, 80);
			text_3.setPosition(0, 100);;
			text_f.setPosition(0, 120);
			text_4.setPosition(0, 140);
			text_p.setPosition(0, 160);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_b);
			first_mes.draw(text_3);
			first_mes.draw(text_f);
			first_mes.draw(text_4);
			first_mes.draw(text_p);
			first_mes.display();
		}
		while ((vod_wall) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_wall = false;
				w->need_to_error = true;
			}
			else
				reading_keyboard(event, s_w, vod_wall, vod_cord, w->amount_wall);
			//std::cout << (w->amount_wall) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_b(s_b, font, 20);
			sf::Text text_3("How much food?", font, 20);
			sf::Text text_f(s_f, font, 20);
			sf::Text text_4("How much poison?", font, 20);
			sf::Text text_p(s_p, font, 20);
			sf::Text text_5("How much wall?", font, 20);
			sf::Text text_w(s_w, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_b.setPosition(0, 80);
			text_3.setPosition(0, 100);;
			text_f.setPosition(0, 120);
			text_4.setPosition(0, 140);
			text_p.setPosition(0, 160);
			text_5.setPosition(0, 180);
			text_w.setPosition(0, 200);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_b);
			first_mes.draw(text_3);
			first_mes.draw(text_f);
			first_mes.draw(text_4);
			first_mes.draw(text_p);
			first_mes.draw(text_5);
			first_mes.draw(text_w);
			first_mes.display();
		}
		while ((vod_cord) && (first_mes.pollEvent(event)))
		{
			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_cord = false;
				w->need_to_error = true;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Key::Enter)
				{
					vod_cord = false;
					vod_bot_need_evoule = true;
				}
				if (event.key.code == sf::Keyboard::Key::Num0)
				{
					w->need_to_cordinat = false;
					s_cord.push_back('0');
				}
				if (event.key.code == sf::Keyboard::Key::Num1)
				{
					w->need_to_cordinat = true;
					s_cord.push_back('1');
				}
			}
				//std::cout << (w->need_to_cordinat) << std::endl;
				first_mes.clear();
				sf::Text text("How much world?", font, 20);
				sf::Text text_x(s_x, font, 20);
				sf::Text text_y(s_y, font, 20);
				sf::Text text_2("How much bot?", font, 20);
				sf::Text text_b(s_b, font, 20);
				sf::Text text_3("How much food?", font, 20);
				sf::Text text_f(s_f, font, 20);
				sf::Text text_4("How much poison?", font, 20);
				sf::Text text_p(s_p, font, 20);
				sf::Text text_5("How much wall?", font, 20);
				sf::Text text_w(s_w, font, 20);
				sf::Text text_6("Need to cordinates(1 - Yes, 0 - No)", font, 20);
				sf::Text text_cord(s_cord, font, 20);
				text.setPosition(0, 0);
				text_x.setPosition(0, 20);
				text_y.setPosition(0, 40);
				text_2.setPosition(0, 60);
				text_b.setPosition(0, 80);
				text_3.setPosition(0, 100);;
				text_f.setPosition(0, 120);
				text_4.setPosition(0, 140);
				text_p.setPosition(0, 160);
				text_5.setPosition(0, 180);
				text_w.setPosition(0, 200);
				text_6.setPosition(0, 220);
				text_cord.setPosition(0, 240);
				first_mes.draw(text);
				first_mes.draw(text_x);
				first_mes.draw(text_y);
				first_mes.draw(text_2);
				first_mes.draw(text_b);
				first_mes.draw(text_3);
				first_mes.draw(text_f);
				first_mes.draw(text_4);
				first_mes.draw(text_p);
				first_mes.draw(text_5);
				first_mes.draw(text_w);
				first_mes.draw(text_6);
				first_mes.draw(text_cord);

				first_mes.display();
		}
		while ((vod_bot_need_evoule) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_bot_need_evoule = false;
				w->need_to_error = true;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Key::Enter)
				{
					vod_bot_need_evoule = false;
					first_mes.close();
					w->need_to_error = false;
					return 1;
				}
				else
				{
					bool q1 = true, q2 = true;
					reading_keyboard(event, s_m, q1, q2, w->amount_boot_evolue);
					
				}
			}
			//std::cout << (w->amount_wall) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_b(s_b, font, 20);
			sf::Text text_3("How much food?", font, 20);
			sf::Text text_f(s_f, font, 20);
			sf::Text text_4("How much poison?", font, 20);
			sf::Text text_p(s_p, font, 20);
			sf::Text text_5("How much wall?", font, 20);
			sf::Text text_w(s_w, font, 20);
			sf::Text text_6("Need to cordinates(1 - Yes, 0 - No)", font, 20);
			sf::Text text_cord(s_cord, font, 20);
			sf::Text text_7("How much boot need to evolue?", font, 20);
			sf::Text text_m(s_m, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_b.setPosition(0, 80);
			text_3.setPosition(0, 100);;
			text_f.setPosition(0, 120);
			text_4.setPosition(0, 140);
			text_p.setPosition(0, 160);
			text_5.setPosition(0, 180);
			text_w.setPosition(0, 200);
			text_6.setPosition(0, 220);
			text_cord.setPosition(0, 240);
			text_7.setPosition(0, 260);
			text_m.setPosition(0, 280);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_b);
			first_mes.draw(text_3);
			first_mes.draw(text_f);
			first_mes.draw(text_4);
			first_mes.draw(text_p);
			first_mes.draw(text_5);
			first_mes.draw(text_w);
			first_mes.draw(text_6);
			first_mes.draw(text_cord);
			first_mes.draw(text_7);
			first_mes.draw(text_m);
			first_mes.display();
		}
		
		
	}
	return 1;
}


int main()
{
	
	WorldSize w;
	
	//if(!(w.otkladka)) first_message(&w);
	if(!(w.otkladka)) first_reading(&w);
	int s1 = ((w.x) - 1) * ((w.y) - 1), s2 = (w.amount_bot) + (w.amount_food) + (w.amount_poison) + (w.amount_wall);
	if (s1 < s2)
	{
		std::cout << "Map is crowded";
		return 1;
	}
	if (w.need_to_error)
	{
		std::cout << "ERROR";
		return 0;
	}

    God g(&w);
	g.run_2(&w);
}