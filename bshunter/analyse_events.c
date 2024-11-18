/*
** EPITECH PROJECT, 2024
** analyse_events.c
** File description:
** .
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include "include/my.h"
#include <stdio.h>

void analyse_events(sfRenderWindow *window, sfEvent event, sfIntRect *rect, sfSprite *sprite)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        manage_mouse_click(event.mouseButton, rect, sprite);
}

void manage_mouse_click(sfMouseButtonEvent event, sfIntRect *rect, sfSprite *sprite)
{
    sfVector2i position = sfIntRect_getPosition(rect);
    sfVector2i size = sfIntRect_getSize(rect);

 //  printf("Mouse x=%d y=%d\n", event.x, event.y);
    if (position.x <= event.x && position.x + size.x >= event.x && position.y <= event.y && position.y + size.y >= event.y)
        printf("posx = %d posy = %d\n", event.x, event.y);
      //  sfSprite_destroy(sprite);
}

void moveSprite(sfSprite *sprite, sfIntRect *rect, int max_pos)
{
    int speed = 10;
    sfVector2f position = sfSprite_getPosition(sprite);

    if (position.x + speed > max_pos)
        position.x = -max_pos - rect->width;
    else
        position.x = speed;
    sfSprite_move(sprite, position);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset >= max_value)
        rect->left = 0;
    else
        rect->left += offset;
    
}