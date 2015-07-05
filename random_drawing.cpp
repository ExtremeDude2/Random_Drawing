/***********************************************************/
/*                                                         */
/* Created by Ryan Collins 2014-2015, use at your own risk.*/
/*                                                         */
/***********************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT	24	// Height of a command window
#define WIDTH	80	// Width of a command window

// Declare all possible characters
unsigned char characters[] = { '`', '~', '%', '^', 'v', '*', '(', ')', '-', '_', '=', '+', '[', '{', ']', '}', '\\', '|', ';', ':', '\'', '\"', ',', '<', '.', '>', '/'};

// Declare board as empty to begin
unsigned char board[HEIGHT][WIDTH];

unsigned char save, next;

// Create randomness code here (probably should not use time, but rather something that actually works)
int random(void)
{
	unsigned int r;
	r = rand() % sizeof(characters);
	return characters[r];
}

//
void fillBoard(void)
{
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			board[y][x] = random();
		}
	}
}

// Print the board
void printBoard(FILE * stream)
{
	unsigned int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		if (y == 0) {}
//		else
//			fputc('\n', stream);

		for (x = 0; x < WIDTH; x++)
			fputc(board[y][x], stream);
	}
}

int main(int argc, char* argv[])
{
	FILE * stream;
	unsigned int running = 1;

	if (argc < 2)
		stream = stdout; /* All drawings are done to the console buffer. */
	else
		stream = fopen(argv[1], "w"); /* Drawings are saved to a text file. */

	if (stream == NULL)
		stream = stdout;

	do
	{
		// Write the list of characters randomly to fill the board
		fillBoard();

		// Print the board
		printBoard(stream);

		// Ask user if they want to create another "picture"
		printf("Would you like to create a new picture? Y/N: ");
		do
		{
			std::cin >> next;

			if ((next | 0x20) == 'y')
			{
				running = 1;
				break;
			}
			if ((next | 0x20) == 'n')
			{
				running = 0;
				return 0;	// Close the program
			}
			else
			{
				printf("Error, unknown input, please try again: ");
			}
		} while (1);
	} while (running);
	return 0;
}
