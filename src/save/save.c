/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** save
*/

#include "utils.h"
#include "struct.h"

void save_game(assets_t *assets)
{
    FILE *file = fopen("save_file", "w");

    if (!file) {
        printf("save file not found or could not be opened\n");
        return;
    }
    fprintf(file, "%d\n", assets->gun.ammo_count);
    fclose(file);
}
