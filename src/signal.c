/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** receive signal and send
*/
#include "my.h"

int send_result(map_t1 *map)
{
    mini_printf("result: %c%d:", game_data.coord_letter, game_data.sig_coord);
    if (game_data.missed == 1) {
        mini_printf("missed\n\n");
        for (int i = 0; i < 2; i++) {
            kill(game_data.pid_player1, SIGUSR1);
            usleep(1000);
        }
        game_data.missed = 0;
    }
    if (game_data.hit == 1) {
        mini_printf("hit\n\n");
        kill(game_data.pid_player1, SIGUSR1);
        usleep(1000);
        game_data.hit = 0;
    }
    kill(game_data.pid_player1, SIGUSR2);
}

int send_result2(map_t1 *map)
{
    mini_printf("result: %c%d:", game_data.coord_letter, game_data.sig_coord);
    if (game_data.missed == 1) {
        mini_printf("missed\n\n");
        for (int i = 0; i < 2; i++) {
            kill(game_data.pid2, SIGUSR1);
            usleep(1000);
        }
        game_data.missed = 0;
    }
    if (game_data.hit == 1) {
        mini_printf("hit\n\n");
        kill(game_data.pid2, SIGUSR1);
        usleep(1000);
        game_data.hit = 0;
    }
    kill(game_data.pid2, SIGUSR2);
}

static void handle_sig_res(int sig, siginfo_t *inf, void *context)
{
    (void)context;
    (void)inf;
    if (sig == SIGUSR1) {
        game_data.var_miss += 1;
    }
    if (sig == SIGUSR2) {
        game_data.signal_received = 1;
        game_data.need_user_input = 1;
    }
}

static void foo_miss(map_t1 *map)
{
    if (game_data.var_miss == 2) {
        mini_printf("result: %c%c:missed\n\n",
            game_data.coord_letter, game_data.coord_digit);
        attack_v2(game_data.coord_letter, game_data.coord_digit, map);
    }
}

int receive_result(map_t1 *map)
{
    struct sigaction sa;

    game_data.var_miss = 0;
    sa.sa_sigaction = handle_sig_res;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
        sigaction(SIGUSR2, &sa, NULL) == -1) {
        return 84;
    }
    while (game_data.signal_received != 1)
        usleep(1000);
    foo_miss(map);
    if (game_data.var_miss == 1) {
        mini_printf("result: %c%c:hit\n\n",
            game_data.coord_letter, game_data.coord_digit);
        attack_v4(game_data.coord_letter, game_data.coord_digit, map);
    }
}

int send_signals(int num_signals, pid_t target_pid, int signal_type)
{
    for (int i = 0; i < num_signals; i++) {
            kill(target_pid, SIGUSR1);
        usleep(1000);
    }
    kill(target_pid, SIGUSR2);
    return 0;
}
