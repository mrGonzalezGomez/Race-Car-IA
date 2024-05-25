/*
** EPITECH PROJECT, 2023
** B-AIA-200-MPL-2-1-bsn4s-killian.cassard
** File description:
** main.c
*/

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

#include "n4s.h"

static void consume_line(void)
{
    char *buffer = NULL;
    size_t size = 0;

    getline(&buffer, &size, stdin);
    free(buffer);
}

static double diff(double a, double b)
{
    if (a > b)
        return a - b;
    return b - a;
}

static void check_middle(double *left, double *right, double *m, double *alpha)
{
    if (*m < DIST){
        if (*left < *right)
            *alpha = -ANGLE;
        if (*right < *left)
            *alpha = ANGLE;
    }
}

static void danger(double *left, double *right, double *alpha)
{
    if (*left < 175)
        *alpha = -ANGLE * 1.2;
    if (*right < 175)
        *alpha = ANGLE * 1.2;
}

infos_t calculate_values(double *rays)
{
    double left = (rays[10] + rays[11] + rays[12]) / 3;
    double right = (rays[21] + rays[20] + rays[19]) / 3;
    double middle = rays[15];
    double speed = DEFAULT_SPEED;
    double alpha = 0;

    check_middle(&left, &right, &middle, &alpha);
    left = rays[0];
    right = rays[31];
    return (infos_t){left, right, middle, speed, alpha};
}

infos_t initial_decision(double *rays)
{
    infos_t values = calculate_values(rays);
    double left = values.left;
    double right = values.right;
    double middle = values.middle;
    double speed = values.speed;
    double alpha = values.alpha;

    if (diff(left, right) > 350){
        if (left < right)
            alpha = -ANGLE * 0.65;
        if (right < left)
            alpha = ANGLE * 0.65;
    }
    if (middle < DANGER){
        speed -= 0.1;
        danger(&left, &right, &alpha);
    }
    return (infos_t){left, right, middle, speed, alpha};
}

infos_t get_values(double *rays)
{
    infos_t values = initial_decision(rays);
    double left = values.left;
    double right = values.right;
    double middle = values.middle;
    double speed = values.speed;
    double alpha = values.alpha;

    if (left < 100)
        alpha = -ANGLE;
    if (right < 100)
        alpha = ANGLE;
    if (middle < 175 || left < 140 || right < 140){
        speed = -0.75;
        alpha *= -1;
    }
    return (infos_t){left, right, middle, speed, alpha};
}

static void handle_track_cleared(char **infos)
{
    if (my_strcmp(infos[35], "Track Cleared") == 0) {
        printf("CAR_FORWARD:0.0\n");
        fflush(stdout);
        consume_line();
        printf("STOP_SIMULATION\n");
        fflush(stdout);
        consume_line();
        exit(0);
    }
}

void my_custom_update(void)
{
    char **infos = get_infos();
    double *rays = get_rays(infos);
    infos_t values = get_values(rays);
    double speed = values.speed;
    double alpha = values.alpha;

    handle_track_cleared(infos);
    if (speed > 0)
        printf("CAR_FORWARD:%f\n", speed);
    else
        printf("CAR_BACKWARDS:%f\n", -speed);
    fflush(stdout);
    consume_line();
    printf("WHEELS_DIR:%f\n", alpha);
    fflush(stdout);
    consume_line();
    free(rays);
}

int main(void)
{
    double speed = 0.5;
    double alpha = 0.0;

    fflush(stdout);
    printf("START_SIMULATION\n");
    fflush(stdout);
    consume_line();
    fflush(stdout);
    printf("CAR_FORWARD:%f\n", speed);
    fflush(stdout);
    consume_line();
    fflush(stdout);
    printf("WHEELS_DIR:%f\n", alpha);
    fflush(stdout);
    consume_line();
    while (1)
        my_custom_update();
}
