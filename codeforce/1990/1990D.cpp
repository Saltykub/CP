#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i=0; i < n;i++) cin >> a[i];
   ll ans = 0;
   for(int i = 0; i < n; i++) {
    if(a[i] == 0) continue;
     if(a[i] > 2) ans++;
     else {
            if(i + 1 < n && a[i+1] <= 2 ){
                ans += 1;
                i+=1;
            }
            else if(i + 3 < n && a[i + 1] <= 4 && a[i + 2] <= 4 && a[i+3] <= 2 && a[i+1] > 2 && a[i+2] > 2){
                ans += 3;
                i+=3;
            }
            else {
                ans++;
            }
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