#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("correctoutput.txt", "w", stdout);
    vector<int> arrmap(2000);
    vector<pair<int, int>> allseeds;
    int num = 0, range;
    cin >> num >> range;
    while (num != -1)
    {
        allseeds.emplace_back(num, num + range);
        cin >> num >> range;
    }
    sort(allseeds.begin(), allseeds.end());
    set<int> si;
    for (auto a : allseeds)
        for (int i = a.first; i < a.second; i++)
            si.insert(i);
    for (int i = 0; i < 7; i++)
    {
        vector<tuple<int, int, int>> vtiii;
        int a = 0, b = 0, c = 0;
        while (cin >> a >> b >> c, a != -1)
            vtiii.emplace_back(b, b + c, a);
        vector<int> mapchange(2000);
        for (int i = 0; i < 2000; i++)
            mapchange[i] = i;
        sort(vtiii.begin(), vtiii.end());
        for (auto [source, end, dest] : vtiii)
            for (int i = source; i < end; i++)
                mapchange[i] = dest + i - source;
        set<int> last;
        for (auto a : si)
            last.insert(mapchange[a]);
        si.swap(last);
    cout << *si.begin() << '\n';
    }
}