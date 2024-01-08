#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
string plain[maxn], spotty[maxn];
int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, len;
    cin >> n >> len;
    for (int i = 0; i < n; i++)
        cin >> plain[i];
    for (int i = 0; i < n; i++)
        cin >> spotty[i];
    int ct = 0;
    for (int j = 0; j < len; j++)
        for (int k = j + 1; k < len; k++)
            for (int l = k + 1; l < len; l++)
            {
                set<string> si1, si2;
                for (int i = 0; i < n; i++)
                {
                    string tmp;
                    tmp.push_back(plain[i][j]);
                    tmp.push_back(plain[i][k]);
                    tmp.push_back(plain[i][l]);
                    si1.insert(tmp);
                }
                for (int i = 0; i < n; i++)
                {
                    string tmp;
                    tmp.push_back(spotty[i][j]);
                    tmp.push_back(spotty[i][k]);
                    tmp.push_back(spotty[i][l]);
                    si2.insert(tmp);
                }
                for (auto a : si1)
                    if (si2.count(a))
                        goto A;
                ct++;
            A:;
            }
    cout << ct << "\n";
}