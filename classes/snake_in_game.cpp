/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** snake_in_game.cpp
*/

#include <iostream>
#include "snake.hpp"

int Snake::change_texture_turn(int from, int to, std::list<parts_t>::iterator
cur)
{
    cur->turn = false;
    cur->dir = cur->turn_into;
    if (cur == parts.begin())
        cur->sp.setTexture(heads[cur->dir]);
    else if (cur == --parts.end())
        cur->sp.setTexture(tails[cur->dir]);
    else
        get_turn_texture(from, to, cur);
    return (cur->dir);
}

int Snake::change_texture(std::list<parts_t>::iterator
cur)
{
    if (cur != this->parts.begin() && cur != --this->parts.end())
        cur->sp.setTexture(betweens[cur->dir % 2]);
    return (cur->dir);
}

int
Snake::switch_texture(int from, int to, std::list<parts_t>::iterator &cur) const
{
    cur->turn = false;
    cur->dir = cur->turn_into;
    if (cur == parts.begin())
        cur->sp.setTexture(heads[cur->dir]);
    else if (cur == --parts.end())
        cur->sp.setTexture(tails[cur->dir]);
    else
        get_turn_texture(from, to, cur);
    return (cur->dir);
}

void Snake::get_turn_texture(int from, int to,
                             const std::list<parts_t>::iterator &cur) const
{
    if ((from == UP && to == RIGHT) || (from == LEFT && to == DOWN))
        cur->sp.setTexture(turns[UR]);
    if ((from == UP && to == LEFT) || (from == RIGHT && to == DOWN))
        cur->sp.setTexture(turns[UL]);
    if ((from == DOWN && to == RIGHT) || (from == LEFT && to == UP))
        cur->sp.setTexture(turns[DR]);
    if ((from == DOWN && to == LEFT) || (from == RIGHT && to == UP))
        cur->sp.setTexture(turns[DL]);
    cur->dir = cur->turn_into;
}

void Snake::insert()
{
    parts_t insert_this;
    std::list<parts_t>::iterator cur;
    cur = this->parts.begin();
    insert_this = *cur;
    cur++;
    insert_this.sp.setTexture(betweens[cur->turn_into % 2]);
    this->parts.insert(cur, insert_this);
    cur--;
    get_turn_texture(insert_this.dir, insert_this.turn_into, cur);
}

void Snake::move_snake()
{
    parts_t insert_this;
    std::list<parts_t>::iterator cur;
    insert();
    cur = this->parts.begin();
    cur->pos = mover;
    cur->dir = cur->turn_into;
    cur->sp.setTexture(heads[cur->turn_into]);
    if (this->my_insert_nb > 0) {
        this->my_insert_nb--;
    }
    else {
        cur = this->parts.end();
        cur--;
        cur--;
        insert_this = *cur;
        this->parts.erase(cur);
        cur = this->parts.end();
        cur--;
        *cur = insert_this;
        cur->sp.setTexture(tails[cur->turn_into]);
        cur->dir = cur->turn_into;
    }
    cur = this->parts.begin();
    move_per_speed(cur);
    cur->turn = false;
}

void Snake::move_per_speed(std::list<parts_t>::iterator &cur)
{
    switch (cur->dir) {
        case UP:
            mover.y -= SPEED;
            break;
        case DOWN:
            mover.y += SPEED;
            break;
        case RIGHT:
            mover.x += SPEED;
            break;
        case LEFT:
            mover.x -= SPEED;
            break;
        default:
            std::cout << "exit\n";
            exit(84);
    }
}
