/*
  program.c
  Name: Kristian Welsh
  Candidate Number: 
  Description:
  A program that keeps track of tabel tenis scores.
  xx/xx/xxxx
*/

#include <stdio.h>
#include <string.h>

struct player
{
  char name[33];
};

struct match
{
  struct player player1;
  struct player player2;
  int p1Scores[5];
  int p2Scores[5];
};

struct round
{
  struct match matches[8];
  struct player playersAdvancing[8];
};

void haltProgram(void);
void userInputPlayerNames(struct player players[]);
void displayPlayerNames(struct player players[]);
void displayMenuScreen(void);
void displayRound(int);
int getMenuSelection(void);
void clearInputBuffer(void);
void displayMatch(int);

int main(void)
{
  struct player players[5];
  struct round round1, round2, round3;

  puts("Max player name length: 32");
  userInputPlayerNames(players);
  displayPlayerNames(players);
  haltProgram();
  displayMenuScreen();
  getMenuSelection();
  printf("\n\n");
  displayRound(1);
  haltProgram();
}

void userInputPlayerNames(struct player players[])
{
  int index;

  for(index = 0; index < 5; index++)
  {
    printf("Please enter name for player %d: ", index);
    scanf("%32[^\n]", players[index].name);
  }
}

void displayPlayerNames(struct player players[])
{
  int index;

  for(index = 0; index < 5; index++)
  {
    printf("name of player %d: %s\n", index, players[index].name);
  }
}

void haltProgram(void)
{
  char pausePorgramChar;

  printf("Press any key to continue...");
  scanf("%c", &pausePorgramChar);
}

void displayMenuScreen(void)
{
  printf("* Menu *\n"
         "1. Enter a game result\n"
         "2. Display current round\n"
         "3. Display players advancing\n"
         "4. Display Previous Round\n"
         "5. Exit\n"
         "Please enter menu selection: ");
}

int getMenuSelection(void)
{
  int input;
  scanf("%d", &input);
  return input;
}

void displayRound(int roundNumber)
{
  printf("* Display Round Results *\n"
         "\n"
         "Results for round %d:\n"
         "\n", roundNumber);
  displayMatch(1);
}

void displayMatch(int matchNumber)
{
  printf("Match %d:\n"
         "+-----------------------------+\n"
         "| %32s |%2d|%2d|%2d|%2d|%2d|\n"
         "+-----------------------------+\n"
         "\n", matchNumber, "name here", 1, 2, 3, 4, 5);
}

void clearInputBuffer(void)
{
  char token;
  do
  {
    token = getchar();
  } while(token != '\n' && token != '\r' && token != EOF);
}
