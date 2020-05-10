/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** textbox.cpp
*/

#include "../include/all_includes.h"
#include "textbox.hpp"

void Textbox::update(sf::RenderWindow *window)
{
    window->draw(this->text);
}

bool Textbox::set_font(std::string path)
{
    return (this->font.loadFromFile(path));
}

bool Textbox::set_text(std::string new_text)
{
    this->text.setString(new_text);
    return true;
}

Textbox::Textbox(const std::string& text_sting, unsigned int size_tmp, float x,
    float y, sf::Color
color_tmp)
{
    this->font.loadFromFile("assets/font3.ttf");
    this->text.setFont(font);
    this->color = color_tmp;
    this->text_s = text_sting;
    this->size = size_tmp;
    this->text.setString(text_sting);
    this->text.setCharacterSize(this->size);
    this->text.setFillColor(this->color);
    sf::FloatRect textRect = this->text.getLocalBounds();
    text.setOrigin(textRect.width / 2,textRect.height / 2);
    this->text.setPosition(x, y);
}
