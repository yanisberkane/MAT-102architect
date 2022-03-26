/*
** EPITECH PROJECT, 2021
** swap_h
** File description:
** Library header
*/

#ifndef ARCHI_H
    #define ARCHI_H

        struct result {
            float a;
            float b;
            float x;
            float y;
            float m[9];
        };
        typedef struct result t_res;

    #define ERROR 84
    #define MY_PI 3.14159265358979323846
    #define ERROR_MSG "error\n"
    #define FILE_ERROR_MSG "file format error\n"
    #define EXIT_USAGE    0
    #define USER_MANUAL "USAGE\n\
    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...  \n\
DESCRIPTION\n\
    x abscissa of the original point\n\
    y ordinate of the original point\n\
\n\
    transfo arg1 [arg2]\n\
    -t i j translation along vector (i, j)\n\
    -z m n scaling by factors m (x-axis) and n (y-axis)\n\
    -r d rotation centered in O by a d degree angle\n\
    -s d reflection over the axis passing through O with an inclination\n\
         angle of d degrees\n"

void reflect(t_res *res, char **av, int i);
void rotate(t_res *res, char **av, int i);
void translate(t_res *res, char **av, int i);
void scale(t_res *res, char **av, int i);

#endif
