#include <bits/stdc++.h>
using namespace std;
const int offset = 100002, maxn = 100010;
int alltargets[maxn], current[offset + maxn];
bitset<maxn + offset> istarget;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int targets, n;
    cin >> targets >> n;
    for (int i = 1; i <= targets; i++)
    {
        cin >> alltargets[i];
        alltargets[i] += offset;
        istarget[alltargets[i]] = 1;
    }
    string command;
    cin >> command;
    set<int> si;
    int cur = offset;
    for (auto a : command)
        if (a == 'L')
            cur--;
        else if (a == 'R')
            cur++;
        else if (a == 'F')
            si.insert(cur);
    int maxi = 0;
    for (auto a : si)
        maxi += istarget[a];

    // L to R
    {
        memset(current, 0, sizeof current);
        int hit = 0;

        int cur = offset + 2;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                if (current[cur] == 0 && istarget[cur])
                    hit++;
                current[cur]++;
            }

        cur = offset;
        for (auto a : command)
            if (a == 'L')
            {
                cur--;
                maxi = max(maxi, hit);
            }
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                current[cur + 2]--;
                if (current[cur + 2] == 0 && istarget[cur + 2])
                    hit--;
                current[cur]++;
                if (current[cur] == 1 && istarget[cur])
                    hit++;
            }
    }

    // R to L
    {
        memset(current, 0, sizeof current);
        int hit = 0;

        int cur = offset - 2;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                if (current[cur] == 0 && istarget[cur])
                    hit++;
                current[cur]++;
            }

        cur = offset;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
            {
                cur++;
                maxi = max(maxi, hit);
            }
            else if (a == 'F')
            {
                current[cur - 2]--;
                if (current[cur - 2] == 0 && istarget[cur - 2])
                    hit--;
                current[cur]++;
                if (current[cur] == 1 && istarget[cur])
                    hit++;
            }
    }

    // F to R
    {
        memset(current, 0, sizeof current);
        int hit = 0;

        int cur = offset + 1;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                if (current[cur] == 0 && istarget[cur])
                    hit++;
                current[cur]++;
            }

        cur = offset;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                current[cur + 1]--;
                if (current[cur + 1] == 0 && istarget[cur + 1])
                    hit--;
                maxi = max(maxi, hit);
                current[cur]++;
                if (current[cur] == 1 && istarget[cur])
                    hit++;
            }
    }

    // F to L
    {
        memset(current, 0, sizeof current);
        int hit = 0;

        int cur = offset - 1;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                if (current[cur] == 0 && istarget[cur])
                    hit++;
                current[cur]++;
            }

        cur = offset;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                current[cur - 1]--;
                if (current[cur - 1] == 0 && istarget[cur - 1])
                    hit--;
                maxi = max(maxi, hit);
                current[cur]++;
                if (current[cur] == 1 && istarget[cur])
                    hit++;
            }
    }

    // R to F
    {
        memset(current, 0, sizeof current);
        int hit = 0;

        int cur = offset - 1;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                if (current[cur] == 0 && istarget[cur])
                    hit++;
                current[cur]++;
            }

        cur = offset;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
            {
                if (current[cur] == 0 && istarget[cur])
                    hit++;
                maxi = max(maxi, hit);
                if (current[cur] == 0 && istarget[cur])
                    hit--;
                cur++;
            }
            else if (a == 'F')
            {
                current[cur - 1]--;
                if (current[cur - 1] == 0 && istarget[cur - 1])
                    hit--;
                current[cur]++;
                if (current[cur] == 1 && istarget[cur])
                    hit++;
            }
    }

    // L to F
    {
        memset(current, 0, sizeof current);
        int hit = 0;

        int cur = offset + 1;
        for (auto a : command)
            if (a == 'L')
                cur--;
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                if (current[cur] == 0 && istarget[cur])
                    hit++;
                current[cur]++;
            }

        cur = offset;
        for (auto a : command)
            if (a == 'L')
            {
                if (current[cur] == 0 && istarget[cur])
                    hit++;
                maxi = max(maxi, hit);
                if (current[cur] == 0 && istarget[cur])
                    hit--;
                cur--;
            }
            else if (a == 'R')
                cur++;
            else if (a == 'F')
            {
                current[cur + 1]--;
                if (current[cur + 1] == 0 && istarget[cur + 1])
                    hit--;
                current[cur]++;
                if (current[cur] == 1 && istarget[cur])
                    hit++;
            }
    }
    cout << maxi << '\n';
}