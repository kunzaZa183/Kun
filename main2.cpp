#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000, MOD = 998244353;
queue<int> alldp[maxn + 1];
int arr[maxn], sum[maxn + 1], nothing[maxn + 1];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (arr[0] == -1)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i - 1; j++)
                alldp[i].push(0);
        for (int i = 1; i <= n; i++)
        {
            alldp[i].push(1);
            sum[i] = 1;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                alldp[i].push(0);
        alldp[arr[0]].pop();
        alldp[arr[0]].push(1);
        sum[arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
        if (arr[i] == -1)
        {
            int sumall = 0;
            for (int j = 1; j <= n; j++)
                sumall = (sumall + sum[j]) % MOD;
            for (int j = 1; j <= n; j++)
            {
                int val = sumall - sum[j];
                if (val < 0)
                    val += MOD;
                alldp[j].push(val);
                sum[j] = (sum[j] + val) % MOD;
                if (nothing[j])
                {
                    nothing[j]--;
                    alldp[j].pop();
                }
                else
                {
                    sum[j] -= alldp[j].front();
                    alldp[j].pop();
                    if (sum[j] < 0)
                        sum[j] += MOD;
                }
            }
        }
        else
        {
            int sumall = 0;
            for (int j = 1; j <= n; j++)
                if (arr[i] != j)
                    sumall = (sumall + sum[j]) % MOD;
            alldp[arr[i]].push(sumall);
            sum[arr[i]] = (sum[arr[i]] + sumall) % MOD;
            if (nothing[arr[i]])
            {
                nothing[arr[i]]--;
                alldp[arr[i]].pop();
            }
            else
            {
                sum[arr[i]] -= alldp[arr[i]].front();
                alldp[arr[i]].pop();
                if (sum[arr[i]] < 0)
                    sum[arr[i]] += MOD;
            }
            for (int j = 1; j <= n; j++)
                if (arr[i] != j)
                {
                    nothing[j] = j;
                    sum[j] = 0;
                }
        }
    int all = 0;
    for (int i = 1; i <= n; i++)
        all = (all + sum[i]) % MOD;
    cout << all << "\n";
}