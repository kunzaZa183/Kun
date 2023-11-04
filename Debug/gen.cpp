#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    int n = 100;
    int trues = rand() % n;
    int falses = n - trues;
    string vi;
    cout << n << "\n";
    for (int i = 0; i < trues; i++)
        vi.push_back('T');
    for (int i = 0; i < falses; i++)
        vi.push_back('F');
    random_shuffle(vi.begin(), vi.end());
    cout << vi << '\n';
}