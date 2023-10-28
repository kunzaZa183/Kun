#include "pandelib.h"
#include <bits/stdc++.h>
using namespace std;

int n, k, l;

const int maxpeople = 100000;

assignment_t a[34][maxpeople];
bool results[4][maxpeople];
vector<long long> allstates; // base 5
int stop;
void recur(long long base5, int ct, array<int, 4> left)
{
    if (ct == stop)
    {
        allstates.push_back(base5);
        return;
    }
    base5 *= 5;
    recur(base5, ct + 1, left);
    for (int i = 0; i < 4; i++)
        if (left[i] > 0)
        {
            left[i]--;
            recur(base5 + i + 1, ct + 1, left);
            left[i]++;
        }
}
int main()
{
    pandemic_init(n, k, l);
    int maxp;
    for (int i = 1; i <= 30; i++)
    {
        allstates.clear();
        stop = i;
        recur(0, 0, {l, l, l, l});
        if (allstates.size() >= n)
        {
            maxp = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> vi;
        long long tmp = allstates[i];
        while (tmp > 0)
        {
            vi.push_back(tmp % 5);
            tmp /= 5;
        }
        for (int j = 0; j < vi.size(); j++)
            if (vi[j] != 0)
                a[vi[j] - 1][j].push_back(i);
    }
    for (int i = 0; i < 4; i++)
        pandemic_assign(a[i], results[0]);
    for (int i = 0; i < 26; i++)
        pandemic_assign(a[0], results[0]);
    for (int i = 0; i < 4; i++)
        pandemic_assign(a[0], results[i]);
    vector<int> all;
    for (int i = 0; i < maxp; i++)
    {
        for (int j = 0; j < 4; j++)
            if (results[j][i])
            {
                all.push_back(j + 1);
                goto A;
            }
        all.push_back(0);
    A:;
    }
    reverse(all.begin(), all.end());
    long long check = 0;
    for (auto a : all)
    {
        check *= 5;
        check += a;
    }
    for (int i = 0; i < n; i++)
        if (allstates[i] == check)
        {
            pandemic_answer(i);
            return 0;
        }
}
