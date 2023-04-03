#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    map<string, pair<int, int>> mspii;
    // hi
    for (int i = 0; i <= 7; i++)
        for (int j = 0; j <= 7; j++)
        {
            string tmp;
            for (int k = 0; k <= 7; k++)
                if (k + 1 == j || k + 1 == i || k - 1 == i || k - 1 == j)
                    tmp.push_back('0');
                else
                    tmp.push_back('1');
            mspii[tmp] = {i, j};
        }
}