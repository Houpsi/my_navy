/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** eat
*/
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "stdarg.h"
#include "stdlib.h"

#ifndef TEST_H_
    #define TEST_H_

typedef struct map_s1 {
    char **map_boat_mine;
    char **map_attack;
} map_t1;

map_t1 *create_struct_map(char *filepath_mine);
char **open_file(char *filepath);
int which_colums(char letter);
int my_putstr(char const *str);
char **map_empty(void);
int which_line(char letter);
map_t1 *create_struct_map(char *filepath);
int give_ligne(char *filepath);
int error_handling(char *filepath);
char **cond_space_map(char **map, int *space, int *i, int *j);
char **put_line(char **map);
char **put_letter_num(char **map);
char **mem_alloc_2d_array(void);
void display_map(map_t1 *map);
int attack(char letter, int line, map_t1 *);
typedef struct {
    int connected;
    int signal_received;
    int sig_coord;
    int win;
    int loose;
    int need_user_input;
    int type_sig;
    char coord_letter;
    char coord_digit;
    pid_t pid_player1;
    int missed;
    int hit;
    int var_miss;
    pid_t pid2;
    char *filepath_1;
    char *filepath_2;
} game_data_t;
extern game_data_t game_data;

int my_putstr(char const *str);
char **map_empty(void);
int my_strcmp(char const *s1, char const *s2);
int cond3(int i, const char *format, va_list list);
int cond2(int i, const char *format, va_list list);
int cond(int i, const char *format, va_list list);
int mini_printf(const char *format, ...);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_uns(int nb);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int condition(int h, int no_nombre, char const *str);
void sigusr1_handler(int signo);
int player1(int argc, char **argv);
int player2(int argc, char **argv);
int transform(void);
int send_signals(int num_signals, pid_t target_pid, int signal_type);
int receive_sig(void);
void handl_sig_answer1(int sig, siginfo_t *inf, void *context);
int receive_result(map_t1 *map);
void handl_sig_answer2(int sig, siginfo_t *inf, void *context);
int receive_digit(void);
int string_to_int(const char *str);
void int_to_letter(void);
int receive_letter(void);
void transf_letter_receive_digit(map_t1 *map);
int send_result2(map_t1 *map);
int send_coordinate(pid_t pid2, map_t1 *map);
int attack2(pid_t pid_player1);
int attack_v2(char letter, int line, map_t1 *maps_p1);
int attack_v3(char letter, int line, map_t1 *maps_p1);
int send_result(map_t1 *map);
int attack_v4(char letter, int line, map_t1 *maps_p1);
int win_or_not(map_t1 *map_p1);
int loose_or_not(map_t1 *map);
int display_win(map_t1 *map_p1);
int display_loose(map_t1 *map_p1);
int my_help(void);
int my_getnbr_c(char const str);
int good_pos(char *filepath);
int diagonal(char *filepath);
int ligne_1(char *ligne);
int same(char *filepath);

#endif /* TEST_H_ */
