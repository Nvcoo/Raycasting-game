/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** main
*/

#include "struct.h"
#include "utils.h"
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <stdbool.h>

void mouse_rotation(sfRenderWindow *window, Player_t *player)
{
    sfVector2i center = {400, 300};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int x_change = mouse_pos.x - center.x;
    float sensitivity = 0.0002f;

    player->angle += x_change * sensitivity;
    sfMouse_setPosition(center, (sfWindow *)window);
    sfWindow_setMouseCursorVisible((sfWindow *)window, sfFalse);
}

void relative_pause(Player_t *player, sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfRectangleShape *blur = NULL;

    if (!player->show_map)
        return;
    blur = sfRectangleShape_create();
    sfRectangleShape_setSize(blur, (sfVector2f){size.x, size.y});
    sfRectangleShape_setPosition(blur, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(blur, sfColor_fromRGBA(0, 0, 0, 180));
    sfRenderWindow_drawRectangleShape(window, blur, NULL);
    draw_minimap(window, player);
    sfRectangleShape_destroy(blur);
}

static void game_functions(Player_t *player, sfRenderWindow *window,
    assets_t *assets)
{
    update_player(player);
    mouse_rotation(window, player);
    sfRenderWindow_clear(window, sfBlack);
    draw_floor_and_ceiling(window);
    cast_all_rays(window, player);
    sfRenderWindow_drawSprite(window, assets->t_sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->g_sprite, NULL);
    sfRenderWindow_drawText(window, assets->ammo_text, NULL);
    relative_pause(player, window);
    if (!player->show_map)
        draw_crosshair(window, assets);
    sfRenderWindow_display(window);
}

int events(sfRenderWindow *window, sfEvent event, Player_t *player,
    assets_t *assets)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) ||
            sfKeyboard_isKeyPressed(sfKeySpace))
            assets->firing = true;
        else
            assets->firing = false;
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            player->show_map = !player->show_map;
    }
    game_functions(player, window, assets);
    return 0;
}

static void resolution_view(sfRenderWindow *window)
{
    sfView *view;
    sfVector2u window_size = sfRenderWindow_getSize(window);

    view = sfView_createFromRect((sfFloatRect)
    {0, 0, window_size.x, window_size.y});
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
}

static void destroy_assets(assets_t *assets, sfClock *torch_clock,
    sfClock *gun_clock)
{
    destroy_torch(assets);
    destroy_gun(assets);
    sfClock_destroy(torch_clock);
    sfClock_destroy(gun_clock);
    sfSprite_destroy(assets->cross_sprite);
    sfTexture_destroy(assets->cross_texture);
    sfText_destroy(assets->ammo_text);
    sfFont_destroy(assets->ammo_font);
}

static void init_game(Player_t *player, assets_t *assets,
    sfRenderWindow *window)
{
    init_player(player);
    init_gun(window, assets);
    init_torch(window, assets);
    init_crosshair(window, assets);
    ammo_text(assets);
}

int game_loop(sfRenderWindow *window)
{
    assets_t assets;
    sfClock *torch_clock = sfClock_create();
    sfClock *gun_clock = sfClock_create();
    sfEvent event;
    Player_t player;

    init_game(&player, &assets, window);
    while (sfRenderWindow_isOpen(window)) {
        events(window, event, &player, &assets);
        if (!player.show_map) {
            update_torch(window, &assets, torch_clock);
            update_gun(window, &assets, gun_clock);
        }
        resolution_view(window);
    }
    destroy_assets(&assets, torch_clock, gun_clock);
    return 0;
}

static void cleanup_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "3D", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    game_loop(window);
    cleanup_window(window);
    return 0;
}
