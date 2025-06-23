/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** load
*/

#include "utils.h"

int load_game(void)
{
    FILE *file = fopen("save_file", "r");
    char *line = 0;
    size_t len;
    int ammo = 0;

    if (!file) {
        printf("Couldn't load game stats\n");
        return 0;
    }
    if (getline(&line, &len, file) != -1)
        ammo = atoi(line);
    return ammo;
}
