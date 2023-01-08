#include <stdio.h>
#include <unistd.h>

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 25
#define FRAME_RATE 10

struct ball 
{
   char shape;
   int x;
   int y;
   int xVelocity;
   int yVelocity;
};

void initializeScreen(char screen[SCREEN_WIDTH][SCREEN_HEIGHT]);
void printScreen(char screen[SCREEN_WIDTH][SCREEN_HEIGHT]);
void updateScreen(struct ball ball, char screen[SCREEN_WIDTH][SCREEN_HEIGHT]);
void updateBall(struct ball *ball);

int main()
{
   char screen[SCREEN_WIDTH][SCREEN_HEIGHT];
   initializeScreen(screen);

   struct ball ballOne = {'O', 5, 5, 1, 1};
   struct ball ballTwo = {'#', 90, 20, 2, 2};
   struct ball ballThree = {'*', 50, 15, -1, -1};
   struct ball ballFour = {'@', 15, 10, 2, -1};
   struct ball ballFive = {'.', 20, 22, -1, 2};

   while(1)
   {
      initializeScreen(screen);

      updateBall(&ballOne);
      updateBall(&ballTwo);
      updateBall(&ballThree);
      updateBall(&ballFour);
      updateBall(&ballFive);

      updateScreen(ballOne, screen);
      updateScreen(ballTwo, screen);
      updateScreen(ballThree, screen);
      updateScreen(ballFour, screen);
      updateScreen(ballFive, screen);

      printScreen(screen);

      usleep(1000000 / FRAME_RATE);
   }

   return 0;
}

void initializeScreen(char screen[SCREEN_WIDTH][SCREEN_HEIGHT])
{
   for(int i = 0; i < SCREEN_HEIGHT; i++)
   {
      for(int j = 0; j < SCREEN_WIDTH; j++)
      {
         if(i < 1|| i > SCREEN_HEIGHT - 2 || j < 1 || j > SCREEN_WIDTH - 2)
         {
            screen[j][i] = '#'; 
         }
         else 
         {
            screen[j][i] = ' ';
         }
      }
   }
}

void printScreen(char screen[SCREEN_WIDTH][SCREEN_HEIGHT])
{
   for(int i = 0; i < SCREEN_HEIGHT; i++)
   {
      for (int j = 0; j < SCREEN_WIDTH; j++)
      {
        printf("%c", screen[j][i]);  
      }
      printf("\n");
   }
}

void updateScreen(struct ball ball, char screen[SCREEN_WIDTH][SCREEN_HEIGHT])
{
   screen[ball.x][ball.y] = ball.shape;
}

void updateBall(struct ball *ball)
{
   if(ball->x < 2)
   {
      ball->xVelocity = -(ball->xVelocity);
   }
   else if(ball->x > SCREEN_WIDTH - 3)
   {
      ball->xVelocity = -(ball->xVelocity);
   }

   if(ball->y < 2)
   {
      ball->yVelocity = -(ball->yVelocity);
   }
   else if(ball->y > SCREEN_HEIGHT - 3)
   {
      ball->yVelocity = -(ball->yVelocity);
   }

   ball->x += ball->xVelocity;
   ball->y += ball->yVelocity;
}
