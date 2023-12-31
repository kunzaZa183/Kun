#include <bits/stdc++.h>
using namespace std;
#define int long long
const int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1}, dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool valid(int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int all = i * i * (i * i - 1) / 2;
        int hit = 0;
        if (i <= 4)
        {
            for (int j = 0; j < i; j++)
                for (int k = 0; k < i; k++)
                    for (int l = 0; l < 8; l++)
                        if (valid(dx[l] + j, dy[l] + k, i))
                            hit++;
            hit /= 2;
        }
        else
        {
            hit = (i - 4) * (i - 4) * 8;
            hit += (4 * 2);
            hit += (8 * 3);
            hit += (i - 3) * 4 * 6;
            hit += ((i * i) - (i - 4) * (i - 4) - 4 - 8 - (i - 3) * 4) * 6;
            hit -= 8 * i;
            hit /= 2;
            hit += 12;
        }
        all -= hit;
        cout << all << "\n";
    }
}