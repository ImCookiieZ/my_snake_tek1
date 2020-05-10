/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** snake_change_dir.cpp
*/

#include <iostream>
#include "snake.hpp"

void Snake::turn_right()
{
    std::list<parts_t>::iterator cur;
    cur = this->parts.begin();
    if (cur->turn)
        return;
    cur->turn = true;
    cur->turn_into = RIGHT;
    mover.x = cur->pos.x + SPEED;
    mover.y = cur->pos.y;
}

void Snake::turn_left() {
    std::list<parts_t>::iterator cur;
    cur = this->parts.begin();
    if (cur->turn)
        return;
    cur->turn = true;
    cur->turn_into = LEFT;
    mover.x = cur->pos.x - SPEED;
    mover.y = cur->pos.y;
}

void Snake::turn_up() {
    std::list<parts_t>::iterator cur;
    cur = this->parts.begin();
    if (cur->turn)
        return;
    cur->turn = true;
    cur->turn_into = UP;
    mover.y = cur->pos.y - SPEED;
    mover.x = cur->pos.x;
}

void Snake::turn_down() {
    std::list<parts_t>::iterator cur;
    cur = this->parts.begin();
    if (cur->turn)
        return;
    cur->turn = true;
    cur->turn_into = DOWN;
    mover.y = cur->pos.y + SPEED;
    mover.x = cur->pos.x;
}