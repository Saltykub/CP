#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int main(){
    int n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        ll ans = i*i*(i*i-1)/2 - (2*(i-2)*2*(i-1));
        cout << ans << "\n";
    }
}