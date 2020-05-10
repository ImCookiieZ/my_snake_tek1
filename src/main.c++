/*
** EPITECH PROJECT, 2020
** snake_sfml
** File description:
** main.c++
*/

#include "../include/all_includes.h"

int main(int ac, char **av)
{
    srand(time(NULL));
    sf::SoundBuffer music_b;
    sf::Sound music;if (ac != 1)
        return (84);
    sf::RenderWindow my_win(sf::VideoMode(1920, 1080), "SNAKE",
        sf::Style::Close);

    music_b.loadFromFile("assets/music.ogg");
    music.setBuffer(music_b);
    music.setLoop(true);
    music.setVolume(5);
    music.play();
    menu(&my_win, "Start", "Exit", "MAIN MENU", 1);
}