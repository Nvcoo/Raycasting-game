/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** game_loop
*/

#include "utils.h"
#include "struct.h"

void menu_page(sfRenderWindow *window, assets_t *assets)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_menu(assets, window);
    sfRenderWindow_display(window);
}

void game_page(core_t *core, sfRenderWindow *window,
    sfClock *torch_clock, sfClock *gun_clock)
{
    game_functions(core->player, window, core->assets);
    if (!core->player->show_map) {
        update_torch(window, core->assets, torch_clock);
        update_gun(window, core->assets, gun_clock);
    }
}

void handle_events(sfRenderWindow *window, core_t *core, assets_t *assets)
{
    while (sfRenderWindow_pollEvent(window, core->event)) {
        if (assets->state == MENU) {
            handle_menu(core->event, assets, window);
            continue;
        } else
            events(window, *core->event, core->player, core->assets);
    }
}

static void music_handler(assets_t *assets, int *music_playing)
{
    if (*music_playing == 0) {
        sfMusic_play(assets->bg_music);
        sfMusic_play(assets->torch_music);
        *music_playing = 1;
    }
}

static void music_loop(assets_t *assets)
{
    sfMusic_setLoop(assets->bg_music, sfTrue);
    sfMusic_setLoop(assets->torch_music, sfTrue);
    assets->gun.ammo_count = load_game();
}

void game_code(assets_t *assets, Player_t *player, sfRenderWindow *window)
{
    sfClock *torch_clock = sfClock_create();
    sfClock *gun_clock = sfClock_create();
    sfEvent event;
    core_t core = {&event, assets, player};
    int music_playing = 0;

    assets->state = MENU;
    music_loop(assets);
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, &core, assets);
        if (assets->state == MENU)
            menu_page(window, assets);
        else {
            music_handler(assets, &music_playing);
            game_page(&core, window, torch_clock, gun_clock);
        }
        resolution_view(window);
    }
    save_game(assets);
    destroy_assets(assets, torch_clock, gun_clock);
}

int game_loop(sfRenderWindow *window)
{
    assets_t assets;
    Player_t player;

    assets.bg_music = sfMusic_createFromFile("assets/music.ogg");
    assets.torch_music = sfMusic_createFromFile("assets/torch.ogg");
    init_menu(&assets);
    init_game(&player, &assets, window);
    game_code(&assets, &player, window);
    sfMusic_destroy(assets.bg_music);
    sfMusic_destroy(assets.torch_music);
    return 0;
}
