/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** snake.cpp
*/

#include <iostream>
#include "snake.hpp"

void Snake::init_pics()
{
    parts_t cur;
    heads[UP].loadFromFile("assets/spritesheet_snake.png", get_rect(1, 3));
    heads[RIGHT].loadFromFile("assets/spritesheet_snake.png", get_rect(3, 2));
    heads[DOWN].loadFromFile("assets/spritesheet_snake.png", get_rect(2, 3));
    heads[LEFT].loadFromFile("assets/spritesheet_snake.png", get_rect(3, 1));

    tails[UP].loadFromFile("assets/spritesheet_snake.png", get_rect(2, 0));
    tails[RIGHT].loadFromFile("assets/spritesheet_snake.png", get_rect(0, 1));
    tails[DOWN].loadFromFile("assets/spritesheet_snake.png", get_rect(1, 0));
    tails[LEFT].loadFromFile("assets/spritesheet_snake.png", get_rect(0, 2));

    turns[UR].loadFromFile("assets/spritesheet_snake.png", get_rect(1, 1));
    turns[UL].loadFromFile("assets/spritesheet_snake.png", get_rect(1, 2));
    turns[DL].loadFromFile("assets/spritesheet_snake.png", get_rect(2, 2));
    turns[DR].loadFromFile("assets/spritesheet_snake.png", get_rect(2, 1));

    betweens[RL].loadFromFile("assets/spritesheet_snake.png", get_rect(0, 3));
    betweens[UD].loadFromFile("assets/spritesheet_snake.png", get_rect(3, 0));

    cur.pos = sf::Vector2f(10 * 64, 10 * 64);
    mover = cur.pos;
    mover.y -= SPEED;
    cur.turn_into = UP;
    cur.dir = UP;
    cur.turn = false;
    cur.sp.setTexture(heads[UP]);
    parts.push_back(cur);
    cur.sp.setTexture(betweens[UD]);
    cur.pos.y += 64;
    parts.push_back(cur);
    cur.sp.setTexture(betweens[UD]);
    cur.pos.y += 64;
    parts.push_back(cur);
    cur.sp.setTexture(tails[UP]);
    cur.pos.y += 64;
    parts.push_back(cur);
}

void Snake::reset()
{
    parts_t cur;
    this->parts.clear();
    cur.pos = sf::Vector2f(10 * 64, 10 * 64);
    mover = cur.pos;
    mover.y -= SPEED;
    cur.turn_into = UP;
    cur.dir = UP;
    cur.turn = false;
    cur.sp.setTexture(heads[UP]);
    parts.push_back(cur);
    cur.sp.setTexture(betweens[UD]);
    cur.pos.y += 64;
    parts.push_back(cur);
    cur.sp.setTexture(betweens[UD]);
    cur.pos.y += 64;
    parts.push_back(cur);
    cur.sp.setTexture(tails[UP]);
    cur.pos.y += 64;
    parts.push_back(cur);
}


sf::IntRect get_rect(int row, int col)
{
    sf::IntRect ret = {0, 0, 64, 64};
    ret.left = col * 64 + (col + 1) * 10;
    ret.top = row * 64 + (row + 1) * 10;
    return (ret);
}