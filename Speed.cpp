#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main()
{
    int i;
    vector<int> values, values2;
    values.resize(1000);
    values2.resize(1000);
    for (i = 0; i < 1000; i++)
    {
        values[i] = i;
        values2[i] = i;
    }
    {
        auto start = high_resolution_clock::now();
        for (i = 0; i < 1000; i++)
            swap(values, values2);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: "
             << duration.count() << " microseconds" << endl;
    }
    {
        auto start = high_resolution_clock::now();
        for(i=0;i<1000;i++)
            values3eedew
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: "
             << duration.count() << " microseconds" << endl;
    }

    return 0;
}