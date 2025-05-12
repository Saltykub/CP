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
    // precal[i] = 2^i;
    precal[0] = 1;
    precal[1] = 2;
    for(int i = 2; i < 30; i++){
        precal[i] = precal[i-1] * precal[i-1];
        precal[i]%=MOD;
    }
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 0; i < 30; i++){
        if((1<<i) & n){
            ans*=precal[i+1];
            ans%=MOD;
        }
    }
    cout << ans;
