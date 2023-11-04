#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("correctoutput.txt", "w", stdout);
    int len;
    cin >> len;
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j <= len - i; j++)
        {
            string tmp = s.substr(j, i);
            int maxt = 0;
            int curt = 0;
            for (auto a : tmp)
                if (a == 'T')
                {
                    curt++;
                    maxt = max(maxt, curt);
                }
                else if (a == 'F')
                    curt = 0;
            sum += maxt;
        }
    }
    cout << sum << '\n';
}
