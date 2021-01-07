#pragma once
#include <stdio.h>
#include <windows.h>

#define RED   12
#define WHITE 15

void print_score_board(short* input, short* score);
void initialization(short* input, short* score);
void score_process_until_8th(int i, bool* spare_flag, bool* strike_flag, short* input, short* score);
short input_range(short input);
