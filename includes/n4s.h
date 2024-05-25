/*
** EPITECH PROJECT, 2023
** B-AIA-200-MPL-2-1-bsn4s-killian.cassard
** File description:
** n4s.h
*/

#pragma once

#include "stdbool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DIST 800
#define ANGLE 0.22
#define DANGER 400
#define DANGER_EXTRM 200
#define DEFAULT_SPEED 0.55

typedef struct infos_s {
    double left;
    double right;
    double middle;
    double speed;
    double alpha;
} infos_t;

char **mstwa(char *src, char *sep);
double *get_rays(char **infos);
double get_type2(char *cmd);
void free_arr(char **arr);
char **get_infos(void);
int my_strcmp(char const *s1, char const *s2);
