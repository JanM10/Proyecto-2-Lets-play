#include "Ball.h"

Ball::Ball(float radius) : dragged(false), mass(radius * 20.f), circleShape(sf::CircleShape(radius)) {
	circleShape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	circleShape.setOrigin(radius, radius);
}

Ball::~Ball() {}

void Ball::update(float deltatime) {
	setAcceleration(-getVelocity().x * 0.9f * deltatime, -getVelocity().y * 0.9f * deltatime);
	setVelocity(getVelocity().x + (getAcceleration().x), getVelocity().y + (getAcceleration().y));

	circleShape.move(getVelocity());

	if (getVelocity().x <= 0.01 && getVelocity().y <= 0.01)
	{
		//cout << "Se detuvo" << endl;
		setLado(0);
	}

	//Porteria izquierda
	if (getPosition().x >= 60 + getRadius() && getPosition().x <= 120 + getRadius() &&
		getPosition().y >= 330 - getRadius() && getPosition().y <= 480 - getRadius()) {
		int gol = 1;
		setLado(gol);
		setPosition(700, 400);
		setVelocity(0, 0);
	}
	//Porteria derecha
	else if (getPosition().x >= 1200 + getRadius() && getPosition().x <= 1260 + getRadius() && getPosition().y >= 300 - getRadius() && getPosition().y <= 480 - getRadius()) {
		int gol = 2;
		setLado(gol);
		setPosition(700, 400);
		setVelocity(0, 0);
	}


	if (getPosition().x < 120 + getRadius()) {
		setPosition(120 + getRadius(), getPosition().y);
		setVelocity(-getVelocity().x, getVelocity().y);
	}
	else if (getPosition().x > 1260 - getRadius()) {
		setPosition(1260 - getRadius(), getPosition().y);
		setVelocity(-getVelocity().x, getVelocity().y);
	}

	if (getPosition().y < 120 + getRadius()) {
		setPosition(getPosition().x, 120 + getRadius());
		setVelocity(getVelocity().x, -getVelocity().y);
	}
	else if (getPosition().y > 660 - getRadius()) {
		setPosition(getPosition().x, 660 - getRadius());
		setVelocity(getVelocity().x, -getVelocity().y);
	}
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(circleShape);
}

void Ball::setPosition(float x, float y) {
	this->circleShape.setPosition(sf::Vector2f(x, y));
}

float Ball::getRadius() const {
	return circleShape.getRadius();
}

sf::Vector2f Ball::getPosition() const {
	return circleShape.getPosition();
}

int Ball::getLado() const
{
	return lado;
}

void Ball::setLado(int gol)
{
	lado = gol;
}

void Ball::setVelocity(float x, float y) {
	this->velocity = sf::Vector2f(x, y);
}

void Ball::setAcceleration(float x, float y) {
	this->acceleration = sf::Vector2f(x, y);
}

void Ball::setDragged(bool dragged) {
	this->dragged = dragged;
}

float Ball::getMass() const {
	return mass;
}

float Ball::getDragged() const {
	return dragged;
}

sf::Vector2f Ball::getVelocity() const {
	return velocity;
}

sf::Vector2f Ball::getAcceleration() const {
	return acceleration;
}
