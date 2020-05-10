/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** game.hpp
*/

#include "snake.hpp"

class Game
{
private:
    sf::RenderWindow *window;

    int score = 0;

    sf::Texture item1;
    sf::Texture item2;

    sf::Texture wall_t;
    sf::Texture background_t;
    sf::Sprite wall_s;
    sf::Sprite background_s;
    int highscore;
public:
    //variables
    Snake my_snake;
    sf::SoundBuffer eat_b;
    sf::SoundBuffer die_b;
    sf::Sound effect;
    sf::Sprite item;
    sf::Time timer_for_move;
    sf::Clock clocky;
    //methods
    sf::RenderWindow *get_window();
    explicit Game(sf::RenderWindow *window_par);
    void draw_fix_objects();
    void print_snake();
    void set_item_texture(int nb);
    int get_score();
    void increase_score();
    void set_highscore() const;
    void load_highscore();

    int get_highscore() const;
};