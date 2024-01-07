#include <bits/stdc++.h>
using namespace std;
int paint[2000][2000];
int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
        arr[i] += 1000;
    }
    for (int i = 0; i < 2; i++)
        for (int j = arr[4 * i]; j < arr[4 * i + 2]; j++)
            for (int k = arr[4 * i + 1]; k < arr[4 * i + 3]; k++)
                paint[j][k] = int(!i);
    int minx = 2000, maxx = 0, miny = 2000, maxy = 0;
    for (int i = 0; i < 2000; i++)
        for (int j = 0; j < 2000; j++)
            if (paint[i][j])
            {
                minx = min(minx, i);
                maxx = max(maxx, i);
                miny = min(miny, j);
                maxy = max(maxy, j);
            }
    cout << max(0, maxx - minx + 1) * max(0, maxy - miny + 1) << "\n";
}