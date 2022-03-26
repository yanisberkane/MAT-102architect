/*
** EPITECH PROJECT, 2021
** 102architect
** File description:
** transfos_simple_cases
*/

#include "include/architect.h"
#include "include/my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void reflect(t_res *res, char **av, int i)
{
    float resx = 0;
    float resy = 0;
    float deg = (MY_PI/180) * atof(av[i + 1]);
    float tab[3] = {res->a, res->b, 1};
    float t_mt[9] = {cos(2 * deg), sin(2 * deg), 0, sin(2 * deg), (cos(2 * deg) * -1), 0, 0, 0, 1};

    for (int j = 0; j < 3; j++) {
        resx = tab[j] * t_mt[j] + resx;
        res->m[j] = t_mt[j];
    }
    for (int k = 3; k < 6; k++) {
        resy = tab[k - 3] * t_mt[k] + resy;
        res->m[k] = t_mt[k];
    }
    res->x = resx;
    res->y = resy;
    return;
}

void rotate(t_res *res, char **av, int i)
{
    float resx = 0;
    float resy = 0;
    float deg = (MY_PI/180) * atof(av[i + 1]);
    float tab[3] = {res->a, res->b, 1};
    float t_mt[9] = {cos(deg), (sin(deg) * -1), 0, sin(deg), cos(deg), 0, 0, 0, 1};

    for (int j = 0; j < 3; j++) {
        resx = tab[j] * t_mt[j] + resx;
        res->m[j] = t_mt[j];
    }
    for (int k = 3; k < 6; k++) {
        resy = tab[k - 3] * t_mt[k] + resy;
        res->m[k] = t_mt[k];
    }
    res->x = resx;
    res->y = resy;
    return;
}

void scale(t_res *res, char **av, int i)
{
    float resx = 0;
    float resy = 0;
    float tab[3] = {res->a, res->b, 1};
    float t_mt[9] = {atof(av[i + 1]), 0, 0, 0, atof(av[i + 2]), 0, 0, 0, 1};

    for (int j = 0; j < 3; j++) {
        resx = tab[j] * t_mt[j] + resx;
        res->m[j] = t_mt[j];
    }
    for (int k = 3; k < 6; k++) {
        resy = tab[k - 3] * t_mt[k] + resy;
        res->m[k] = t_mt[k];
    }
    res->x = resx;
    res->y = resy;
    return;
}

void translate(t_res *res, char **av, int i)
{
    float resx = 0;
    float resy = 0;
    float tab[3] = {res->a, res->b, 1};
    float t_mt[9] = {1, 0, atof(av[i + 1]), 0, 1, atof(av[i + 2]), 0, 0, 1};

    for (int j = 0; j < 3; j++) {
        resx = tab[j] * t_mt[j] + resx;
        res->m[j] = t_mt[j];
    }
    for (int k = 3; k < 6; k++) {
        resy = tab[k - 3] * t_mt[k] + resy;
        res->m[k] = t_mt[k];
    }
    res->x = resx;
    res->y = resy;
    return;
}
