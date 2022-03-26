/*
** EPITECH PROJECT, 2021
** my_h
** File description:
** Library header
*/

#ifndef MY_H
    #define MY_H

int my_putstr_err(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int put_base_nbr(unsigned int nb, unsigned int base);
int my_compute_power_rec(int nb, int p);
char *isole_nbr_in_str(char const *str);

#endif
