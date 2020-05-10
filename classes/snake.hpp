/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** snake.hpp
*/

#include <SFML/Graphics.hpp>
#include <list>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UR 0
#define UL 1
#define DL 2
#define DR 3
#define UD 0
#define RL 1

sf::IntRect get_rect(int row, int col);

typedef struct snake_parts {
    sf::Vector2f pos;
    sf::Sprite sp;
    int dir;
    int turn_into;
    bool turn;
} parts_t;

class Snake
{
private:
    sf::Texture heads [4];
    sf::Texture tails [4];
    sf::Texture turns [4];
    sf::Texture betweens [2];
    int SPEED = 64;
    //methods
    int change_texture_turn(int from, int to, std::list<parts_t>::iterator cur);
    int change_texture(std::list<parts_t>::iterator cur);
    void move_per_speed(std::list<parts_t>::iterator &cur);
    void get_turn_texture(int from, int to,
                          const std::list<parts_t>::iterator &cur) const;
    int
    switch_texture(int from, int to, std::list<parts_t>::iterator &cur) const;

public:
    //variables
    sf::Vector2f mover;
    int my_insert_nb = 0;
    std::list<parts_t> parts;
    int len = 3;
    //methods
    void init_pics();
    void turn_right();
    void turn_left();
    void turn_up();
    void turn_down();
    void move_snake();
    void insert();
    void reset();
};