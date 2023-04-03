#include <bits/stdc++.h>
#define st first
#define nd second
#define ll int64_t
using namespace std;
const ll INF=1e17;
ll k,x1,y1_,x2,y2,r=1;
ll disc[17][17];
struct A {
    pair <ll,int> a,b,c,d;
    int boxs;
};
bool in_area(ll x_1,ll y_1,ll x_2,ll y_2) {
    if(x1>=x_1 && x1<=x_2 && y1_>=y_1 && y1_<=y_2
    && x2>=x_1 && x2<=x_2 && y2>=y_1 && y2<=y_2) return true;
    return false;
}
bool in_area_spe(ll x_1,ll y_1,ll x_2,ll y_2,ll xx,ll yy) {
    if(xx>=x_1 && xx<=x_2 && yy>=y_1 && yy<=y_2 ) return true;
    return false;
}
ll chp(int x,int box) {
    if(box==1)
        switch(x) {
            case 1 : x=1; break;
            case 4 : x=2; break;
            case 13 : x=5; break;
            case 16 : x=6; break;
            default : break;
        }
    else if(box==2)
        switch(x) {
            case 1 : x=3; break;
            case 4 : x=4; break;
            case 13 : x=7; break;
            case 16 : x=8; break;
            default : break;
        }
    else if(box==3)
        switch(x) {
            case 1 : x=9; break;
            case 4 : x=10; break;
            case 13 : x=13; break;
            case 16 : x=14; break;
            default : break;
        }
    else if(box==4)
        switch(x) {
            case 1 : x=11; break;
            case 4 : x=12; break;
            case 13 : x=15; break;
            case 16 : x=16; break;
            default : break;
        }
    return x;
}
void SetDisc(ll x) {
    for(int i=1;i<=16;i++) for(int j=1;j<=16;j++) disc[i][j]=(i^j ? INF:0);
    disc[2][3]=disc[5][9]=disc[8][12]=disc[14][15]=1;
    disc[1][2]=disc[1][5]=x;
    disc[2][6]=disc[5][6]=x;
    disc[3][4]=disc[3][7]=x;
    disc[4][8]=disc[7][8]=x;
    disc[9][10]=disc[9][13]=x;
    disc[10][14]=disc[13][14]=x;
    disc[11][12]=disc[11][15]=x;
    disc[12][16]=disc[15][16]=x;
    for(int i=1;i<=16;i++) for(int j=i+1;j<=16;j++) disc[j][i]=disc[i][j];
}
A dv(ll x,int box,ll lx,ll ly,int mode) {
    ll cen=(r<<(x-1));
    A tmp;
    tmp.boxs=box;
    if(x==1) {
        if(!mode) {
            tmp.a=make_pair(abs(lx-x1)+abs(ly+1-y1_),1);
            tmp.b=make_pair(abs(lx+1-x1)+abs(ly+1-y1_),4);
            tmp.c=make_pair(abs(lx-x1)+abs(ly-y1_),13);
            tmp.d=make_pair(abs(lx+1-x1)+abs(ly-y1_),16);
        }else {
            tmp.a=make_pair(abs(lx-x2)+abs(ly+1-y2),1);
            tmp.b=make_pair(abs(lx+1-x2)+abs(ly+1-y2),4);
            tmp.c=make_pair(abs(lx-x2)+abs(ly-y2),13);
            tmp.d=make_pair(abs(lx+1-x2)+abs(ly-y2),16);
        }
        return tmp;
    }
    if(!mode) {
        if(in_area_spe(lx,ly,cen-1+lx,cen-1+ly,x1,y1_)) tmp=dv(x-1,3,lx,ly,0);
        else if(in_area_spe(lx,cen+ly,cen-1+lx,(cen<<1LL)-1+ly,x1,y1_)) tmp=dv(x-1,1,lx,cen+ly,0);
        else if(in_area_spe(cen+lx,cen+ly,(cen<<1LL)-1+lx,(cen<<1LL)-1+ly,x1,y1_)) tmp=dv(x-1,2,cen+lx,cen+ly,0);
        else if(in_area_spe(cen+lx,ly,(cen<<1LL)-1+lx,cen-1+ly,x1,y1_)) tmp=dv(x-1,4,cen+lx,ly,0);
    }else {
        if(in_area_spe(lx,ly,cen-1+lx,cen-1+ly,x2,y2)) tmp=dv(x-1,3,lx,ly,1);
        else if(in_area_spe(lx,cen+ly,cen-1+lx,(cen<<1LL)-1+ly,x2,y2)) tmp=dv(x-1,1,lx,cen+ly,1);
        else if(in_area_spe(cen+lx,cen+ly,(cen<<1LL)-1+lx,(cen<<1LL)-1+ly,x2,y2)) tmp=dv(x-1,2,cen+lx,cen+ly,1);
        else if(in_area_spe(cen+lx,ly,(cen<<1LL)-1+lx,cen-1+ly,x2,y2)) tmp=dv(x-1,4,cen+lx,ly,1);
    }
    SetDisc(cen-1);
    for(int i=1;i<=16;i++) {
        for(int j=1;j<=16;j++) {
            for(int k=1;k<=16;k++) {
                disc[j][k]=min(disc[j][k],disc[j][i]+disc[i][k]);
            }
        }
    }
    vector <pair<ll,ll>> u1;
    int aa=chp(tmp.a.nd,tmp.boxs);
    int bb=chp(tmp.b.nd,tmp.boxs);
    int cc=chp(tmp.c.nd,tmp.boxs);
    int dd=chp(tmp.d.nd,tmp.boxs);
    u1.emplace_back(aa,tmp.a.st);
    u1.emplace_back(bb,tmp.b.st);
    u1.emplace_back(cc,tmp.c.st);
    u1.emplace_back(dd,tmp.d.st);
    ll rin=INF;
    for(int i=0;i<4;i++) rin=min(rin,u1[i].nd+disc[u1[i].st][1]);
    tmp.a=make_pair(rin,1); rin=INF;
    for(int i=0;i<4;i++) rin=min(rin,u1[i].nd+disc[u1[i].st][4]);
    tmp.b=make_pair(rin,4); rin=INF;
    for(int i=0;i<4;i++) rin=min(rin,u1[i].nd+disc[u1[i].st][13]);
    tmp.c=make_pair(rin,13); rin=INF;
    for(int i=0;i<4;i++) rin=min(rin,u1[i].nd+disc[u1[i].st][16]);
    tmp.d=make_pair(rin,16); rin=INF;
    tmp.boxs=box;
    return tmp;
}
ll fv(ll x,ll lx,ll ly) {
    ll cen=(r<<(x-1));
    if(in_area(lx,ly,cen-1+lx,cen-1+ly)) return fv(x-1,lx,ly);
    if(in_area(lx,cen+ly,cen-1+lx,(cen<<1LL)-1+ly)) return fv(x-1,lx,cen+ly);
    if(in_area(cen+lx,cen+ly,(cen<<1LL)-1+lx,(cen<<1LL)-1+ly)) return fv(x-1,cen+lx,cen+ly);
    if(in_area(cen+lx,ly,(cen<<1LL)-1+lx,cen-1+ly)) return fv(x-1,cen+lx,ly);
    A S,E;
    if(in_area_spe(lx,ly,cen-1+lx,cen-1+ly,x1,y1_)) S=dv(x-1,3,lx,ly,0);
    if(in_area_spe(lx,cen+ly,cen-1+lx,(cen<<1LL)-1+ly,x1,y1_)) S=dv(x-1,1,lx,cen+ly,0);
    if(in_area_spe(cen+lx,cen+ly,(cen<<1LL)-1+lx,(cen<<1LL)-1+ly,x1,y1_)) S=dv(x-1,2,cen+lx,cen+ly,0);
    if(in_area_spe(cen+lx,ly,(cen<<1LL)-1+lx,cen-1+ly,x1,y1_)) S=dv(x-1,4,cen+lx,ly,0);
    if(in_area_spe(lx,ly,cen-1+lx,cen-1+ly,x2,y2)) E=dv(x-1,3,lx,ly,1);
    if(in_area_spe(lx,cen+ly,cen-1+lx,(cen<<1LL)-1+ly,x2,y2)) E=dv(x-1,1,lx,cen+ly,1);
    if(in_area_spe(cen+lx,cen+ly,(cen<<1LL)-1+lx,(cen<<1LL)-1+ly,x2,y2)) E=dv(x-1,2,cen+lx,cen+ly,1);
    if(in_area_spe(cen+lx,ly,(cen<<1LL)-1+lx,cen-1+ly,x2,y2)) E=dv(x-1,4,cen+lx,ly,1);
    SetDisc(cen-1);
    for(int i=1;i<=16;i++) {
        for(int j=1;j<=16;j++) {
            for(int k=1;k<=16;k++) {
                disc[j][k]=min(disc[j][k],disc[j][i]+disc[i][k]);
            }
        }
    }
    ll res=INF;
    vector <pair<ll,ll>> u1,u2;
    int aa=chp(S.a.nd,S.boxs);
    int bb=chp(S.b.nd,S.boxs);
    int cc=chp(S.c.nd,S.boxs);
    int dd=chp(S.d.nd,S.boxs);
    u1.emplace_back(aa,S.a.st);
    u1.emplace_back(bb,S.b.st);
    u1.emplace_back(cc,S.c.st);
    u1.emplace_back(dd,S.d.st);
    aa=chp(E.a.nd,E.boxs);
    bb=chp(E.b.nd,E.boxs);
    cc=chp(E.c.nd,E.boxs);
    dd=chp(E.d.nd,E.boxs);
    u2.emplace_back(aa,E.a.st);
    u2.emplace_back(bb,E.b.st);
    u2.emplace_back(cc,E.c.st);
    u2.emplace_back(dd,E.d.st);
    for(auto z:u1) {
        for(auto c:u2) {
            res=min(res,disc[z.st][c.st]+z.nd+c.nd);
        }
    }
    return res;
}
int main() {
    cin >> k >> x1 >> y1_ >> x2 >> y2;
    cout << fv(k,0,0);
}