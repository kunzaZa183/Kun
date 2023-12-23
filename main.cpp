#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> vvb;
vector<string> vs;
void recur(int curx, int cury)
{
    if (vvb[curx][cury])
        return;
    vvb[curx][cury] = 1;
    char c = vs[curx][cury];
    if (c == 'S' || c == '-')
        recur(curx, cury + 1), recur(curx, cury - 1);
    else if (c == '|')
        recur(curx - 1, cury), recur(curx + 1, cury);
    else if (c == 'L')
        recur(curx - 1, cury), recur(curx, cury + 1);
    else if (c == 'J')
        recur(curx - 1, cury), recur(curx, cury - 1);
    else if (c == '7')
        recur(curx, cury - 1), recur(curx + 1, cury);
    else if (c == 'F')
        recur(curx, cury + 1), recur(curx + 1, cury);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s, s != "Q")
        vs.push_back(s);
    vvb.resize(vs.size(), vector<bool>(vs.front().size(), 0));
    for (int i = 0; i < vs.size(); i++)
        for (int j = 0; j < vs[i].size(); j++)
            if (vs[i][j] == 'S')
            {
                vs[i][j] == '-';
                recur(i, j);
            }
    int sum = 0;
    for (int i = 0; i < vs.size(); i++)
        for (int j = 0; j < vs[i].size(); j++)
            if (!vvb[i][j])
            {
                int tmpi = i, tmpj = j;
                int ct = 0;
                while (tmpi >= 0 && tmpj >= 0)
                {
                    if (vvb[tmpi][tmpj])
                    {
                        if (vs[tmpi][tmpj] == 'L' || vs[tmpi][tmpj] == '7')
                            ct += 2;
                        else
                            ct++;
                    }
                    tmpi--, tmpj--;
                }
                sum += ct % 2;
            }
    cout << sum << '\n';
}