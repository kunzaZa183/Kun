#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define int long long

/**
 * Find the total distance the subway must travel until all passengers have
 * arrived at their ending station.
 *
 * N: the number of passengers
 * M: the number of stations
 * K: the maximum number of passengers the subway can carry
 * S: list of starting stations for each passenger
 * E: list of ending stations for each passenger
 */
int solve(int N, int M, int K, vector<int> &S, vector<int> &E)
{
    set<pair<int, int>> vpii;
    for (int i = 0; i < N; i++)
        vpii.emplace(S[i], i);
    int cur = 1, dist = 0;
    multiset<int> out;
    while (!vpii.empty() || !out.empty())
    {
        auto receive = vpii.lower_bound({cur, -1});
        auto song = out.lower_bound(cur);
        if (receive == vpii.end() && song == out.end())
        {
            dist += M - cur + 1;
            cur = 1;
        }
        else if (receive == vpii.end())
        {
            dist += *song - cur;
            cur = *song;
            out.erase(song);
        }
        else if (song == out.end())
        {
            if (out.size() == K)
            {
                dist += M - cur + 1;
                cur = 1;
            }
            else
            {
                dist += receive->first - cur;
                cur = receive->first;
                out.insert(E[receive->second]);
                vpii.erase(receive);
            }
        }
        else if (out.size() == K)
        {
            dist += *song - cur;
            cur = *song;
            out.erase(song);
        }
        else if (*song <= receive->first)
        {
            dist += *song - cur;
            cur = *song;
            out.erase(song);
        }
        else if (*song > receive->first)
        {
            dist += receive->first - cur;
            cur = receive->first;
            out.insert(E[receive->second]);
            vpii.erase(receive);
        }
    }
    return dist;
}

signed main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> S(N);
        for (int &item : S)
        {
            cin >> item;
        }
        vector<int> E(N);
        for (int &item : E)
        {
            cin >> item;
        }
        cout << solve(N, M, K, S, E) << '\n';
    }
}
