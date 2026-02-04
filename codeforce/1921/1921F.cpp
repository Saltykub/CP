#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e5+2;
ll qs[405][N] , qs2[405][N];
void solve (){
    int n,q;
    cin >> n >> q;
    ll arr[n+2];
    for(int i = 0; i < 400; i++)for(int j = 0; j < n + 2; j++) qs[i][j] = qs2[i][j] = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i < 400; i++){
        if(i > n)break;
        for(int j = 1; j <= i; j++) qs[i][j] = qs2[i][j] = arr[j];
        for(int j=i+1;j <= n;j++){
            qs[i][j]=arr[j]+qs[i][j-i];
            qs2[i][j]=arr[j]*(ceil(1.0*j/i))+qs2[i][j-i];
        }
    }
    while(q--){
        ll s,d,k;
        cin >> s >> d >> k;
        if(d < 395){
            int r = s + d*(k-1);
            ll ans = qs2[d][r];
            if(s-d > 0) ans =  qs2[d][r] - qs2[d][s-d] - (qs[d][r] - qs[d][s-d])*(ceil(1.0*s/d)-1); 
            cout << ans << " ";
        }   
        else {
            ll ans = 0;
            int cnt = 1;
            for(int i = s; i <= s+d*(k-1); i+= d){
                ans += arr[i]*cnt;
                cnt ++;
            }
            cout << ans << " ";
        }
    }
    cout <<'\n';
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