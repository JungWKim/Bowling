#include "bowling.h"

void print_score_board(short* input, short* score)
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);

	printf("*******************************************************************************************************************************\n");
	printf("\n");
	printf("                                           !!! Welcome to bowling world !!!\n");
	printf("\n");
	printf("*******************************************************************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("|-----------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|  <  1  >  |  <  2  >  |  <  3  >  |  <  4  >  |  <  5  >  |  <  6  >  |  <  7  >  |  <  8  >  |  <  9  >  |    <  10  >     |\n");
	printf("|-----------------------------------------------------------------------------------------------------------------------------|\n");
	for (short i = 0; i < 21; i++)
	{
		if(input[i] == -1)
			printf("|  -  ");
		else
			printf("| %3d ", input[i]);
	}
	printf("|\n");
	printf("|-----------------------------------------------------------------------------------------------------------------------------|\n");
	for (short i = 0; i < 9; i++)
	{
		if(score[i] == -1)
			printf("|     -     ");
		else
			printf("|    %3d    ", score[i]);
	}
	if (score[9] == -1)
	{
		printf("|        -        ");
	}
	else
	{
		printf("|       %3d       ", score[9]);
	}
	printf("|\n");
	printf("|-----------------------------------------------------------------------------------------------------------------------------|\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("\n");
}

void initialization(short* input, short* score)
{
	for (int i = 0; i < 21; i++)
		input[i] = -1;
	
	for (int i = 0; i < 10; i++)
		score[i] = -1;
}

void score_process_until_8th(int i, bool* spare_flag, bool* strike_flag, short* input, short* score)
{
	if (i >= 3)
		score[i - 2] += score[i - 3];

	if (strike_flag[i - 2])
	{
		if (strike_flag[i - 1])
		{
			score[i - 2] += input[(i - 2) * 2] + input[(i - 2) * 2 + 1] + input[(i - 1) * 2] + input[i * 2];
		}
		else
		{
			score[i - 2] += input[(i - 2) * 2] + input[(i - 2) * 2 + 1] + input[(i - 1) * 2] + input[(i - 1) * 2 + 1];
		}
	}
	else if (spare_flag[i - 2])
	{
		score[i - 2] += input[(i - 2) * 2] + input[(i - 2) * 2 + 1] + input[(i - 1) * 2];
	}
	else
	{
		score[i - 2] += input[(i - 2) * 2] + input[(i - 2) * 2 + 1];
	}
}

short input_range(short input)
{
	if (input < 0 || input > 10)
		return 0;
	else return 1;
}
