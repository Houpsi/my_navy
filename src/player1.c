/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** player 1
*/
#include "my.h"

static int wrong_pos(const char *input, map_t1 *map)
{
    if ((input[0] < 'A' || input[0] > 'H') ||
        (input[1] < 49 || input[1] > 56) || (my_strlen(input) != 3)) {
        mini_printf("\nwrong position\n");
        game_data.coord_digit = 0;
        game_data.coord_letter = 0;
        send_coordinate(game_data.pid2, map);
        return 4;
    }
    return 0;
}

int error_read_line(map_t1 *map, const char *input, ssize_t read)
{
    if (read == -1 || input[0] == '\n' || my_strlen(input) == 0) {
        mini_printf("error\n");
        game_data.coord_digit = 0;
        game_data.coord_letter = 0;
        return 4;
    }
    return 0;
}

static void put_in_var(const char *input, int *row, int *col)
{
    (*col) = input[0] - 'A';
    (*row) = input[1] - '0';
}

int send_coordinate(pid_t pid2, map_t1 *map)
{
    char *input = NULL;
    int row;
    int col;
    size_t len = 0;
    ssize_t read;

    mini_printf("\nattack: ");
    read = getline(&input, &len, stdin);
    if (error_read_line(map, input, read) == 4)
        return 84;
    if (wrong_pos(input, map) == 4)
        return 0;
    put_in_var(input, &row, &col);
    game_data.coord_digit = input[1];
    game_data.coord_letter = input[0];
    free(input);
    send_signals(col, pid2, SIGUSR1);
    send_signals(row, pid2, SIGUSR1);
    mini_printf("\n");
    return 0;
}

void display_map(map_t1 *map)
{
    mini_printf("my navy:\n");
    for (int i = 0; i < 10; ++i) {
        mini_printf("%s", map->map_boat_mine[i]);
    }
    mini_printf("\nenemy navy:\n");
    for (int i = 0; i < 10; ++i) {
        mini_printf("%s", map->map_attack[i]);
    }
}

static void receive_coord(void)
{
    receive_letter();
    transform();
    game_data.sig_coord = 1;
    receive_digit();
}

int principal_loop(void)
{
    map_t1 *map_p1 = create_struct_map(game_data.filepath_1);

    while (game_data.win != 1 || game_data.loose == 1) {
        display_map(map_p1);
        if (send_coordinate(game_data.pid2, map_p1) == 84)
            return 84;
        game_data.signal_received = 0;
        game_data.need_user_input = 0;
        receive_result(map_p1);
        if (display_win(map_p1) == 1)
            return 0;
        mini_printf("waiting for enemy's attack...\n\n");
        game_data.sig_coord = -1;
        receive_coord();
        attack(game_data.coord_letter, game_data.sig_coord, map_p1);
        send_result2(map_p1);
        if (display_loose(map_p1) == 1)
            return 1;
    }
}

static void gestionnaire(int num_sig, siginfo_t *info, void *rien)
{
    mini_printf("enemy connected\n\n");
    game_data.pid2 = info->si_pid;
    if (num_sig == SIGUSR1)
        game_data.connected = 1;
}

static int connection(void)
{
    struct sigaction sa;

    sa.sa_sigaction = gestionnaire;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        return 84;
    while (!game_data.connected) {
        usleep(1);
    }
    return 0;
}

int player1(int argc, char **argv)
{
    pid_t pid = getpid();

    mini_printf("my_pid: %d\n\n", pid);
    mini_printf("waiting for enemy...\n\n");
    connection();
    return principal_loop();
}
