/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** button.hpp
*/

#include "../include/all_includes.h"
#ifndef SNAKE_SFML_BUTTON_HPP

#define SNAKE_SFML_BUTTON_HPP

class Button
{
private:
    sf::Font font;
    sf::Text text;
    sf::Color backgrounds[3] = {sf::Color(0, 100, 0), sf::Color(34, 139, 34),
                                sf::Color(255, 165, 0)};
    int press = 0;

public:
    sf::RectangleShape shape;
    explicit Button(float x, float y, float width, float hight, std::string
    string_text);
    void check_pressed(sf::Vector2f pos);
    bool is_pressed() const;
    void update(sf::RenderWindow *window);
};

#endif //SNAKE_SFML_BUTTON_HPP
