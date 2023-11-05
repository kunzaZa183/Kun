#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
int arr[maxn], dp[maxn][maxn] = {} /* val k */, added[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }
    dp[arr[0]][0] = 1;
    for (int i = 1; i < n; i++)
    {
        memset(added, 0, sizeof added);
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (arr[i] < arr[j])
                    added[k + 1] += dp[arr[j]][k];
                else
                    added[k] += dp[arr[j]][k];
        memset(dp, 0, sizeof dp);
        for (int j = 0; j <= i; j++)
            for (int k = 0; k < n; k++)
                dp[arr[j]][k] += added[k];
    }
    memset(added, 0, sizeof added);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            added[i] += dp[j][i];
    for (int i = 0; i < n; i++)
        cout << added[i] << ' ';
    cout << "\n";
}