/*
** EPITECH PROJECT, 2023
** muy_navy.c
** File description:
** player 2
*/
#include "my.h"

game_data_t game_data = {.connected = 0, .signal_received = 0,
    .sig_coord = 0, .win = 0, .loose = 0, .need_user_input = 0,
    .type_sig = 0, .missed = 0, .hit = 0, .var_miss = 0, .filepath_1 = NULL,
    .filepath_2 = NULL};

static int wrong_pos2(const char *input, pid_t pid_player1)
{
    if ((input[0] < 'A' || input[0] > 'H') ||
        (input[1] < 49 || input[1] > 56) || (my_strlen(input) != 3)) {
        mini_printf("\nwrong position\n\n");
        game_data.coord_digit = 0;
        game_data.coord_letter = 0;
        attack2(pid_player1);
        return 4;
    }
    return 0;
}

int transform(void)
{
    game_data.coord_letter = 'A' + (game_data.sig_coord - 1);
}

int error_read(const char *input, ssize_t read)
{
    if (read == -1 || input[0] == '\n') {
        mini_printf("error\n");
        mini_printf("error\n");
        game_data.coord_digit = 0;
        game_data.coord_letter = 0;
        usleep(500000);
        attack2(game_data.pid2);
        return 4;
    }
    return 0;
}

int attack2(pid_t pid_player1)
{
    char *input = NULL;
    int row;
    int col;
    size_t len = 0;
    ssize_t read;

    mini_printf("attack: ");
    read = getline(&input, &len, stdin);
    if (error_read(input, read) == 4)
        return 84;
    if (wrong_pos2(input, pid_player1) == 4)
        return 0;
    col = input[0] - 'A' + 1;
    row = input[1] - '0';
    game_data.coord_digit = input[1];
    game_data.coord_letter = input[0];
    free(input);
    send_signals(col, pid_player1, SIGUSR1);
    send_signals(row, pid_player1, SIGUSR1);
    mini_printf("\n");
}

void transf_letter_receive_digit(map_t1 *map)
{
    if (game_data.need_user_input != 1) {
        transform();
        game_data.sig_coord = 1;
        receive_digit();
        attack(game_data.coord_letter, game_data.sig_coord, map);
        send_result(map);
    }
}

static void connection_with_player1(pid_t pid_player1, pid_t pid2)
{
    mini_printf("my_pid: %d\n\n", pid2);
    game_data.pid_player1 = pid_player1;
    kill(pid_player1, SIGUSR1);
    mini_printf("successfully connected to enemy\n\n");
}

static void receive_coord_and_display_loose(map_t1 *map_p2)
{
    receive_letter();
    transf_letter_receive_digit(map_p2);
}

int player2(int argc, char **argv)
{
    pid_t pid_player1 = string_to_int(argv[1]);
    pid_t pid2 = getpid();
    map_t1 *map_p2 = create_struct_map(game_data.filepath_2);

    connection_with_player1(pid_player1, pid2);
    while (game_data.win != 1 || game_data.loose == 1) {
        display_map(map_p2);
        mini_printf("\nwaiting for enemy's attack...\n\n");
        game_data.sig_coord = 0;
        receive_coord_and_display_loose(map_p2);
        if (display_loose(map_p2) == 1)
            return 1;
        if (attack2(pid_player1) == 84)
            return 84;
        game_data.signal_received = 0;
        game_data.need_user_input = 0;
        receive_result(map_p2);
        if (display_win(map_p2) == 1)
            return 0;
    }
}
