#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    vector<int> vi;
    for (int i = 0; i < 5; i++)
        vi.push_back(i);
    random_shuffle(vi.begin(), vi.end());
    for (auto a : vi)
        cout << a << "\n";
}