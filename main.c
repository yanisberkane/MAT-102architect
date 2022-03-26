/*
** EPITECH PROJECT, 2021
** 102architect
** File description:
** main.c
*/

#include "include/architect.h"
#include "include/my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int my_isformula(char *av)
{
    char *tr[] = {"-z","-t","-r","-s"};

    for (int j = 0; j < 4; j++) {
         if (strcmp(av, tr[j]) == 0)
             return 1;
    }
    return 0;
}

int is_digits(char *argv)
{
    for (int i = 0; i < my_strlen(argv); i++) {
        if ((argv[i] < '0' || argv[i] > '9') && argv[i] != '-' && argv[i] != '.') {
            return 1;
        }
    }
    return 0;
}

void get_transfo(t_res *res, int argc, char **argv, int i)
{
    res->a = atof(argv[i - 2]);
    res->b = atof(argv[i - 1]);
    if (i == 3) {
        for (int k = 0; k < 6; k++)
             res->m[i] = 1;
    }
    if (argc >= 7 && i >= 6) {
        res->a = res->x;
        res->b = res->y;
    }
    if (strcmp(argv[i], "-t") == 0 && argc >= 6) {
        translate(res, argv, i);
        printf("Translation along vector (%d, %d)\n", atoi(argv[i + 1]), atoi(argv[i + 2]));
    }
    if (strcmp(argv[i], "-z") == 0 && argc >= 6) {
        scale(res, argv, i);
        printf("Scaling by factors %d and %d\n", atoi(argv[i + 1]), atoi(argv[i + 2]));
    }
    if (strcmp(argv[i], "-r") == 0 && argc >= 5) {
        rotate(res, argv, i);
        printf("Rotation by a %d degree angle\n", atoi(argv[i + 1]));
    }
    if (strcmp(argv[i], "-s") == 0 && argc >= 5) {
        reflect(res, argv, i);
        printf("Reflection over an axis with an inclination angle of %d degrees\n", atoi(argv[i + 1]));
    }
}

int main(int argc, char **argv)
{
    t_res res;

    if (argc <= 4) {
        if (argc == 2 && strcmp(argv[1], "-h") == 0) {
            my_putstr(USER_MANUAL);
            return 0;
        }
        my_putstr_err(ERROR_MSG);
        return ERROR;
    }
    for (int i = 3; i < argc; i++) {
        if (my_isformula(argv[i]) == 1) {
            get_transfo(&res, argc, argv, i);
        }
    }
    printf("%.2f\t%.2f\t%.2f\n", res.m[0]+0.0000001, res.m[1]+0.0000001, res.m[2]+0.0000001);
    printf("%.2f\t%.2f\t%.2f\n", res.m[3]+0.0000001, res.m[4]+0.0000001, res.m[5]+0.0000001);
    printf("0.00\t0.00\t1.00\n");
    printf("(%.2f, %.2f) => ", atof(argv[1]), atof(argv[2]));
    printf("(%.2f, %.2f)\n", res.x+0.0000001, res.y+0.0000001);
    return 0;
}
