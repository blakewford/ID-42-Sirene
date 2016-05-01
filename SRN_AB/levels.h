#ifndef LEVELS_H
#define LEVELS_H

#include <Arduino.h>
#include "globals.h"
#include "enemies.h"

#define WAVE_SPEED             3
#define WAVE_DURATION          128

boolean checkWaveStart()
{
  if (currentWave != previousWave)
  {
    previousWave = currentWave;
    return true;
  }
  return false;
}

boolean checkEndWave()
{
  byte test = 0; 
  for (byte i = 0; i < ARRAY_MAX_AMOUNT; i++)
  {
    test = test + enemy[i].isActive;
  }
  if (test < 1) currentWave++;
}

void enemySetInLine(byte firstEnemy, byte lastEnemy, byte x, byte y, int spacingX, int spacingY)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    enemy[i].isActive = true;
    enemy[i].x = x + (spacingX * (i - firstEnemy));
    enemy[i].y = y + (spacingY * (i - firstEnemy));
    enemy[i].HP = 2;
  }
}

void enemySwimLeftRight(byte firstEnemy, byte lastEnemy, byte speedEnemy)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    enemy[i].x = enemy[i].x - speedEnemy;
  }
}

void enemySwimToMiddle(byte firstEnemy, byte lastEnemy, byte speedEnemy)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    enemy[i].x = enemy[i].x - speedEnemy;
    if (enemy[i].x < 64)
    {
      if (enemy[i].y < 31) enemy[i].y++;
      if (enemy[i].y > 32) enemy[i].y--;
    }
  }
}

void enemySwimSine(byte firstEnemy, byte lastEnemy, byte speedEnemy)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    enemy[i].x = enemy[i].x - speedEnemy;
    if ((enemy[i].x < 120 ) && (enemy[i].x > 104) && (enemy[i].y > 16)) enemy[i].y--;
    if ((enemy[i].x < 105) && (enemy[i].x > 73) && (enemy[i].y < 48)) enemy[i].y++;
    if ((enemy[i].x < 74 ) && (enemy[i].x > 42) && (enemy[i].y > 16)) enemy[i].y--;
    if ((enemy[i].x < 43) && (enemy[i].x > 10) && (enemy[i].y < 48)) enemy[i].y++;
    if ((enemy[i].x < 11) && (enemy[i].y > 16)) enemy[i].y--;
  }
}

void enemySwimDownUp(byte firstEnemy, byte lastEnemy, byte speedEnemy)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    if (enemy[i].frame > 4 && enemy[i].frame < 7 )enemy[i].y = enemy[i].y - speedEnemy - 1;
    if (enemy[i].frame > 6 )enemy[i].y = enemy[i].y - speedEnemy;
  }
}

void wave000()
{
}

void wave001()
{
  if (checkWaveStart())enemySetInLine(0, MAX_ONSCREEN_FISHY, 128, 12, 20, 0);
  enemySwimLeftRight(0, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave002()
{
  if (checkWaveStart())enemySetInLine(0, MAX_ONSCREEN_FISHY, 128, 32, 20, 0);
  enemySwimLeftRight(0, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave003()
{
  if (checkWaveStart())enemySetInLine(0, MAX_ONSCREEN_FISHY, 128, 56, 20, 0);
  enemySwimLeftRight(0, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave004()
{
  if (checkWaveStart())enemySetInLine(0, MAX_ONSCREEN_FISHY, 128, 12, 20, 0);
  enemySwimToMiddle(0, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave005()
{
  if (checkWaveStart())enemySetInLine(0, MAX_ONSCREEN_FISHY, 128, 56, 20, 0);
  enemySwimToMiddle(0, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave006()
{
  if (checkWaveStart())enemySetInLine(0, MAX_ONSCREEN_FISHY, 128, 32, 20, 0);
  enemySwimSine(0, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave007()
{
  if (checkWaveStart())enemySetInLine(0, 1, 128, 12, 0, 0);
  enemySwimLeftRight(0, 1, 1);
  checkEndWave();
}

void wave008()
{
  if (checkWaveStart())enemySetInLine(0, 1, 128, 32, 0, 0);
  enemySwimLeftRight(0, 1, 1);
  checkEndWave();
}

void wave009()
{
  if (checkWaveStart())enemySetInLine(0, 1, 128, 56, 0, 0);
  enemySwimLeftRight(0, 1, 1);
  checkEndWave();
}

void wave010()
{
  if (checkWaveStart())enemySetInLine(0, 1, 128, 12, 0, 0);
  enemySwimLeftRight(0, 1, 2);
  checkEndWave();
}

void wave011()
{
  if (checkWaveStart())enemySetInLine(0, 1, 128, 32, 0, 0);
  enemySwimLeftRight(0, 1, 2);
  checkEndWave();
}

void wave012()
{
  if (checkWaveStart())enemySetInLine(0, 1, 128, 56, 0, 0);
  enemySwimLeftRight(0, 1, 2);
  checkEndWave();
}

void wave013()
{
  if (checkWaveStart())enemySetInLine(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 96, 64, -40, 16);
  enemySwimDownUp(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 1);
  checkEndWave();
}

void wave014()
{
  if (checkWaveStart())enemySetInLine(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 16, 64, 40, 16);
  enemySwimDownUp(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 1);
  checkEndWave();
}

void wave015()
{
  if (checkWaveStart())enemySetInLine(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 16, 64, 40, 0);
  enemySwimDownUp(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 1);
  checkEndWave();
}

void wave016()
{
  if (checkWaveStart())enemySetInLine(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS - 1, 32, 64, 48, 0);
  enemySwimDownUp(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS - 1, 1);
  checkEndWave();
}



typedef void (*FunctionPointer) ();

FunctionPointer Level01[] = {
 // wave000,
  wave001,
  wave002,
  wave003,
  wave004,
  wave005,
  wave006,
  wave007,
  wave008,
  wave009,
  wave010,
  wave011,
  wave012,
  wave013,
  wave014,
  wave015,
  wave016,
};

FunctionPointer Level02[] = {
  wave000,
  wave016,
  wave015,
  wave014,
  wave013,
  wave012,
  wave011,
  wave010,
  wave009,
  wave008,
  wave007,
  wave006,
  wave005,
  wave004,
  wave003,
  wave002,
  wave001,
  wave000,
};


void updateLevel()
{
  if (arduboy.everyXFrames(WAVE_SPEED))waveDuration++;
  if (waveDuration > WAVE_DURATION)
  {
    waveDuration = 0;
    currentWave++;
  }
  if (currentWave > levelSize) currentWave = levelSize;
}

void calculateLevelSize()
{
  switch (level)
  {
    case 1:
      levelSize = sizeof(Level01) / sizeof(Level01[0]) - 1;
      break;
    case 2:
      levelSize = sizeof(Level02) / sizeof(Level02[0]) - 1;
      break;
  }
}

#endif