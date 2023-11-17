#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void two_player_game()
{
  int sticks=20, player=1, move;
  
  while(sticks > 0)
  {
    printf("Player %d turn\n", player);
    printf("There are %d sticks currently on the board\n", sticks);
    printf("How many stick will you take?\n");
    scanf("%d", &move);

    if(move > 3 || move <= 0)
    {
      printf("invalid move\n");
      continue;
    } else
    {
      sticks -= move;
      if (player == 1)
      {
        player = 2;
      } else
      {
        player = 1;
      }
    }    
  }

  printf("\nGAME OVER\n"
          "Player %d wins\n", player);

}

void one_player_game()
{
  int sticks=20, player=1, move;
  
  while(sticks > 0)
  {

    if (player == 1)
    {
      printf("Player %d turn\n", player);
      printf("There are %d sticks currently on the board\n", sticks);
      printf("How many stick will you take?\n");
      scanf("%d", &move);
      
      if(move > 3 || move <= 0)
      {
        printf("invalid move\n");
        continue;
      } else
      {
        sticks -= move;
        player = 2;
      }    
    } else
    {
      printf("robot turn\n");
      srand(time(0));
      move = (sticks <= 3) ? (sticks-1) : (rand()%3+1);

      printf("robot takes %d sticks\n", move); 
      sticks -= move;
      player = 1;
    }
  }

  printf("\nGAME OVER\n"
          "Player %d wins\n", player);

}


int main()
{

  while (1)
  {

    int mode;
    printf("Welcome to the game of sticks\nselect from the below options\nOnly pick 1 option\n"
            "[1] 2 players\n"
            "[2] 1 player\n"
            "[0] quit\n"
    );
    scanf("%d", &mode);
    switch (mode)
    {
      case 1:
        two_player_game();
        break;
      case 2:
        one_player_game();
        break;
      case 0:
        return 0;
        break;
      default:
        printf("invalid option");
        break;
    }
  }

  return 0;
}