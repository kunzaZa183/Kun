#include <bits/stdc++.h>
using namespace std;
const int maxn = 350;
int dp[maxn + 1][maxn + 1], qsum[maxn+1], trace[maxn + 1][maxn + 1];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>qsum[i];
    sort(qsum + 1,qsum + n + 1);
    for(int i=1;i<=n;i++)
        qsum[i] += qsum[i-1];
    for(int i=0;i<m*2;i++)
        for(int )
    for(int j = 1;j<=n;j++)
    {
        dp[1][j] = qsum[j] * (j - 1); 
        trace[1][j] = 1;
    }
    for(int i=2;i<=n;i++)
        if(i<=m)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=i-1;k<j;k++)
                dp[i][j] = min(dp[i][j],)
            }    
        }   
}