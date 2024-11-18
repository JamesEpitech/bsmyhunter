/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** .
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.h>
#include "include/my.h"
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfIntRect rect;
    sfClock *duckAnimationClock = sfClock_create();
    sfTime duckAnimationTime;

    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    window = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    texture = sfTexture_createFromFile("sources/duck.png", NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        moveSprite(sprite, &rect, mode.width); 
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, &rect, sprite);
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
                close_window(window);
        }
        duckAnimationTime = sfClock_getElapsedTime(duckAnimationClock);
        if (sfTime_asSeconds(duckAnimationTime) >= 0.16) {
            move_rect(&rect, 110, 330);
            sfClock_restart(duckAnimationClock);
        }
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);

    return EXIT_SUCCESS;
}