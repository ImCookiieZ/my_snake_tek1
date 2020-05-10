/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** start_menu.c++
*/

#include <iostream>
#include "../classes/button.hpp"
#include "../classes/textbox.hpp"

bool check_button_pressed(Button button, sf::RenderWindow *my_win)
{
    if (button.is_pressed()) {
        sf::Clock clocky;
        clocky.restart();
        sf::Time timer = clocky.getElapsedTime();
        timer += sf::milliseconds(100);
        while (clocky.getElapsedTime() < timer) {
            button.update(my_win);
            my_win->display();
            my_win->clear(sf::Color::Black);
        };
        return (true);
    }
    return (false);
}

bool direction_self(Snake snake, char dir)
{
    std::list<parts_t>::iterator cur;
    cur = snake.parts.begin();
    sf::Vector2f pos = cur->pos;
    switch (dir) {
        case 'R':
            pos.x += 64;
            break;
        case 'L':
            pos.x -= 64;
            break;
        case 'U':
            pos.y -= 64;
            break;
        case 'D':
            pos.y += 64;
            break;
        default:
            break;
    }
    cur++;
    for (; cur != snake.parts.end(); ++cur)
    {
        if (cur->pos == pos)
            return (true);
    }
    return (false);
}

bool get_item(Game *game)
{
    sf::Vector2f pos = game->item.getPosition();
    std::list<parts_t>::iterator cur;
    cur = game->my_snake.parts.begin();
    if (cur->pos.x + 64 == pos.x && cur->pos.y == pos.y && cur->dir % 2 == 0)
        game->my_snake.turn_right();
    else if (cur->pos.x - 64 == pos.x && cur->pos.y == pos.y && cur->dir % 2
    == 0)
        game->my_snake.turn_left();
    else if (cur->pos.x == pos.x && cur->pos.y - 64 == pos.y && cur->dir % 2
    == 1)
        game->my_snake.turn_up();
    else if (cur->pos.x == pos.x && cur->pos.y + 64 == pos.y && cur->dir % 2
    == 1)
        game->my_snake.turn_down();
    else
        return false;
    return true;
}

void ai_get_direction(Game *game_object)
{
    std::string directions;
    std::list<parts_t>::iterator cur;
    int r;
    if (get_item(game_object))
        return;
    cur = game_object->my_snake.parts.begin();
    if (cur->pos.x + 64 < 1920 - 64 && !direction_self(game_object->my_snake,
        'R'))
        directions.append("R");
    if (cur->pos.x - 64 > 0 && !direction_self(game_object->my_snake,
        'L'))
        directions.append("L");
    if (cur->pos.y + 64 < 1025 - 64 && !direction_self(game_object->my_snake,
        'D'))
        directions.append("D");
    if (cur->pos.y - 64 > 0 && !direction_self(game_object->my_snake,
        'U'))
        directions.append("U");
    r = rand() % directions.length();
    if (directions[r] == 'R' && cur->dir % 2 == 0)
        game_object->my_snake.turn_right();
    else if (directions[r] == 'L' && cur->dir % 2 == 0)
        game_object->my_snake.turn_left();
    else if (directions[r] == 'U' && cur->dir % 2 == 1)
        game_object->my_snake.turn_up();
    else if (directions[r] == 'D' && cur->dir % 2 == 1)
        game_object->my_snake.turn_down();
    directions.clear();
}

void ai_snake(Game *game_object)
{
    if (game_object->clocky.getElapsedTime().asMicroseconds() >
        game_object->timer_for_move.asMicroseconds()) {
        ai_get_direction(game_object);
        game_object->my_snake.move_snake();
        if (check_wall_collision(game_object))
            game_object->my_snake.reset();
        if (check_item_collision(game_object, game_object->item.getPosition())) {
            game_object->increase_score();
            place_valid_item(game_object);
        }
        if (self_collision(game_object))
            game_object->my_snake.reset();
        game_object->timer_for_move += sf::milliseconds(300);
    }
    game_object->get_window()->clear(sf::Color::Black);
    game_object->draw_fix_objects();
    game_object->print_snake();
}

void menu(sf::RenderWindow *my_win, std::string buttton1,
    std::string buttton2, std::string headline, int start)
{
    sf::Texture back;
    back.loadFromFile("assets/background.jpg");
    sf::Sprite sp_back (back);
    sp_back.setScale(2.5, 2.5);
    my_win->draw(sp_back);
    Textbox headline_text (headline, 200, 960, 200, sf::Color::White);
    Button exit_button (960, 700, 400, 100, buttton2);
    Button start_button (960, 500, 400, 100, buttton1);
    sf::Event event = {};
    Game gameobject (my_win);
    gameobject.my_snake.init_pics();
    place_valid_item(&gameobject);
    while (my_win->isOpen()) {
        while (my_win->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                my_win->close();
        }
        ai_snake(&gameobject);
        exit_button.update(my_win);
        start_button.update(my_win);
        headline_text.update(my_win);
        if (check_button_pressed(exit_button, my_win))
            my_win->close();
        if (check_button_pressed(start_button, my_win)) {
            if (start == 1) {
                start_game(my_win);
                my_win->close();
            }
            else
                return;
        }
        my_win->display();
    }
 }