/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** handle_menu
*/

#include "utils.h"
#include "struct.h"

void increase_volume(assets_t *assets)
{
    float volume_bg = sfMusic_getVolume(assets->bg_music);
    float volume_torch = sfMusic_getVolume(assets->torch_music);

    if (volume_bg < 100) {
        volume_bg += 15;
        volume_torch += 15;
        if (volume_bg > 100)
            volume_bg = 100;
        if (volume_torch > 100)
            volume_torch = 100;
        sfMusic_setVolume(assets->bg_music, volume_bg);
        sfMusic_setVolume(assets->torch_music, volume_torch);
        printf("Background music volume: %.0f\n", volume_bg);
        printf("Torch music volume: %.0f\n", volume_torch);
    }
}

void decrease_volume(assets_t *assets)
{
    float volume_bg = sfMusic_getVolume(assets->bg_music);
    float volume_torch = sfMusic_getVolume(assets->torch_music);

    if (volume_bg > 0 || volume_torch > 0) {
        volume_bg -= 15;
        volume_torch -= 15;
        if (volume_bg < 0)
            volume_bg = 0;
        if (volume_torch < 0)
            volume_torch = 0;
        sfMusic_setVolume(assets->bg_music, volume_bg);
        sfMusic_setVolume(assets->torch_music, volume_torch);
        printf("Background music volume: %.0f\n", volume_bg);
        printf("Torch music volume: %.0f\n", volume_torch);
    }
}

static void handle_volume(assets_t *assets, sfFloatRect up_bounds,
    sfFloatRect down_bounds, sfVector2i mouse_pos)
{
    if (sfFloatRect_contains(&up_bounds, mouse_pos.x, mouse_pos.y))
        increase_volume(assets);
    else if (sfFloatRect_contains(&down_bounds, mouse_pos.x, mouse_pos.y))
        decrease_volume(assets);
}

static void update_window(sfRenderWindow **window, sfVideoMode mode,
    sfUint32 res)
{
    sfRenderWindow_destroy(*window);
    *window = sfRenderWindow_create(mode, "3D", res, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

static void window_mode(assets_t *assets, sfVideoMode *mode, sfUint32 *res)
{
    if (assets->is_fullscreen == false) {
        *mode = sfVideoMode_getDesktopMode();
        *res = sfFullscreen;
        sfTexture_destroy(assets->menu.res_texture);
        assets->menu.res_texture =
            sfTexture_createFromFile("assets/min.png", NULL);
        assets->is_fullscreen = true;
    } else {
        mode->width = 800;
        mode->height = 600;
        mode->bitsPerPixel = 32;
        *res = sfClose | sfResize;
        sfTexture_destroy(assets->menu.res_texture);
        assets->menu.res_texture =
            sfTexture_createFromFile("assets/max.png", NULL);
        assets->is_fullscreen = false;
    }
}

void handle_res(sfRenderWindow **window, assets_t *assets)
{
    sfVideoMode mode;
    sfUint32 res;

    window_mode(assets, &mode, &res);
    update_window(window, mode, res);
}

static void handle_clicks(sfVector2i mouse_pos, sfRenderWindow *window,
    assets_t *assets)
{
    sfFloatRect start_bounds =
        sfSprite_getGlobalBounds(assets->menu.start_bg_sprite);
    sfFloatRect help_bounds =
        sfSprite_getGlobalBounds(assets->menu.help_sprite);
    sfFloatRect res_bounds =
        sfSprite_getGlobalBounds(assets->menu.res_sprite);

    if (sfFloatRect_contains(&start_bounds, mouse_pos.x, mouse_pos.y))
        sfRenderWindow_close(window);
    if (sfFloatRect_contains(&help_bounds, mouse_pos.x, mouse_pos.y))
        assets->menu.show_help = !assets->menu.show_help;
    if (sfFloatRect_contains(&res_bounds, mouse_pos.x, mouse_pos.y))
        handle_res(&window, assets);
}

void handle_menu(sfEvent *event, assets_t *assets, sfRenderWindow *window)
{
    sfFloatRect leave_bounds =
        sfSprite_getGlobalBounds(assets->menu.leave_bg_sprite);
    sfFloatRect up_bounds =
        sfSprite_getGlobalBounds(assets->menu.up_sprite);
    sfFloatRect down_bounds =
        sfSprite_getGlobalBounds(assets->menu.down_sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (event->type == sfEvtMouseButtonPressed &&
        event->mouseButton.button == sfMouseLeft) {
        if (sfFloatRect_contains(&leave_bounds, mouse_pos.x, mouse_pos.y))
            assets->state = GAME;
        handle_clicks(mouse_pos, window, assets);
        handle_volume(assets, up_bounds, down_bounds, mouse_pos);
    }
}
