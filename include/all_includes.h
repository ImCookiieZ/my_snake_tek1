/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** all_includes.h
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "../classes/game.hpp"

bool gamelooop(Game *game_object);
bool check_wall_collision(Game *game_object);
bool check_item_collision(Game *game_object, sf::Vector2f pos);
void place_valid_item(Game *game_object);
bool self_collision(Game *game_object);
void menu(sf::RenderWindow *my_win, std::string btn_1, std::string btn_2,
    std::string headline, int start);
void start_game(sf::RenderWindow *my_win);
#ifndef SNAKE_SFML_ALL_INCLUDES_H

#define SNAKE_SFML_ALL_INCLUDES_H

#endif //SNAKE_SFML_ALL_INCLUDES_H
