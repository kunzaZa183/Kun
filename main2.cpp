//codeforces D
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
int par[maxn]={};
bool three = 0;
int colofpar[maxn] = {};
int rb=0;
void dfs(int cur)
{
    if()
    if(colofpar[cur] == 0)
    {
        rb = 1;
        colofpar[0] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> adjlist[maxn];
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
        adjlist[par[i]].push_back(i), adjlist[i].push_back(par[i]);
    }
    for(int i=1;i<=n;i++)
        if(adjlist[i].size()==2)
            for(auto a:adjlist[i])
                if(adjlist[a].size()==2)
                    three = 1;
    for(auto a:adjlist[1])
        dfs(a);
}