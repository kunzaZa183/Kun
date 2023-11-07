#include <bits/stdc++.h>
using namespace std;
double dist(pair<double, double> a, pair<double, double> b)
{
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<double, double>> vpii(n);
    for (auto &a : vpii)
    {
        string receive;
        cin >> receive;
        int index = receive.find(',');
        a.first = stod(receive.substr(0, index));
        a.second = stod(receive.substr(index + 1));
    }
    vpii.emplace_back(0, 0);
    sort(vpii.begin(), vpii.end());
    double mini = INT_MAX;
    do
    {
        double sum = dist(vpii.front(), vpii.back());
        for (int i = 0; i < n; i++)
            sum += dist(vpii[i + 1], vpii[i]);
        mini = min(mini, sum);
    } while (next_permutation(vpii.begin(), vpii.end()));
    cout << fixed << setprecision(2) << mini << '\n';
}