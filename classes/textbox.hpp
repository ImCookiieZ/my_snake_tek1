/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** textbox.hpp
*/

#ifndef SNAKE_SFML_TEXTBOX_HPP

#define SNAKE_SFML_TEXTBOX_HPP

class Textbox
{
private:

    std::string text_s;
    sf::Font font;
    unsigned int size;
    sf::Color color;
public:
    sf::Text text;
    bool set_font(std::string path);
    void update(sf::RenderWindow *window);

    Textbox(const std::string &text_sting, unsigned int size_tmp, float x,
            float y, sf::Color color_tmp);

    bool set_text(std::string new_text);
};

#endif //SNAKE_SFML_TEXTBOX_HPP
