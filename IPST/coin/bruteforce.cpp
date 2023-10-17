#include "coin.h"
#include <bits/stdc++.h>
using namespace std;
int n, tape;
vector<int> rail;
void initialize(int N, vector<int> Rail, int L)
{
    n = N, tape = L;
    rail = Rail;
    return;
}
vector<int> max_dist(vector<vector<int>> Coins)
{
    vector<int> Ans(Coins.size(), n);
    for (int i = 0; i < Coins.size(); i++)
    {
        int curin = Coins[i][0];
        while (curin < n)
        {
            if (Coins[i][2] < rail[curin])
                Coins[i][1]--;
            if (Coins[i][1] == -1)
                goto A;
            curin++;
        }
        continue;
    A:
        if (tape == 0)
        {
            Ans[i] = curin;
            continue;
        }
        deque<int> num;
        int buffer = 0, maxbuff = 0;
        for (int j = Coins[i][0]; j < Coins[i][0] + tape && j < n; j++)
        {
            num.push_back(rail[j]);
            if (rail[j] > Coins[i][2])
            {
                buffer++;
                maxbuff = max(maxbuff, buffer);
            }
        }
        for (int j = Coins[i][0] + 1; j <= curin; j++)
        {
            if (num.front() > Coins[i][2])
                buffer--;
            num.pop_front();
            if (j + tape - 1 < n)
            {
                num.push_back(rail[j + tape - 1]);
                if (num.back() > Coins[i][2])
                    buffer++;
            }
            maxbuff = max(maxbuff, buffer);
        }
        Coins[i][1] += maxbuff;
        curin++;
        while (curin < n)
        {
            if (Coins[i][2] < rail[curin])
                Coins[i][1]--;
            if (Coins[i][1] <= -1)
                goto B;
            curin++;
        }
        continue;
    B:
        Ans[i] = curin;
    }
    return Ans;
}

int main()
{
    int N, Q, L;
    freopen("in.txt", "r", stdin);
    freopen("correct.txt", "w", stdout);
    scanf("%d %d %d", &N, &Q, &L);
    vector<int> Rail(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Rail[i]);
    }
    vector<vector<int>> Coins(Q, vector<int>(3, 0));
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d %d", &Coins[i][0], &Coins[i][1], &Coins[i][2]);
    }
    initialize(N, Rail, L);
    vector<int> ans(Q);
    ans = max_dist(Coins);
    for (int i = 0; i < Q; i++)
    {
        printf("%d\n", ans[i]);
    }
}
