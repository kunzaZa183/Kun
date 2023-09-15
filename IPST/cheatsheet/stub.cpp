#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define BASE 350'001
#define LEN 1068
struct bignum
{
	vector<int> num;
	bignum()
	{
	}
	bignum(int num)
	{
		this->num.push_back(num);
	}
	friend bignum operator+(bignum a, bignum b)
	{
		a.recheck(), b.recheck();
		bignum ret(0);
		for (int i = 0; i < max(a.num.size(), b.num.size()); i++)
		{
			int first = 0, second = 0;
			if (i < a.num.size())
				first = a.num[i];
			if (i < b.num.size())
				second = b.num[i];
			ret.num.back() += first + second;
			ret.num.push_back(ret.num.back() / BASE);
			ret.num[ret.num.size() - 2] %= BASE;
		}
		return ret;
	}
	friend bignum operator-(bignum a, bignum b)
	{
		a.recheck(), b.recheck();
		bignum ret;
		for (int i = 0; i < b.num.size(); i++)
			ret.num.push_back(a.num[i] - b.num[i]);
		for (int i = b.num.size(); i < a.num.size(); i++)
			ret.num.push_back(a.num[i]);
		for (int i = 0; i < ret.num.size() - 1; i++)
			if (ret.num[i] < 0)
			{
				ret.num[i] += BASE;
				ret.num[i + 1]--;
			}
		return ret;
	}
	friend bignum operator*(bignum a, bignum b)
	{
		a.recheck(), b.recheck();
		vector<bignum> ret;
		for (int i = 0; i < b.num.size(); i++)
		{
			bignum sth;
			sth.num.resize(i + 1, 0);
			for (int j = 0; j < a.num.size(); j++)
			{
				sth.num.back() += b.num[i] * a.num[j];
				sth.num.push_back(sth.num.back() / BASE);
				sth.num[sth.num.size() - 2] %= BASE;
			}
			ret.push_back(sth);
		}
		for (int i = 1; i < ret.size(); i++)
			ret[i] = ret[i] + ret[i - 1];
		return ret.back();
	}
	friend bool operator<(bignum a, bignum b)
	{
		a.recheck(), b.recheck();
		if (a.num.size() > b.num.size())
			return 0;
		if (a.num.size() < b.num.size())
			return 1;
		for (int i = a.num.size() - 1; i >= 0; i--)
			if (a.num[i] < b.num[i])
				return 1;
			else if (a.num[i] > b.num[i])
				return 0;
		return 0;
	}
	void recheck()
	{
		while (num.back() == 0 && num.size() > 1)
			num.pop_back();
	}
};

vector<int> write_cheatsheet(int N, vector<int> A)
{
	bignum last;
	last.num = A;

	vector<int> vi;
	for (int i = 0; i < LEN; i++)
		vi.push_back(i);

	vector<bignum> fact;
	fact.emplace_back(1);
	for (int i = 1; i <= LEN; i++)
		fact.push_back(fact.back() * bignum(i));

	vector<int> ans;
	for (int i = 0; i < LEN; i++)
	{
		int in = 0;
		while (!(last < fact[LEN - i - 1]))
		{
			last = last - fact[LEN - i - 1];
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
		fact.push_back(fact.back() * bignum(i));

	vector<int> vi;
	for (int i = 0; i < LEN; i++)
		vi.push_back(i);

	bignum res(0);
	for (int i = 0; i < R.size(); i++)
	{
		res = res + fact[R.size() - i - 1] * bignum(find(vi.begin(), vi.end(), R[i]) - vi.begin());
		vi.erase(find(vi.begin(), vi.end(), R[i]));
	}
	while (res.num.size() < N)
		res.num.push_back(0);
	while (res.num.size() > N)
		res.num.pop_back();
	return res.num;
}


static int M = 0;
static int N;
static std::vector<int> a, R, answers;
static int MX = 1000000;
static std::set<int> labels;

int main() {
	assert(scanf("%d", &N) == 1);
	a.resize(N);
	for (int i = 0; i < N; i++) assert(scanf("%d", &a[i]) == 1);

	R = write_cheatsheet(N, a);
	if (R.size() > MX) {
		printf("Wrong answer: size limit exceeded\n");
		exit(0);
	}
	for (int i = 0; i < R.size(); i++) {
		if (labels.find(R[i]) != labels.end()) {
			printf("Wrong answer: duplicate elements\n");
			exit(0);
		}
		if (R[i] < 0 || R[i] > MX) {
			printf("Wrong answer: value out of bound\n");
			exit(0);
		}
		labels.insert(R[i]);
		M = std::max(M, R[i]);
	}

	answers = recover_answer(N, R);
	if (answers.size() != a.size()) {
		printf("Wrong answer: incorrect answer size\n");
		exit(0);
	}
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] != a[i]) {
			printf("Wrong answer: incorrect value\n");
			exit(0);
		}
	}
	printf("%d\n", M);
}
