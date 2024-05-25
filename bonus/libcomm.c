/*
** EPITECH PROJECT, 2023
** B-AIA-200-MPL-2-1-n4s-noa.gonzalez-gomez
** File description:
** libcomm.c
*/

#include "n4s.h"

/*
API CALLS:
START_SIMULATION
STOP_SIMULATION
CAR_FORWARD:float
CAR_BACKWARDS:float
WHEELS_DIR:float
GET_INFO_LIDAR
GET_CURRENT_SPEED
GET_CURRENT_WHEELS
CYCLE_WAIT
GET_CAR_SPEED_MAX
GET_CAR_SPEED_MIN
GET_INFO_SIMTIME
*/

static int my_strlen(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++){
        n++;
    }
    return n;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && i < my_strlen(s1); i++);
    if (i == my_strlen(s1) && i == my_strlen(s2)){
        return 0;
    }
    return (s1[i] - s2[i]);
}

double *convert_rays(char **src)
{
    double *rays = malloc(sizeof(double) * 32);

    for (int i = 0; i < 32; i++)
        rays[i] = atof(src[i + 3]);
    return rays;
}

char **get_infos(void)
{
    char *buffer = NULL;
    size_t size = 0;
    char **infos = NULL;

    fflush(stdout);
    printf("GET_INFO_LIDAR\n");
    fflush(stdout);
    getline(&buffer, &size, stdin);
    infos = mstwa(buffer, ":");
    free(buffer);
    return infos;
}

double *get_rays(char **infos)
{
    return convert_rays(infos);
}

double get_type2(char *cmd)
{
    char *buffer = NULL;
    size_t size = 0;
    char **infos = NULL;

    printf("%s", cmd);
    fflush(stdout);
    getline(&buffer, &size, stdin);
    infos = mstwa(buffer, ":");
    if (strncmp(infos[1], "OK", 2) != 0){
        write(2, "Error: ", 8);
        write(2, cmd, strlen(cmd));
        write(2, "\n", 1);
        exit(84);
    }
    free(buffer);
    return atof(infos[3]);
}
