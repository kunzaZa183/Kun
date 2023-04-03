#include "Anna.h"
#include <bits/stdc++.h>
using namespace std;

void Anna(int X, int Y, int N, string S)
{
    int ct = 0;
    for (int i = 0; i <= 7; i++)
        for (int j = 0; j <= 7; j++)
            if (i != X && j != Y && i != j)
            {
                if (S[ct] == 'A')
                    Paint(i, j, 0);
                else if (S[ct] == 'B')
                    Paint(i, j, 1);
                ct++;
            }
    for (int i = 0; i <= 7; i++)
        if (i + 1 == X || i + 1 == Y || i - 1 == X || i - 1 == Y)
            Paint(i, i, 0);
        else
            Paint(i, i, 1);
}
