/* February 24, 2022
Topics:  scope and random number
4 types of scope:
block scope(local variable)variables being available from a set of open curly brace to a set of closed curly brace
file scope-global variable-variables that are globally available/can be accessed anywhere in the variable
function scope- local variable-variables that are available only within a particaular function
function prototype
inlcude <time.h>
srand(time(null))
*/
/*Write the C code snippet to generate random numbers in the following ranges:
  a. 14 sxs27
  b. -22 < xs -3
  c. 100 <x S 150
  d. 2, 4, 6, 8, 10
  е. 6, 10, 14, 18, 22, 26, 30
  f. 1, 8, 15, 22
  g. 544, 509, 474, 439, 404
Home Work: Do question 5.31 (Coin Tossing) and 5.32 (Guess the Number) from the text*/

/*(Coin Tossing) Write a program that simulates coin tossing. For each toss of the coin the
program should print Heads or Tails. Let the program toss the coin 100 times, and count the number of times each side of the coin appears. Print the results. The program should call a separate funcion flip that takes no arguments and returns 0 for tails and 1 for heads. [Note: If the program
realistically simulates the coin tossing, then each side of the coin should appear approximately half the time for a total of approximately 50 heads and 50 tails.*/
// 5.31

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();

int flip()
{
  int coin;
  coin = rand() % 2;
  return coin;
}
int main()
{
  int num, coinflip, head = 0, tail = 0;
  srand(time(0));
  printf("Coin Flipping Simulator\n");
  for (int i = 1; i <= 100; i++)
  {
    coinflip = flip();
    if (coinflip == 0)
    {
      printf("Tails\n");
      tail = tail + 1;
      // return 0;
    }
    if (coinflip == 1)
    {
      printf("Heads\n");
      head = head + 1;
      // return 1;
    }
  }
  printf("%d number of heads.\n", head);
  printf("%d number of tails.\n", tail);
}

/*(Guess the Number) Write a C program that plays the game of “guess the number” as follows: Your program chooses the number to be guessed by selecting an integer at random in the range 1 to 1000....contd.*/
// 5.32
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ranNum(int number);

void ranNum(int number)
{
  int ran;
  ran = rand() % 1000 + 1;
  printf("%d. \n", ran);
  if (ran == number)
  {
    printf("Excellent! You guessed the number!\n");
  }
  while (ran != number)
  {
    printf("%d\n", ran);
    if (ran > number)
    {
      printf("Too low. Try again.\n");
    }
    if (ran < number)
    {
      printf("Too high. Try again.\n");
    }
    printf("Guess again. ");
    scanf("%d", &number);
  }
}

int main()
{
  int num, num_2;
  char again;
  printf("I have a number between 1 and 1000. \n");
  printf("Can you guess the number? \n");
  printf("Please type your first guess. ");
  scanf("%d", &num);
  ranNum(num);
  printf("Would you like to play again (y or n)? ");
  scanf(" %c", &again);
  while (again == 'y')
  {
    printf("Guess again. ");
    scanf("%d", &num_2);
    ranNum(num_2);
    printf("Would you like to play again (y or n)? ");
    scanf(" %c", &again);
  }
  return 0;
}