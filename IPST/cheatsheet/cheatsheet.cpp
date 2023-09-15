#include "cheatsheet.h"
#include <bits/stdc++.h>
// #include <array>
using namespace std;
#define BASE 350001
#define LEN 1068
struct bignum {
	int D = 501;
	int B = 350001;
	array<int, 501> d;
	bignum(int x = 0ll) {
		for (int i = 0; i < D; i++)d[i] = x % B, x /= B;
	}
	bignum& operator+=(const bignum& rhs) {
		for (int i = 0; i < D; i++) {
			d[i] += rhs.d[i];
			if (d[i] >= B)d[i] -= B, d[i + 1]++;
		}
		return *this;
	}
	bignum& operator-=(const bignum& rhs) {
		for (int i = 0; i < D; i++) {
			d[i] -= rhs.d[i];
			if (d[i] < 0)d[i] += B, d[i + 1]--;
		}
		return *this;
	}
	bignum& operator*=(const int& rhs) {
		int carry = 0;
		for (int i = 0; i < D; i++) {
			d[i] *= rhs;
			d[i] += carry;
			carry = d[i] / B;
			d[i] %= B;
		}
		return *this;
	}
	friend bignum operator+(const bignum& lhs, const bignum& rhs) { return bignum(lhs) += rhs; }
	friend bignum operator-(const bignum& lhs, const bignum& rhs) { return bignum(lhs) -= rhs; }
	friend bignum operator*(const bignum& lhs, const int& rhs) { return bignum(lhs) *= rhs; }
	int cmp(const bignum& rhs) {
		for (int i = D - 1; i >= 0; i--)if (d[i] != rhs.d[i])return d[i] < rhs.d[i] ? -1 : 1;
		return 0;
	}
	bool operator<(const bignum& rhs) { return this->cmp(rhs) == -1; }
};

vector<int> write_cheatsheet(int N, vector<int> A)
{
	bignum last;
	for (int i = 0; i < N; i++)
		last.d[i] = A[i];

	vector<int> vi;
	for (int i = 0; i < LEN; i++)
		vi.push_back(i);

	vector<bignum> fact;
	fact.emplace_back(1);
	for (int i = 1; i <= LEN; i++)
		fact.push_back(fact.back() * i);

	vector<int> ans;
	for (int i = 0; i < LEN; i++)
	{
		int in = 0;
		while (!(last < fact[LEN - i - 1]))
		{
			last -= fact[LEN - i - 1];
			in++;
		}
		ans.push_back(vi[in]);
		vi.erase(vi.begin() + in);
	}
	return ans;
}

vector<int> recover_answer(int N, vector<int> R)
{
	vector<bignum> fact;
	fact.emplace_back(1);
	for (int i = 1; i <= LEN; i++)
		fact.push_back(fact.back() * i);

	vector<int> vi;
	for (int i = 0; i < LEN; i++)
		vi.push_back(i);

	bignum res(0);
	for (int i = 0; i < R.size(); i++)
	{
		res += fact[R.size() - i - 1] * (find(vi.begin(), vi.end(), R[i]) - vi.begin());
		vi.erase(find(vi.begin(), vi.end(), R[i]));
	}
	vector<int> last;
	for (auto a : res.d)
		last.push_back(a);
	while (last.size() < N)
		last.push_back(0);
	while (last.size() > N)
		last.pop_back();
	return last;
}