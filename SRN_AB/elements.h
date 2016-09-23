#ifndef ELEMENTS_H
#define ELEMENTS_H

#define POWER_UP_HEART             0
#define POWER_UP_SHIELD            1
#define POWER_UP_TRIDENT           2
#define POWER_UP_BUBBLE            3
#define POWER_UP_SEASHELL          4
#define POWER_UP_MAGIC             5
#define POWER_UP_STAR              6


#include <Arduino.h>
#include "globals.h"

int powerUpArrayX[] = {128, 320, 256, 192};
byte powerUpArrayY[] = {11, 47, 23, 41, 35, 29, 17, 53};

struct Background
{
  public:
    int x;
};

struct Elements
{
  public:
    int x;
    byte y;
    byte type;
    boolean isVisible;
    boolean isActive;
};

struct Bonus
{
  public:
    byte x;
    byte y;
    int amount;
    boolean isVisible;
    boolean isActive;
};

Background Column[3];
Elements powerUP;
Bonus bonus[MAX_ONSCREEN_ENEMIES];


void setBackground()
{
  backgroundIsVisible = true;
  Column[0].x = 28;
  Column[1].x = 92;
  Column[3].x = 128;
}

void checkBackground()
{
  if (arduboy.everyXFrames(10))
  {
    Column[0].x--;
    Column[1].x--;
  }
  if (arduboy.everyXFrames(3)) Column[2].x--;

  if (Column[0].x < -8) Column[0].x = 128;
  if (Column[1].x < -8) Column[1].x = 128;
  if (Column[2].x < -16) Column[2].x = 128;
}

void checkPowerUP()
{
  if (powerUP.isActive)
  {
    if (arduboy.everyXFrames(5)) powerUP.isVisible = !powerUP.isVisible;
    if (arduboy.everyXFrames(2)) powerUP.x--;
    if (powerUP.x < -8) powerUP.isActive = false;
  }
}


void checkBonus()
{
  for (byte i = 0; i < MAX_ONSCREEN_ENEMIES; ++i)
  {
    if (bonus[i].isActive)
    {

    }
  }
}


void giveBonus()
{
  for (byte i = 0; i < MAX_ONSCREEN_ENEMIES; ++i)
  {
    
  }
}


void powerUPSet(byte type)
{
  powerUP.isActive = true;
  powerUP.x = powerUpArrayX[powerUpSelectorX];
  powerUP.y = powerUpArrayY[powerUpSelectorY];
  powerUP.type = type;
  powerUpSelectorX = (++powerUpSelectorX) % 4;
  powerUpSelectorX = (++powerUpSelectorY) % 8;
}

void drawBackground()
{
  if (backgroundIsVisible)
  {
    for (byte z = 0; z < 2; z++)
    {
      for (byte i = 0; i < 3; i++)
      {
        sprites.drawSelfMasked(28 + (z * 15) + (8 * i), (8 * i), sunRay, i);
      }
    }
    sprites.drawPlusMask(Column[0].x, 20, columnSmall_plus_mask, 0);
    sprites.drawPlusMask(Column[1].x, 20, columnSmall_plus_mask, 0);
    sprites.drawPlusMask(Column[2].x, 18, columnBig_plus_mask, 0);
    sprites.drawPlusMask(Column[2].x + 8, 18, columnSmall_plus_mask, 0);
  }
}


void drawPowerUP()
{
  if (powerUP.isActive && powerUP.isVisible) sprites.drawPlusMask(powerUP.x, powerUP.y, powerUP_plus_mask, powerUP.type);
}


void drawBonus()
{
  for (byte i = 0; i < MAX_ONSCREEN_ENEMIES; ++i)
  {
    if (bonus[i].isActive && bonus[i].isVisible)
    {

    }
  }
}


#endif
