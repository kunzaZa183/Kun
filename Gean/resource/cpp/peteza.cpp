#include <bits/stdc++.h>
#include "resource.h"
using namespace std;
using ll = long long;

struct node {
    node *l = NULL, *r = NULL;
    int sz = 0;
    ll sum = 0;
} *root[100005];

node* build(int l, int r) {
    auto it = new node();
    if(l == r) return it;
    int mid = (l+r) >> 1;
    it->l = build(l, mid); it->r = build(mid+1, r);
    return it;
}

node* upd(node*&old, int l, int r, int tgt, int val) {
    auto it = new node();
    if(l == r) {
        it->sum = val;
        it->sz = 1;
        return it;
    }
    int mid = (l+r) >> 1;
    if(tgt <= mid) it->l = upd(old->l, l, mid, tgt, val), it->r = old->r;
    else         it->r = upd(old->r, mid+1, r, tgt, val), it->l = old->l;
    it->sum = it->l->sum + it->r->sum;
    it->sz = it->l->sz + it->r->sz;
    return it;
}

ll qr(node *&add, node*&add2, node *&sub, int l, int r, int cnt) {
    if(!add) return 0;
    if(l == r) return ((cnt>0) * (add->sz + add2->sz - sub->sz) * (add->sum + add2->sum - sub->sum));
    int mid = (l+r) >> 1, leftsz = add->l->sz + add2->l->sz - sub->l->sz;
    //cout << leftsz << " -> " << (add->l->sum - sub->l->sum + add2->l->sum) << '\n';
    if(leftsz <= cnt) return (add->l->sum - sub->l->sum + add2->l->sum) + qr(add->r, add2->r, sub->r, mid+1, r, cnt-leftsz);
    else return qr(add->l, add2->l, sub->l, l, mid, cnt);
}

vector<int> val;
vector<int> adj[100005];
int ct = 1;
pair<int, int> euler[100005];
int pos[100005];

void dfstour(int x, int p = -1) {
    root[ct] = upd(root[ct-1], 0, val.size()-1, pos[x], val[x]);
    euler[x].first = ct++;
    for(int e:adj[x]) {
        if(e == p) continue;
        dfstour(e, x);
    }
    euler[x].second = ct-1;
}

vector<int> u, v;

void init_resource(int N, int Q, std::vector<int> A, std::vector<int> U, std::vector<int> V, int G) {
    // edit this
    for(int i=0;i<N-1;i++) {
        adj[U[i]].push_back(V[i]);
        adj[V[i]].push_back(U[i]);
    }
    vector<pair<int, int>> findposes(N);
    for(int i=0;i<N;i++) findposes[i] = {A[i], i};
    sort(findposes.rbegin(), findposes.rend());
    for(int i=0;i<N;i++) pos[findposes[i].second] = i;
    val = A;
    root[0] = build(0, N-1);
    dfstour(0, -1);
    u = U; v = V;
}

long long need_help(int X, int C, int K) {
    // edit this
    //determine if C is in subtree or outside
    if(euler[v[X]].first <= euler[C].first && euler[C].first <= euler[v[X]].second) { // C is in subtree!!
        //cout << "Inside";
        return qr(root[euler[v[X]].second], root[0], root[euler[v[X]].first-1], 0, v.size()-1, K);
    } else {
        //cout << "outisde";
        return qr(root[euler[0].second], root[euler[v[X]].first-1], root[euler[v[X]].second], 0, v.size()-1, K);
    }
}