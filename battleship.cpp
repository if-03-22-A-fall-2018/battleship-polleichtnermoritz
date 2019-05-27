/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>

#include "battleship.h"
#define SIZE 10
static CellContent myField[SIZE][SIZE];
static CellContent enemyField[SIZE][SIZE];
static CellContent myGuesses[SIZE][SIZE];

void load_game()
{
  FILE *my_fd = fopen("battleship.my", "r+");
  FILE *op_fd = fopen("battleship.op", "r+");

  for (int i = 0; i < FIELDSIZE ; i++)
  {
    for (int j = 0; j < FIELDSIZE; j++)
    {
      fread(&myField[i][j], 4, 1, my_fd);
      fread(&enemyField[i][j], 4, 1, op_fd);
      myGuesses[i][j] = Unknown;
    }
  }
  fclose(my_fd);
  fclose(op_fd);
}

CellContent get_shot(int row, int col)
{
  if (row < 0 || row >= FIELDSIZE || col < 0 || col >= FIELDSIZE)
  {
    return OutOfRange;
  }
  return myField[row][col];
}

bool shoot(int row, int col)
{
  if(!(row> -1 && row< SIZE && col>-1&&col<SIZE ))
  {
    return false;
  }

  for (int i = -1; i <= 1; ++i)
  {
      for (int j = -1; j <= 1; ++j)
      {
            if(row+i> -1 && row+i< SIZE && col+j>-1&&col+j<SIZE)
            {
              myGuesses[row+i][col+j] = enemyField[row+i][col+j];
            }
      }
  }
      return true;
}

CellContent get_my_guess(int row, int col)
{
  if (row < 0 || row >= FIELDSIZE || col < 0 || col >= FIELDSIZE)
  {
    return OutOfRange;
  }

  return myGuesses[row][col];
}
