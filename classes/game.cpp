/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** game.cpp
*/

#include <fstream>
#include "../include/all_includes.h"

sf::RenderWindow * Game::get_window()
{
    return (window);
}

void Game::draw_fix_objects()
{
    window->draw(background_s);
    for (int i = 0; i < (1920 - 64) / 64; i++) {
        window->draw(wall_s);
        wall_s.move(64, 0);
    }
    for (int i = 0; i < 1025 / 64; i++) {
        window->draw(wall_s);
        wall_s.move(0, 64);
    }
    wall_s.setPosition(0, 0);
    for (int i = 0; i < (1025 - 64) / 64; i++) {
        window->draw(wall_s);
        wall_s.move(0, 64);
    }
    for (int i = 0; i < (1920 - 64) / 64; i++) {
        window->draw(wall_s);
        wall_s.move(64, 0);
    }
    wall_s.setPosition(0, 0);
    window->draw(item);
}

void Game::print_snake()
{
    std::list<parts_t>::iterator cur;
    for (cur = this->my_snake.parts.begin();
        cur != this->my_snake.parts.end(); cur++) {
        cur->sp.setPosition(cur->pos.x, cur->pos.y);
        this->get_window()->draw(cur->sp);
    }
}

Game::Game(sf::RenderWindow *window_par)
{
    int ran = rand() % 2;
    this->die_b.loadFromFile("assets/dieSound.ogg");
    this->eat_b.loadFromFile("assets/eatSound.ogg");
    this->effect.setVolume(10);
    window = window_par;
    background_t.loadFromFile("assets/background.jpg");
    wall_t.loadFromFile("assets/spritesheet_snake.png", get_rect(4, 0));
    background_s.setTexture(background_t);
    wall_s.setTexture(wall_t);
    clocky.restart();
    timer_for_move = clocky.getElapsedTime();
    item1.loadFromFile("assets/spritesheet_snake.png", get_rect(4, 1));
    item2.loadFromFile("assets/spritesheet_snake.png", get_rect(4, 2));
    if (ran == 0)
        item.setTexture(item1);
    else
        item.setTexture(item2);
    background_s.scale(2.5, 2.5);
    this->score = 0;
    this->highscore = 0;
}

void Game::increase_score()
{
    this->effect.setBuffer(this->eat_b);
    this->effect.setVolume(50);
    this->effect.play();
    this->my_snake.my_insert_nb++;
    this->score++;
}

int Game::get_score()
{
    return (this->score);
}

void Game::set_highscore() const
{
    if (this->score > this->highscore) {
        std::ofstream saver (".highscore.txt");
        saver << this->score;
        saver << "\n";
        saver.close();
    }
}

void Game::load_highscore()
{
    std::string score_str;
    std::ifstream saver (".highscore.txt");

    int high = 0;
    if (getline(saver, score_str))
        high = std::stoi(score_str);
    saver.close();
    this->highscore = high;
}

int Game::get_highscore() const
{
    return this->highscore;
}

void Game::set_item_texture(int nb)
{
    if (nb == 0)
        this->item.setTexture(item1);
    else
        this->item.setTexture(item2);
}

