#include "2eggs.h"
#include <bits/stdc++.h>
using namespace std;
int height_threshold(int N, int Q)
{
  bool die;
  die = drop_egg(1, 15);
  if (die)
  {
    for (int i = 1; i <= 14; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 15;
  }
  die = drop_egg(1, 29);
  if (die)
  {
    for (int i = 16; i <= 28; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 29;
  }
  die = drop_egg(1, 42);
  if (die)
  {
    for (int i = 30; i <= 41; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 42;
  }
  die = drop_egg(1, 54);
  if (die)
  {
    for (int i = 43; i <= 53; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 54;
  }
  die = drop_egg(1, 65);
  if (die)
  {
    for (int i = 55; i <= 64; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 65;
  }
  die = drop_egg(1, 75);
  if (die)
  {
    for (int i = 66; i <= 74; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 75;
  }
  die = drop_egg(1, 84);
  if (die)
  {
    for (int i = 76; i <= 83; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 84;
  }
  die = drop_egg(1, 92);
  if (die)
  {
    for (int i = 85; i <= 91; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 92;
  }
  else
  {
    for (int i = 93; i <= 99; i++)
    {
      die = drop_egg(2, i);
      if (die)
        return i;
    }
    return 100;
  }
}