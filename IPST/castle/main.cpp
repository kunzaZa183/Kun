#include <bits/stdc++.h>
#include "castle.h"
using namespace std;

int N, M, Q, Y;
vector<int> A, B;

int main()
{
  castle_init(N, M, Q, Y);
  castle_read_map(A, B);

  while (Q--)
  {
    int T, X, Y;
    castle_read_event(T, X, Y);
    
    if (T == 2)
    {
      castle_answer(0);
    }
  }
}
