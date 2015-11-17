/* program.c Name: Kristian Welsh Candidate Num: 
  Description:
  A program that keeps track of tabel tenis scores.
  xx/xx/xxxx
*/

/*https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c*/
/* dude, remember about ^N when editing. */

#include <stdio.h>
#include <string.h>

#define NUM_ROUND_1_MATCHES 8
#define NUM_GAMES_PER_MATCH 5

struct player
{
  char name[33];
};

struct match
{
  struct player player1;
  struct player player2;
  int p1Scores[NUM_GAMES_PER_MATCH];
  int p2Scores[NUM_GAMES_PER_MATCH];
  int gamesPlayed;
  int matchNum;
};

struct round
{
  struct match matches[NUM_ROUND_1_MATCHES];
  struct player playersAdvancing[NUM_ROUND_1_MATCHES];
  int roundNum;
};

struct data
{
  struct round rounds[3];
  int currentRound;
};

struct round userInputPlayerNames();
void displayPlayerNames(struct round round1);
void displayMenuScreen(void);
struct round displayRound(struct round round);

int getMenuSelection(void);
struct data switchScreen(int input, struct data);
struct round enterGameResult(struct round round);
struct match displayMatch(struct match match);
void displayPlayersAdvancing(int);

void clearInputBuffer(void);
void haltProgram(void);

int main(void)
{
  struct data data;
  int screenNum;

  puts("Max player name length: 32");
  data.rounds[0] = userInputPlayerNames();
  data.currentRound = 0;

  haltProgram();

  while(screenNum != 5)
  {
    displayMenuScreen();
    screenNum = getMenuSelection();

    printf("\n\n");
    data = switchScreen(screenNum, data);
  }

  return 0;
}

struct round userInputPlayerNames()
{
  int matchNum;
  struct match curMatch;
  int playerNum = 1;
  struct round round1;
  int scoreNum;

  for(matchNum = 0; matchNum < NUM_ROUND_1_MATCHES; matchNum++)
  {
    curMatch = round1.matches[matchNum];
    printf("Please enter name for player %d: ", playerNum++);
    scanf("%32[^\n]", curMatch.player1.name);
    clearInputBuffer();

    printf("Please enter name for player %d: ", playerNum++);
    scanf("%32[^\n]", curMatch.player2.name);
    clearInputBuffer();

    curMatch.gamesPlayed = 0;
    curMatch.matchNum = matchNum;
    round1.matches[matchNum] = curMatch;

    for(scoreNum = 0; scoreNum < NUM_GAMES_PER_MATCH; scoreNum++)
    {
      round1.matches[matchNum].p1Scores[scoreNum] = -1;
      round1.matches[matchNum].p2Scores[scoreNum] = -1;
    }
  }

  round1.roundNum = 1;

  return round1;
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
  clearInputBuffer();
  return input;
}

struct data switchScreen(int input, struct data data)
{
  int curRound = data.currentRound;
  switch(input)
  {
    case 1:
      data.rounds[curRound] = enterGameResult(data.rounds[curRound]);
      break;
    case 2:
      displayRound(data.rounds[curRound]);
      break;
    case 3:
      displayPlayersAdvancing(curRound);
      break;
    case 4:
      if(curRound >= 1)
      {
        data.rounds[curRound] = displayRound(data.rounds[curRound-1]);
      }
      break;
  }
  return data;
}

struct round enterGameResult(struct round round)
{
  int matchNum;
  struct match curMatch;
  int player1Score;
  int player2Score;

  printf("Entering a result for round %d:\n"
         "\n"
         "Enter match number to add game results to: ", round.roundNum);
  scanf("%d", &matchNum);
  matchNum--;
  curMatch = round.matches[matchNum];


  /* matchFinished not implemented 
  if(matchFinished(match))
  {
    printf("Match has already finished");
    return round;
  }
*/
  printf("Please enter %s's score: ", curMatch.player1.name);
  scanf("%d", &player1Score);
  curMatch.p1Scores[curMatch.gamesPlayed] = player1Score;

  printf("Please enter %s's score: ", curMatch.player2.name);
  scanf("%d", &player2Score);
  curMatch.p2Scores[curMatch.gamesPlayed] = player2Score;

  curMatch.gamesPlayed++;

  round.matches[matchNum] = curMatch;

  return round;
}

struct round displayRound(struct round round)
{
  int matchNum;

  printf("* Display Round Results *\n"
         "\n"
         "Results for round %d:\n"
         "\n", round.roundNum);

  for(matchNum = 0; matchNum < NUM_ROUND_1_MATCHES; matchNum++)
  {
    displayMatch(round.matches[matchNum]);
  }

  return round;
}

struct match displayMatch(struct match match)
{
  int curScore;
  char p1Scores[NUM_GAMES_PER_MATCH][3] = {
    "  ",
    "  ",
    "  ",
    "  ",
    "  "};
  char p2Scores[NUM_GAMES_PER_MATCH][3] = {
    "  ",
    "  ",
    "  ",
    "  ",
    "  "};

  for(curScore = 0; curScore < NUM_GAMES_PER_MATCH; curScore++)
  {
    if(match.p1Scores[curScore] == -1)
    {
      strcpy(p1Scores[curScore], "xx");
    }
    else
    {
      itoa(match.p1Scores[curScore], p1Scores[curScore], 10);
    }
  }

  for(curScore = 0; curScore < NUM_GAMES_PER_MATCH; curScore++)
  {
    if(match.p2Scores[curScore] == -1)
    {
      strcpy(p2Scores[curScore], "xx");
    }
    else
    {
      itoa(match.p2Scores[curScore], p2Scores[curScore], 10);
    }
  }

  printf("Match %d:\n"
         "+-------------------------------------------------+\n"
         "| %32s |%2s|%2s|%2s|%2s|%2s|\n"
         "+-------------------------------------------------+\n"
         "| %32s |%2s|%2s|%2s|%2s|%2s|\n"
         "+-------------------------------------------------+\n"
         "\n", match.matchNum + 1,
         match.player1.name, p1Scores[0], p1Scores[1],
         p1Scores[2], p1Scores[3], p1Scores[4],
         match.player2.name, p2Scores[0], p2Scores[1],
         p2Scores[2], p2Scores[3], p2Scores[4]);
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
