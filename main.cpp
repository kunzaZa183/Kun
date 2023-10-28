#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
int arr[maxn], dp[maxn][maxn] = {}, dp2[maxn][maxn] = {}; // val k
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
        
    }
}