#include <bits/stdc++.h>
using namespace std;
struct node
{
  int val, sum;
  vector<node*> vn;
  node* par;
  string s;
  node()
  {
    val = 0, sum = 0;
    par = NULL;
  }
};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  int ct = 0;
  while (tests--)
  {
    cout << "COMPANY " << ++ct << "\n";
    node root;
    map<string, node*> msn;
    msn["ROOT"] = &root;
    int qs;
    cin >> qs;
    while (qs--)
    {
      string type;
      cin >> type;
      if (type == "ADD")
      {
        string a, b;
        cin >> a >> b;
        node *tmp = new node;
        tmp->s = b;
        msn[a]->vn.push_back(tmp);
        tmp->par = msn[a];
        msn[b] = tmp;
      }
      else if (type == "SALE")
      {
        string a;
        cin >> a;
        int val;
        cin >> val;
        auto it = msn[a];
        while (it != NULL)
        {
          it->val += val;
          it = it->par;
        }
      }
      else if (type == "QUERY")
      {
        string s;
        cin >> s;
        cout << msn[s]->val << '\n';
      }
    }
  }
}