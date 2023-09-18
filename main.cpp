#include <bits/stdc++.h>
using namespace std;
const int arrsiz = 200000;

int seg[arrsiz * 4];
pair<int,int> lazy[arrsiz * 4];
int arr[arrsiz];

void build(int curin, int curl, int curr)
{
  if (curl == curr)
  {
    seg[curin] = arr[curl];
    return;
  }
  build(curin * 2 + 1, curl, (curl + curr) / 2), build(curin * 2 + 2, (curl + curr) / 2 + 1, curr);
  seg[curin] = seg[curin * 2 + 1] + seg[curin * 2 + 2];
}

void lazyv(int curin,int curl,int curr)
{

}

void update(int curin,int curl, int curr,int ql,int qr)
{

}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i=0;i<arrsiz;i++)
}