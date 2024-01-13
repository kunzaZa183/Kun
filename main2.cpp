#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int arr[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> vi;
        int tmpi = n;
        for (int i = 1; i <= tmpi; i++)
            if (n % i == 0)
                vi.push_back(i);
        if (vi.back() != n)
            vi.push_back(n);
        int points = 0;
        for (auto a : vi)
        {
            int gcd = -1;
            for (int i = 0; i < a; i++)
                for (int j = i; j < n; j += a)
                    if (arr[j] != arr[i])
                    {
                        if (gcd == -1)
                            gcd = abs(arr[j] - arr[i]);
                        else
                            gcd = std::gcd(gcd, abs(arr[j] - arr[i]));
                    }
            if (gcd != 1)
                points++;
        }
        cout << points << "\n";
    }
}