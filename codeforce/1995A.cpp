#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int n,k;
    cin >> n >> k;
    int ans = 0;
    int used = 1,cur = n;
    while(k > 0){
        k-=cur;
        used++;
        if(used == 2){
            cur--;
            used = 0;
        }
        ans++;
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