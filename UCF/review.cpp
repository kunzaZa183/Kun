#include <bits/stdc++.h>
using namespace std;
vector<set<int>> redadj, blueadj;
vector<int> component;
void dfs(int cur, int ct)
{
  if (component[cur] != -1)
    return;
  component[cur] = ct;
  for (auto a : redadj[cur])
    dfs(a, ct);
  for (auto a : blueadj[cur])
    dfs(a, ct);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int problems, n;
    cin >> problems >> n;
    redadj.resize(n), blueadj.resize(n);
    for (int i = 0; i < problems; i++)
    {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      if (c == 1)
        redadj[a].insert(b), redadj[b].insert(a);
      else if (c == 2)
        blueadj[a].insert(b), blueadj[b].insert(a);
      else if (c == 3)
        redadj[a].insert(b), redadj[b].insert(a), blueadj[a].insert(b), blueadj[b].insert(a);
    }
    vector<set<int>> originalred(redadj), originalblue(blueadj);
    component.resize(n, -1);
    for (int i = 0; i < n; i++)
      dfs(i, i);
    vector<set<int>> eachcompo(n);
    for (int i = 0; i < n; i++)
      eachcompo[component[i]].insert(i);
    vector<int> color(n, -1); // 1 red 2 blue
    bool can = 1;
    for (int i = 0; i < n; i++)
      if (!eachcompo[i].empty())
      {
        for (int j = 1; j <= 2; j++)
        {
          queue<pair<int, int>> qpii; // in color
          for (auto &a : eachcompo[i])
            if (redadj[a].empty())
              qpii.push({a, 2});
            else if (blueadj[a].empty())
              qpii.push({a, 1});
          while (!qpii.empty())
          {
            pair<int, int> tmp = qpii.front();
            if (color[tmp.first] == -1)
            {
              color[tmp.first] = tmp.second;
              if (tmp.second == 1)
              {
                for (auto a : redadj[tmp.first])
                {
                  redadj[a].erase(tmp.first);
                  if (redadj[a].empty())
                    qpii.push({a, 2});
                }
                redadj[tmp.first].clear();
                for (auto a : blueadj[tmp.first])
                {
                  qpii.push({a, 2});
                  blueadj[a].erase(tmp.first);
                }
                blueadj[tmp.first].clear();
              }
              else if (tmp.second == 2)
              {
                for (auto a : redadj[tmp.first])
                {
                  qpii.push({a, 1});
                  redadj[a].erase(tmp.first);
                }
                redadj[tmp.first].clear();
                for (auto a : blueadj[tmp.first])
                {
                  blueadj[a].erase(tmp.first);
                  if (blueadj[a].empty())
                    qpii.push({a, 1});
                }
                blueadj[tmp.first].clear();
              }
            }
          }
          // try
          queue<pair<int, int>> states; // in col;
          states.push({*eachcompo[i].begin(), j});
          bool works = 1;
          while (!states.empty())
          {
            pair<int, int> pii = states.front();
            states.pop();
            if (color[pii.first] == -1)
            {
              color[pii.first] = pii.second;
              if (pii.second == 1)
              {
                for (auto a : redadj[pii.first])
                {
                  redadj[a].erase(pii.first);
                  if (redadj[a].empty())
                    states.push({a, 2});
                }
                redadj[pii.first].clear();
                for (auto a : blueadj[pii.first])
                {
                  states.push({a, 2});
                  blueadj[a].erase(pii.first);
                }
                blueadj[pii.first].clear();
              }
              else if (pii.second == 2)
              {
                for (auto a : redadj[pii.first])
                {
                  states.push({a, 1});
                  redadj[a].erase(pii.first);
                }
                redadj[pii.first].clear();
                for (auto a : blueadj[pii.first])
                {
                  blueadj[a].erase(pii.first);
                  if (blueadj[a].empty())
                    states.push({a, 1});
                }
                blueadj[pii.first].clear();
              }
            }
            else if (color[pii.first] != pii.second)
            {
              works = 0;
              break;
            }
          }
          for (auto a : eachcompo[i])
            redadj[a] = originalred[a], blueadj[a] = originalblue[a], color[a] = -1;
          if (works)
            goto A;
        }
        can = 0;
        break;
      A:;
      }
  }
}