#include <bits/stdc++.h>
using namespace std;
vector<int> firstrow, firstcolumn;
int r, c;
void prrow()
{
  for (int i = 0; i < r; i++)
  {
    cout << firstrow[i];
    if (i != r - 1)
      cout << ' ';
  }
  cout << "\n";
  for (int i = r; i < r + c; i++)
  {
    cout << firstrow[i];
    if (i != r + c - 1)
      cout << " ";
  }
  cout << "\n";
}
void prcol()
{
  for (int i = 0; i < r; i++)
  {
    cout << firstcolumn[i];
    if (i != r - 1)
      cout << ' ';
  }
  cout << "\n";
  for (int i = r; i < r + c; i++)
  {
    cout << firstcolumn[i];
    if (i != r + c - 1)
      cout << " ";
  }
  cout << "\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    cin >> r >> c;
    vector<string> vvi(r);
    for (auto& a : vvi)
      cin >> a;
    vector<string> orig(vvi);
    firstrow.clear(), firstcolumn.clear();
    {
      bool works = 1;
      vector<int> row(r);
      vector<int> col(c);
      for (int j = 0; j < c; j++)
        if (vvi[0][j] == '1')
        {
          col[j] = 1;
          for (int k = 0; k < r; k++)
            vvi[k][j] = ('1' - vvi[k][j]) + '0';
        }
        else
          col[j] = 0;

      for (int i = 1; i < r; i++)
      {
        for (int j = 1; j < c; j++)
          if (vvi[i][j] != vvi[i][0])
          {
            works = 0;
            break;
          }
        if (vvi[i][0] == '1')
          row[i] = 1;
        else
          row[i] = 0;
      }
      if (works)
      {
        for (auto a : row)
          firstrow.push_back(a);
        for (auto a : col)
          firstrow.push_back(a);
      }
    }

    for (auto a : firstrow)
      firstcolumn.push_back(1 - a);

    int ct1 = 0, ct2 = 0;
    for (auto a : firstrow)
      if (a == 1)
        ct1++;
    for (auto a : firstcolumn)
      if (a == 1)
        ct2++;

    if (firstrow.empty() && firstcolumn.empty())
      cout << "impossible\n";
    else if (firstrow.empty())
      prcol();
    else if (firstcolumn.empty())
      prrow();
    else if (ct1 < ct2)
      prrow();
    else if (ct1 > ct2)
      prcol();
    else if (firstrow < firstcolumn)
      prrow();
    else
      prcol();
  }
}
