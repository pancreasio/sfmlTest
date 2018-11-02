#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

int main()
{
	int screenwidth = 800, screenheight = 600;
	sf::RenderWindow window(sf::VideoMode(screenwidth, screenheight), "P.O.N.G.");
	sf::RectangleShape p1({20.0f,100.0f});
	sf::RectangleShape p2({ 20.0f,100.0f });
	p1.setFillColor(sf::Color::Blue);
	p2.setFillColor(sf::Color::Red);

	p1.setPosition({10.0f, screenheight /2});

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(p1);
		window.display();
	}

	return 0;
}