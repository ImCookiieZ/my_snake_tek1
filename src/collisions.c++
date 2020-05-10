/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** collisions.c++
*/

#include "../include/all_includes.h"

bool check_item_collision(Game *game_object, sf::Vector2f pos)
{
    std::list<parts_t>::iterator cur;
    for (cur = game_object->my_snake.parts.begin();
        cur != game_object->my_snake.parts.end(); ++cur) {
        if (pos.x == cur->pos.x && pos.y == cur->pos.y) {
            return (true);
        }
    }
    return (false);
}

bool self_collision(Game *game_object)
{
    std::list<parts_t>::iterator cur;
    cur = game_object->my_snake.parts.begin();
    sf::Vector2f pos = cur->pos;
    cur++;
    for (; cur != game_object->my_snake.parts.end(); ++cur) {
        if (pos.x == cur->pos.x && pos.y == cur->pos.y) {
            return (true);
        }
    }
    return (false);
}

bool check_wall_collision(Game *game_object)
{
    sf::Vector2f head_pos = game_object->my_snake.parts.begin()->pos;
    if (head_pos.x < 64 || head_pos.x + 64 > 1920 - 64)
        return (true);
    return head_pos.y < 64 || head_pos.y + 64 > 1025 - 64;
}