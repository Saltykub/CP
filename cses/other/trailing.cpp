#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
const int MOD = 1e9+7;
vector<ll> precal (30);
int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i < 30; i++){
        ll use = pow(5,i);
        if(use > n) break;
        ans += n/use;
    }
    cout << ans;
}