/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** .
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>

#ifndef MY_H_
    #define MY_H_

void analyse_events(sfRenderWindow *window, sfEvent event, sfIntRect *rect, sfSprite *sprite);
void manage_mouse_click(sfMouseButtonEvent event, sfIntRect *rect, sfSprite *sprite);
void close_window(sfRenderWindow *window);
void move_rect(sfIntRect *rect, int offset, int max_value);
void moveSprite(sfSprite *sprite, sfIntRect *rect, int max_pos);

#endif /* !MY_H_ */
