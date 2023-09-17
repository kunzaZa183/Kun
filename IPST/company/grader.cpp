#pragma GCC optimize("O3")
#include "company.h"
#include <bits/stdc++.h>
using namespace std;

const int COMPANIES = 100000;
vector<pair<int, int>> roadlist;
vector<int> compcity[COMPANIES];
int cities, roads;
int bslcompany[COMPANIES] = {}, bsrcompany[COMPANIES];

int dsu[100000];
int find(int in)
{
  if (dsu[in] == in)
    return in;
  dsu[in] = find(dsu[in]);
  return dsu[in];
}

void init(int N, int M, vector<int> C, vector<vector<int>> Road)
{
  reverse(Road.begin(), Road.end());
  for (auto &a : Road)
    roadlist.emplace_back(a[0], a[1]);
  for (auto &a : C)
    a--;
  cities = N;
  roads = M;

  for (int i = 0; i < cities; i++)
    compcity[C[i]].push_back(i);

  fill(bsrcompany, bsrcompany + COMPANIES, roads);
  while (1)
  {
    vector<pair<int, int>> vpii; // val index;
    for (int i = 0; i < COMPANIES; i++)
      if (bslcompany[i] < bsrcompany[i])
        vpii.emplace_back((bslcompany[i] + bsrcompany[i]) / 2, i);
    if (vpii.empty())
      return;
    sort(vpii.begin(), vpii.end());
    for (int i = 0; i < cities; i++)
      dsu[i] = i;

    int in = 0;
    for (int i = 0; i < roads; i++)
    {
      if (in == vpii.size())
        goto B;
      while (vpii[in].first == i)
      {
        for (auto a : compcity[vpii[in].second])
          if (find(a) != find(compcity[vpii[in].second].front()))
          {
            bslcompany[vpii[in].second] = vpii[in].first + 1;
            goto C;
          }
        bsrcompany[vpii[in].second] = vpii[in].first;
      C:
        in++;
        if (in == vpii.size())
          goto B;
      }
      dsu[find(roadlist[i].first)] = dsu[find(roadlist[i].second)];
    }
    while (vpii[in].first == roads)
    {
      for (auto a : compcity[vpii[in].second])
        if (find(a) != find(compcity[vpii[in].second].front()))
        {
          bslcompany[vpii[in].second] = vpii[in].first + 1;
          goto D;
        }
      bsrcompany[vpii[in].second] = vpii[in].first;
    D:;
      in++;
      if (in == vpii.size())
        goto B;
    }
  B:;
  }
}

vector<int> dissolve(vector<vector<int>> Group)
{
  int bsl[100000] = {}, bsr[100000];
  fill(bsr, bsr + 100000, roads);
  for (int i = 0; i < Group.size(); i++)
    for (auto &a : Group[i])
    {
      a--;
      bsl[i] = max(bsl[i], bslcompany[a]);
    }

  while (1)
  {
    vector<pair<int, int>> vpii; // val index
    for (int i = 0; i < Group.size(); i++)
      if (bsl[i] < bsr[i])
        vpii.emplace_back((bsl[i] + bsr[i]) / 2, i);

    if (vpii.empty())
    {
      vector<int> ans;
      for (int i = 0; i < Group.size(); i++)
        ans.push_back(roads - bsl[i]);
      return ans;
    }

    for (int i = 0; i < cities; i++)
      dsu[i] = i;

    sort(vpii.begin(), vpii.end());
    int in = 0;
    for (int i = 0; i < roads; i++)
    {
      if (in == vpii.size())
        goto A;
      while (i == vpii[in].first)
      {
        for (auto a : Group[vpii[in].second])
          if (find(compcity[a].front()) != find(compcity[Group[vpii[in].second][0]].front()))
          {
            bsl[vpii[in].second] = vpii[in].first + 1;
            goto E;
          }
        bsr[vpii[in].second] = vpii[in].first;
      E:
        in++;
        if (in == vpii.size())
          goto A;
      }
      dsu[find(roadlist[i].first)] = dsu[find(roadlist[i].second)];
    }
    while (roads == vpii[in].first)
    {
      for (auto a : Group[vpii[in].second])
        if (find(compcity[a].front()) != find(compcity[Group[vpii[in].second][0]].front()))
        {
          bsl[vpii[in].second] = vpii[in].first + 1;
          goto F;
        }
      bsr[vpii[in].second] = vpii[in].first;
    F:
      in++;
      if (in == vpii.size())
        goto A;
    }
  A:;
  }
}

int main()
{
	int N, M, P;
	scanf("%d %d %d", &N, &M, &P);
	std::vector<int> C(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &C[i]);
	}
	std::vector<std::vector<int> > Road(M, std::vector<int>(2, 0)), Group;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &Road[i][0], &Road[i][1]);
	}
	for (int i = 0; i < P; i++)
	{
		int P_i;
		scanf("%d", &P_i);
		std::vector<int> group(P_i);
		for (int j = 0; j < P_i; j++)
		{
			scanf("%d", &group[j]);
		}
		Group.push_back(group);
	}
	init(N, M, C, Road);
	std::vector<int> Ans = dissolve(Group);
	for (auto i : Ans)
	{
		printf("%d\n", i);
	}
}
