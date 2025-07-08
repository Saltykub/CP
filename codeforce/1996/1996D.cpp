#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve(){
    int n,x;
    cin >> n >> x;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(min((n-i*j)/(i+j),x-i-j) <= 0) break;
            ans += min((n-i*j)/(i+j),x-i-j);
        }
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}