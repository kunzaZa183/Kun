#include <bits/stdc++.h>
using namespace std;
const int dx2[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy2[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ct = 0;
vector<string> vs;
vector<vector<int>> group;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    while (s != "Q")
    {
        vs.push_back(s);
        cin >> s;
    }
    int rows = vs.size(), cols = vs[0].size();
    group.resize(rows, vector<int>(cols, -1));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (isdigit(vs[i][j]))
            {
                if (j > 0)
                    if (isdigit(vs[i][j - 1]))
                    {
                        group[i][j] = group[i][j - 1];
                        continue;
                    }
                group[i][j] = ct++;
            }
    vector<int> val(ct, 0);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (group[i][j] != -1)
            {
                val[group[i][j]] *= 10;
                val[group[i][j]] += vs[i][j] - '0';
            }
    int total = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (vs[i][j] == '*')
            {
                set<int> si;
                for (int k = 0; k < 8; k++)
                    if (group[i + dx2[k]][j + dy2[k]] != -1)
                        si.insert(group[i + dx2[k]][j + dy2[k]]);
                if (si.size() == 2)
                    total += val[*si.begin()] * val[*si.rbegin()];
            }

    cout << total << '\n';
}