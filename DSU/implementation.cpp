#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<int,int>
#define f first
#define s second
#define pll pair<ll, ll>
#define vpl vector<pll>
#define vl vector<ll>
#define vll vector<ll, ll>
#define mp make_pair
#define rep(x,start,end,k) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x+=k:x-=k))
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1005;

int root(vl a,ll i){
    while(a[i] != i){
        a[i] = a[a[i]];
        i = a[i];
    }
    return i;
}

void height_union(vl a,vl size,ll A,ll B){
    ll rootA = root(a,A);
    ll rootB = root(a,B);

    if(size[rootA] < size[rootB]){
        a[rootA] = a[rootB];
        size[rootB] += size[rootA];
    }
    else {
        a[rootB] = a[rootA];
        size[rootA] += size[rootB];
    }

}

void initialize(vl &a,ll n,vl &size){
    rep(i,0,n,1){
        a[i] = i;
        size[i] = 1;
    }
}

