#include<bits/stdc++.h>
using namespace std;
long long n,t,a[100005],x,y,st,md,ed,ans;
vector<pair<long long,long long> > v;
pair<long long,long long> pxir;
double least;
struct node
{
    long long val,cnt;
    node *l,*r;
};
node root[100005];
void build(node *tree,long long st,long long ed)
{
    long long md=(st+ed)/2;
    if(st==ed)
    {
        tree->val=a[st];
        tree->cnt=0;
        return;
    }
    tree->l=new node();
    tree->r=new node();
    build(tree->l,st,md);
    build(tree->r,md+1,ed);
    tree->val=tree->l->val+tree->r->val;
    tree->cnt=tree->l->cnt+tree->r->cnt;
}
void update(node *tree,node *prev,long long st,long long ed,long long idx)
{
    long long md=(st+ed)/2;
    if(st==ed)
    {
        tree->val=0;
        tree->cnt=1;
        return;
    }
    if(idx<=md)
    {
        tree->r=prev->r;
        tree->l=new node();
        update(tree->l,prev->l,st,md,idx);
    }else
    {
        tree->l=prev->l;
        tree->r=new node();
        update(tree->r,prev->r,md+1,ed,idx);
    }
    tree->val=tree->l->val+tree->r->val;
    tree->cnt=tree->l->cnt+tree->r->cnt;
}
pair<long long,long long> query(node *tree,long long st,long long ed,long long l,long long r)
{
    long long md=(st+ed)/2;
    if(st>r||ed<l)
    {
        return {0,0};
    }
    if(st>=l&&ed<=r)
    {
        return {tree->val,tree->cnt};
    }
    pair<long long,long long> lft=query(tree->l,st,md,l,r);
    pair<long long,long long> rht=query(tree->r,md+1,ed,l,r);
    return {lft.first+rht.first,lft.second+rht.second};
}
int main()
{
    
    freopen("input.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    scanf("%lld%lld",&n,&t);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        v.push_back({a[i],i});
    }
    build(&root[0],1,n);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        update(&root[i+1],&root[i],1,n,v[i].second);
    }
    while(t--)
    {
        scanf("%lld%lld%lf",&x,&y,&least);
        st=0;
        ed=n;
        ans=1e9;
        while(ed>=st)
        {
            md=(st+ed)/2;
            pxir=query(&root[md],1,n,x,y);
            if(pxir.second==y-x+1)
            {
                ed=md-1;
            }else if((double)pxir.first/(y-x+1-pxir.second)>=least)
            {
                ans=min(ans,pxir.second);
                ed=md-1;
            }else
            {
                st=md+1;
            }
        }
        if(ans==1e9)
        {
            printf("-1\n");
        }else
        {
            printf("%lld\n",ans);
        }
    }
}