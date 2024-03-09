/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** tg
*/
#include "my.h"

void handl_sig_answer2(int sig, siginfo_t *inf, void *context)
{
    (void)context;
    (void)inf;
    if (sig == SIGUSR1) {
        game_data.sig_coord += 1;
        game_data.need_user_input = 0;
    }
    if (sig == SIGUSR2) {
        game_data.signal_received = 1;
        game_data.need_user_input = 1;
        game_data.type_sig = 0;
    }
}

int receive_digit(void)
{
    struct sigaction sa;

    game_data.signal_received = 0;
    game_data.type_sig = 0;
    sa.sa_sigaction = handl_sig_answer2;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
        sigaction(SIGUSR2, &sa, NULL) == -1)
        return 84;
    while (game_data.signal_received != 1)
        usleep(1);
}

void handl_sig_answer(int sig, siginfo_t *inf, void *context)
{
    (void)context;
    (void)inf;
    if (sig == SIGUSR1) {
        game_data.sig_coord += 1;
        game_data.need_user_input = 0;
    }
    if (sig == SIGUSR2) {
        game_data.signal_received = 1;
        game_data.need_user_input = 1;
        game_data.type_sig = 1;
    }
}

int receive_letter()
{
    struct sigaction sa;

    game_data.signal_received = 0;
    game_data.type_sig = 0;
    sa.sa_sigaction = handl_sig_answer;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
        sigaction(SIGUSR2, &sa, NULL) == -1)
        return 84;
    while (game_data.signal_received != 1)
        usleep(1);
}
