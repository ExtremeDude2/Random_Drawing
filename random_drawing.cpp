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
void printBoard(void)
{
	unsigned int x, y;
	for (y = 0; y < HEIGHT; y++)
	{
		if (y == 0) {}
		//else
		//	putchar('\n');

		for (x = 0; x < WIDTH; x++)
			putchar(board[y][x]);
	}
}


// Add code to save "picture" (.txt) to file
void saveToFile(void)
{
	return;
}


int main()
{
	unsigned int running = 1;

	do
	{
		// Write the list of characters randomly to fill the board
		fillBoard();

		// Print the board
		printBoard();

		// Ask user if they want to save the "picture" to a file
		printf("Would you like to save the current picture to a file? Y/N: ");
		do
		{
			std::cin >> save;

			if ((save | 0x20) == 'y')
			{
				saveToFile();
				printf("File saved as \"random_drawing.txt\" in same folder as the program.\n");
				break;
			}
			else if ((save | 0x20) == 'n')
			{
				break;
			}
			else
			{
				printf("Error, unknown input, please try again: ");
			}
		} while (1);

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
