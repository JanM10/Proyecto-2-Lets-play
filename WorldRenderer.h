#ifndef WORLDRENDERER_H
#define WORLDRENDERER_H
#include <SFML/Graphics.hpp>
#include "World.h"
#include <iostream>

using namespace std;

class WorldRenderer {

public:
	WorldRenderer(World& world);
	~WorldRenderer();

	void render(sf::RenderWindow& ventanaPrueba) const;
	void renderBalls(sf::RenderWindow& ventanaPrueba) const;
	void getPosition(sf::RenderWindow& ventanaPrueba) const;
	int getLado(sf::RenderWindow& ventanaPrueba) const;
	void setLado(sf::RenderWindow& ventanaPrueba);

private:
	World& world;
};

#endif