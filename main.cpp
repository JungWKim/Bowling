#include "bowling.h"

short input[21];
short score[10];
bool spare_flag[10];
bool strike_flag[10];
char answer;
bool isValidInput = true;

int main()
{
	while (1)
	{
		initialization(input, score);
		int i;
		for (i = 0; i < 10; i++)
		{
			//until 9th frame
			if (i < 9)
			{
				//first input
				while (1)
				{
					print_score_board(input, score);
					printf("[ type the score of this turn ] >> ");
					scanf_s("%hd", &input[i * 2]);

					short exception = input_range(input[i * 2]);
					if (exception == 1) break;
					else
					{
						input[i * 2] = -1;
						continue;
					}
				}

				//strike
				if (input[i * 2] == 10)
				{
					spare_flag[i] = false;
					strike_flag[i] = true;
					if (i >= 2)
						score_process_until_8th(i, spare_flag, strike_flag, input, score);
					continue;
				}

				//second input
				else
				{
					while (1)
					{
						print_score_board(input, score);
						printf("[ type the score of this turn ] >> ");
						scanf_s("%hd", &input[i * 2 + 1]);

						short exception = input_range(input[i * 2 + 1]);
						if (exception == 1)
						{
							if ((input[i * 2] + input[i * 2 + 1]) > 10)
							{
								input[i * 2 + 1] = -1;
								continue;
							}
							else break;
						}
						else
						{
							input[i * 2 + 1] = -1;
							continue;
						}
					}

					//spare
					if ((input[i * 2] + input[i * 2 + 1]) == 10)
					{
						spare_flag[i] = true;
						strike_flag[i] = false;
					}
					//split
					else
					{
						spare_flag[i] = false;
						strike_flag[i] = false;
					}
				}

				if (i >= 2)
					score_process_until_8th(i, spare_flag, strike_flag, input, score);
			}
			//10th frame
			else
			{
				//10th frame, first input
				while (1)
				{
					print_score_board(input, score);
					printf("[ type the score of this turn ] >> ");
					scanf_s("%hd", &input[i * 2]);

					short exception = input_range(input[i * 2]);
					if (exception == 1) break;
					else
					{
						input[i * 2] = -1;
						continue;
					}
				}

				score_process_until_8th(i, spare_flag, strike_flag, input, score);

				//10th frame, second input
				while (1)
				{
					print_score_board(input, score);
					printf("[ type the score of this turn ] >> ");
					scanf_s("%hd", &input[i * 2 + 1]);

					short exception = input_range(input[i * 2 + 1]);
					if (exception == 1) break;
					else
					{
						input[i * 2 + 1] = -1;
						continue;
					}
				}

				//9th frame score process
				if (strike_flag[i - 1])
				{
					score[i - 1] += score[i - 2] + input[(i - 1) * 2] + input[(i - 1) * 2 + 1] + input[i * 2] + input[i * 2 + 1];
				}
				else if(spare_flag[i - 1])
				{
					score[i - 1] += score[i - 2] + input[(i - 1) * 2] + input[(i - 1) * 2 + 1] + input[i * 2];
				}
				else
				{
					score[i - 1] += score[i - 2] + input[(i - 1) * 2] + input[(i - 1) * 2 + 1];
				}

				if (input[i * 2] + input[i * 2 + 1] >= 10)
				{
					//10th frame, third input
					while (1)
					{
						print_score_board(input, score);
						printf("[ type the score of this turn ] >> ");
						scanf_s("%hd", &input[i * 2 + 2]);

						short exception = input_range(input[i * 2 + 2]);
						if (exception == 1) break;
						else
						{
							input[i * 2 + 2] = -1;
							continue;
						}
					}
				}
				//10th frame score process
				score[i] += score[i - 1] + input[i * 2] + input[i * 2 + 1] + input[i * 2 + 2];
			}
		}

		//ask one more try
		while (1)
		{
			print_score_board(input, score);
			if(isValidInput)
			{
				printf("[Error] Wrong input!!!");
			}
			printf("[ one more use?(y/n) ] >> ");
			scanf_s("%c", &answer, sizeof(answer));
			if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
			{
				isValidInput = true;
				break;
			}
			else
			{
				isValidInput = false;
				continue;
			}
		}

		if (answer == 'y' || answer == 'Y')
			continue;
		else if (answer == 'n' || answer == 'N')
			break;
	}
	return 0;
}