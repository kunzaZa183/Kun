#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <utility>
#include <map>
#include <iomanip>
#include <tuple>
using namespace std;
#define int long long
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int ct = 0;
	bool right = 1;
	while (1)
	{
		char c;
		cin >> c;
		s.push_back(c);
		if (s.size() % 2 == 0 && s.substr(0, s.size() / 2) == s.substr(s.size() / 2))
		{
			int num = s.size() / 2;
			cout << "? flip" << endl;
			ct++;
			s.clear();
			for (int i = 0; i < num + 1; i++)
			{
				char c;
				cin >> c;
				if (right)
					cout << "? left" << endl;
				else
					cout << "? right" << endl;
				ct++;
				s.push_back(c);
			}
			if (s.back() == s.front())
			{
				cout << "! " << num << endl;
				//cout << ct << '\n';
				return 0;
			}
			else
			{
				for (int i = 0; i < num - 1; i++)
				{
					char c;
					cin >> c;
					s.push_back(c);
					if (right)
						cout << "? left" << endl;
					else
						cout << "? right" << endl;
					ct++;
				}
				right = !right;
			}
		}
		else if (right)
		{
			cout << "? right" << endl;
			ct++;
		}
		else
		{
			cout << "? left" << endl;
			ct++;
		}
	}
}