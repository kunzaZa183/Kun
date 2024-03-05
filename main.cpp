#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
pair<int,int> arr[maxn];
vector<int> all[30][maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin>>tests;
  while(tests--)
  {
    for(int i=0;i<30;i++)
      all[i].clear();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>arr[i].first>>arr[i].second;
    for(int i=0;i<n;i++)
    {
      int tmp = arr[i].second;
      for(int j=0;j<30;j++)
      if(arr[j].second & (1<<j))
      {
        all[i]
      }
    }
  }
}