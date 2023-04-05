#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500000

static int32_t N, K;
static int32_t H[MAX_N][2];
static int32_t L[MAX_N];
static int32_t solution;

inline void my_assert(int32_t e)
{
  if (!e)
    abort();
}

void read_input()
{
  int32_t i;
  my_assert(2 == scanf("%d %d", &N, &K));
  for (i = 0; i < N - 1; i++)
    my_assert(3 == scanf("%d %d %d", &H[i][0], &H[i][1], &L[i]));
  my_assert(1 == scanf("%d", &solution));
}

int32_t main()
{
  int32_t ans;
  freopen("grader4.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  scanf("%d %d", &N, &K);
  read_input();
  if (ans == solution)
    printf("Correct.\n");
  else
    printf("Incorrect. Returned %d, Expected %d.\n", ans, solution);

  return 0;
}
