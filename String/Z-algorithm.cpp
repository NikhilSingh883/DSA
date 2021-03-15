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
#define v(x) vector<x>
#define s(x) set<x>
#define mp make_pair
const ll mxN = 2e5;
const ll mod = 1e9 + 7;
const ll N = 1005;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

v(ll) calculateZ(string input){
    ll n = input.size();

    v(ll) Z(n);
    ll left=0,right=0;

    rep(k,0,n){
        if(k>right){
            left = right = k;

            while(right < n && input[right] == input[right-left])
                right++;
            Z[k] = right - left;
            right--;
        }
        else {
            ll k1 = k- left;
            if(Z[k1] < right - k + 1)
                Z[k1] = Z[k];
            else{
                left = k;

                while(right < n && input[right] == input[right-left])
                    right++;
                Z[k] = right - left;
                right--;
            }
        }
    }

    return Z;
}

v(ll) patternmatch(string text,string pattern){
    string newString = pattern;
    newString += '$';
    newString += text;

    v(ll) Z = calculateZ(newString);

    v(ll) res;

    rep(k,0,newString.size())
        if(Z[k] == pattern.size())
            res.pb(k-pattern.size()-1);

    return res;
}
