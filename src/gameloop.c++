/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** gameloop.c++
*/

#include "../include/all_includes.h"

void place_valid_item(Game *game_object)
{
    sf::Vector2f const pos = {
        static_cast<float>((rand() % (1920 / 64 - 2) + 1) * 64),
        static_cast<float>((rand() % (1025 / 64 - 2) + 1) * 64)
    };
    if (check_item_collision(game_object, pos))
        place_valid_item(game_object);
    else
        game_object->item.setPosition(pos);
}

void check_event(Game *game_object)
{
    if (game_object->my_snake.parts.begin()->dir % 2 == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            game_object->my_snake.turn_left();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            game_object->my_snake.turn_right();
    }
    if (game_object->my_snake.parts.begin()->dir % 2 == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            game_object->my_snake.turn_up();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            game_object->my_snake.turn_down();
    }
}

bool gamelooop(Game *game_object)
{
    check_event(game_object);
    if (game_object->clocky.getElapsedTime().asMicroseconds() >
    game_object->timer_for_move.asMicroseconds()) {
        game_object->my_snake.move_snake();
        if (check_wall_collision(game_object))
            return (true);
        if (check_item_collision(game_object, game_object->item.getPosition())) {
            game_object->increase_score();
            place_valid_item(game_object);
        }
        if (self_collision(game_object))
            return (true);
        game_object->timer_for_move += sf::milliseconds(300);

    }
    game_object->get_window()->clear(sf::Color::Black);
    game_object->draw_fix_objects();
    game_object->print_snake();
    return (false);
}