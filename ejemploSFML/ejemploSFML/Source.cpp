#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Window.hpp>

int main()
{
	int screenwidth = 800, screenheight = 600;
	sf::RenderWindow window(sf::VideoMode(screenwidth, screenheight), "P.O.N.G.");
	sf::RectangleShape p1({20.0f,100.0f});
	sf::RectangleShape p2({ 20.0f,100.0f });
	sf::Keyboard dInput;
	sf::Vector2f p1pos;
	sf::Vector2f p2pos;
	sf::Clock clock;

	float pSpeed = 250.0f;

	p1.setFillColor(sf::Color::Blue);
	p2.setFillColor(sf::Color::Red);

	p1pos ={10.0f,(float)screenheight /2};
	p2pos ={(float)screenwidth - 30.0f,(float)screenheight / 2 };

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (dInput.isKeyPressed(dInput.W)) {
			p1pos.y -= pSpeed * elapsed.asSeconds();
		}
		if (dInput.isKeyPressed(dInput.S)) {
			p1pos.y += pSpeed * elapsed.asSeconds();
		}
		if (dInput.isKeyPressed(dInput.Up)) {
			p2pos.y -= pSpeed * elapsed.asSeconds();
		}
		if (dInput.isKeyPressed(dInput.Down)) {
			p2pos.y += pSpeed * elapsed.asSeconds();
		}
		p1.setPosition(p1pos);
		p2.setPosition(p2pos);
		window.clear();
		window.draw(p1);
		window.draw(p2);
		window.display();
	}

	return 0;
}