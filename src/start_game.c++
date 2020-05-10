/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** start_game.c++
*/

#include <sstream>
#include "../include/all_includes.h"
#include "../classes/textbox.hpp"

void start_game(sf::RenderWindow *my_win)
{
    bool ret = false;
    Game gameobject (my_win);
    Textbox score ("Score:", 50, 50, 0, sf::Color::White);
    Textbox score_nb ("insert", 40, 200, 10, sf::Color::White);
    score_nb.set_font("assets/font.ttf");
    Textbox high_score ("Highscore:", 50, 300, 0, sf::Color::White);
    Textbox high_score_nb ("insert", 40, 600, 10, sf::Color::White);
    high_score_nb.set_font("assets/font.ttf");
    gameobject.my_snake.init_pics();
    place_valid_item(&gameobject);
    my_win->setVerticalSyncEnabled(true);
    sf::Event my_ev{};
    gameobject.load_highscore();
    while (my_win->isOpen())
    {
        while (my_win->pollEvent(my_ev))
        {
            if (my_ev.type == sf::Event::Closed)
                my_win->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                menu(my_win, "Continue", "Exit", "Pause", 0);
                gameobject.timer_for_move = gameobject.clocky.getElapsedTime();
            }
        }
        ret = gamelooop(&gameobject);
        if (ret) {
            gameobject.effect.setVolume(10);
            gameobject.effect.setBuffer(gameobject.die_b);
            gameobject.effect.play();
            gameobject.my_snake.reset();
            break;
        }
        score.update(my_win);
        high_score.update(my_win);
        score_nb.set_text(std::to_string(gameobject.get_score()));
        high_score_nb.set_text(std::to_string(gameobject.get_highscore()));
        score_nb.update(my_win);
        high_score_nb.update(my_win);
        gameobject.get_window()->display();
    }
    if (ret) {
        menu(my_win, "restart", "exit", "GAME OVER", 1);
    }
    gameobject.set_highscore();
}