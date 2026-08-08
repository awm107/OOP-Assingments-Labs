#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace std;
using namespace sf;

int main() {
	RenderWindow window(VideoMode(1000, 600), "PACMAN");
	window.setFramerateLimit(60);

	sf::Texture sting;
	//sting.loadFromFile("C:\\Users\\user\\Downloads.png");
	const sf::Texture* copy = &sting;
	/*sf::Sprite */
	sf::CircleShape pac(15.f);
	pac.setTexture(copy);
	sf::Vector2f pos(200, 200);
	pos.x = 300;
	pos.y = 300;

	char original[15][26] = {
		"aaaaaaaaaaaaaaaaaaaaaaaaa",
		"a22222222222222222222222a",
		"a2aaaaaaaa2aaaaaaa2aaaa2a",
		"a2a2222222222222222222a2a",
		"a2aaaaaaaa2aaaaaaa2aaaa2a",
		"a22222222222222222222222a",
		"a2aaaaaa22222222aaaaaaaaa",
		"2222222222222222222222222",
		"a2aaa22aaaaa3aaaa22aaa2aa",
		"a2aaa22aaa 014 a22aaa22aa",
		"a2aaa22aaaaaaaaaa22aaa22a",
		"a22222222222222222222222a",
		"a2aaaaaaaa2aaaaaaa2aaaa2a",
		"a2a2222222222222222222a2a",
		"aaaaaaaaaaaaaaaaaaaaaaaaa"
	};

	char map[15][26];
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 26; j++) {
			map[i][j] = original[i][j];
		}
	}
	sf::Texture walls;
	walls.loadFromFile("C:\\Users\\user\\Downloads\\maze.png");
	sf::Sprite wall;
	wall.setTexture(walls);

	sf::Texture pellet;
	pellet.loadFromFile("C:\\Users\\user\\Downloads\\white.png");
	sf::Sprite food;
	food.setTexture(pellet);

	//food.setScale(sf::Vector2f(10.f, 10.f));
	

	sf::Texture Inky;
	Inky.loadFromFile("C:\\Users\\user\\Downloads\\inky.jfif");
	sf::Sprite ghosts;
	ghosts.setTexture(Inky);

	sf::Texture Blinky;
	Blinky.loadFromFile("C:\\Users\\user\\Downloads\\blinkkkyy.png");
	sf::Sprite ghosts1;
	ghosts1.setTexture(Blinky);

	sf::Texture Pinky;
	Pinky.loadFromFile("C:\\Users\\user\\Downloads\\pinky.png");
	sf::Sprite ghosts2;
	ghosts2.setTexture(Pinky);

	sf::Texture Clyde;
	Clyde.loadFromFile("C:\\Users\\user\\Downloads\\clyde.png");
	sf::Sprite ghosts3;
	ghosts3.setTexture(Clyde);



	pac.setPosition(pos);
	pac.setFillColor(sf::Color::Yellow);

	float Xvelocity = 0;
	float Yvelocity = 0;


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			
				
				Yvelocity = -2;
				Xvelocity = 0;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			Yvelocity = +2;
			Xvelocity = 0;
		}if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			Yvelocity = 0;
			Xvelocity = +2;
		}if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			Yvelocity = 0;
			Xvelocity = -2;
		}
		if (pos.x < 0 || pos.x>1000 - 100) Xvelocity  *= -1;
		{
			if (pos.y < 0 || pos.y> 600 - 90) Yvelocity *= -1;
			{
				pos.x += Xvelocity;
				pos.y += Yvelocity;
			}
		}
		pac.setPosition(pos);
		window.clear();

		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (map[i][j] == 'a') {
					wall.setPosition(j * 40, i * 40);
					window.draw(wall);
				}
				if (map[i][j] == '2')
				{
					food.setPosition(j * 40 +13, i * 40 + 12);
					window.draw(food);
				}
				if (map[i][j] == '0')
				{
					ghosts.setPosition(j * 40, i * 40);
					window.draw(ghosts);
				}
				if (map[i][j] == '1')
				{
					ghosts1.setPosition(j * 40, i * 40);
					window.draw(ghosts1);
				}
				if (map[i][j] == '4')
				{
					ghosts2.setPosition(j * 40, i * 40);
					window.draw(ghosts2);
				}
				if (map[i][j] == '3')
				{
					ghosts3.setPosition(j * 40, i * 40);
					window.draw(ghosts3);
				}
			}
		}
		
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (map[i][j] == '2')
				{
					if (pos.x >= j * 40 + 13 && pos.x + 40 <= j * 40 + 12+40) {
						if (pos.y >= i * 40 + 12 && pos.y + 40 <= i * 40 + 12+40) {
							map[i][j] = ' ';
						}
					}
				}
			}
		}
		window.draw(pac);
		window.display();
	}







}