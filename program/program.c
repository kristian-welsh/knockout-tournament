/*
  program.c
  Name: Kristian Welsh
  Candidate Num: 
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

struct round userInputPlayerNames();
void displayPlayerNames(struct round round1);
void displayMenuScreen(void);
void displayRound(int);

int getMenuSelection(void);
int switchScreen(int);
void enterGameResult(int);
void displayMatch(int);
void displayPlayersAdvancing(int);

void clearInputBuffer(void);
void haltProgram(void);

int main(void)
{
  struct player players[5];
  struct round round1, round2, round3;
  int shouldExit;

  puts("Max player name length: 32");
  round1 = userInputPlayerNames();

  haltProgram();

  displayMenuScreen();
  getMenuSelection();

  printf("\n\n");
  switchScreen(1);

  haltProgram();
}

struct round userInputPlayerNames()
{
  int matchNum;
  int matchPlayerNum;
  int playerNum = 1;
  struct round round1;

  for(matchNum = 0; matchNum < 8; matchNum++)
  {
    printf("Please enter name for player %d: ", playerNum++);
    scanf("%32[^\n]", round1.matches[matchNum].player1.name);
    clearInputBuffer();

    printf("Please enter name for player %d: ", playerNum++);
    scanf("%32[^\n]", round1.matches[matchNum].player2.name);
    clearInputBuffer();
  }
  return round1;
}

/* unused atm */
void displayPlayerNames(struct round round1)
{
  int matchNum;
  int playerNum = 1;
  struct match match;

  for(matchNum = 0; matchNum < 8; matchNum++)
  {
    match = round1.matches[matchNum];
    printf("name of player %d: %s\n",
           playerNum++, match.player1.name);
    printf("name of player %d: %s\n",
           playerNum++, match.player2.name);
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

int switchScreen(int input)
{
  switch(input)
  {
    case 1:
      enterGameResult(1);/*enter game result*/
      break;
    case 2:
      displayRound(1);/*display current round*/
      break;
    case 3:
      displayPlayersAdvancing(1);/*display advancing*/
      break;
    case 4:
      displayRound(1);/*display previous round*/
      break;
    case 5:
      return 1;
  }
  return 0;
}

void enterGameResult(int roundNum)
{
  int matchNum;
  int player1Score;
  int player2Score;

  printf("Entering a result for round %d:\n"
         "\n"
         "Enter match number to add game results to: ", roundNum);
  scanf("%d", &matchNum);
  clearInputBuffer();
  printf("Please enter %s's score: ", "bob");
  scanf("%d", &player1Score);
  printf("Please enter %s's score: ", "bill");
  scanf("%d", &player2Score);
}

void displayRound(int roundNum)
{
  printf("* Display Round Results *\n"
         "\n"
         "Results for round %d:\n"
         "\n", roundNum);
  displayMatch(1);
}

void displayMatch(int matchNum)
{
  printf("Match %d:\n"
         "+-----------------------------+\n"
         "| %32s |%2d|%2d|%2d|%2d|%2d|\n"
         "+-----------------------------+\n"
         "\n", matchNum, "name here", 1, 2, 3, 4, 5);
}

void displayPlayersAdvancing(int roundNum)
{
  int i;

  printf("Players advancing from round %d:", roundNum);
  for(i = 0; i < 5; i++)
  {
    printf("%s\n", "bob");
  }
}

void clearInputBuffer(void)
{
  /*
  fflush(stdin);
  /**/
  char token;
  do
  {
    token = getchar();
  } while(token != '\n' && token != '\r' && token != EOF);
  /**/
}
