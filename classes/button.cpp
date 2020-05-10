/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** button.cpp
*/

#include "button.hpp"

void Button::check_pressed(sf::Vector2f pos)
{
    if (this->shape.getGlobalBounds().contains(pos)) {
        press = 1;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            press = 2;
    }
    else
        press = 0;

}

Button::Button(float x, float y, float width, float height,
               std::string string_text)
{
    this->shape.setOrigin(width / 2, height / 2);
    this->font.loadFromFile("assets/font3.ttf");
    this->text.setFont(font);
    this->text.setString(string_text);
    this->text.setCharacterSize(int(height));
    this->text.setFillColor(sf::Color::White);     /*
        this->shape.getPosition().x / 2.f - this->text.getGlobalBounds()
        .width / 2.f,
        this->shape.getPosition().y / 2.f - this->text.getGlobalBounds()
        .height / 2.f
        );*/
    this->text.setOrigin(this->text.getGlobalBounds().width / 2.f, height / 1.5);
    this->text.setPosition(x, y);
    this->shape.setSize(sf::Vector2f (width, height));
    this->shape.setPosition(x, y);
    this->shape.setFillColor(this->backgrounds[press]);
}

void Button::update(sf::RenderWindow *window)
{
    this->check_pressed((sf::Vector2f(sf::Mouse::getPosition().x,
        sf::Mouse::getPosition().y - 55)));
    this->shape.setFillColor(this->backgrounds[press]);
    window->draw(this->shape);
    window->draw(this->text);
}

bool Button::is_pressed() const
{
    return press == 2;
}
