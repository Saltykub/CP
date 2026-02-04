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
    ll s;
    vector<pii> ans;
    if(n == 1){
        for(int i = 1;i <= 9999; i++){
            ans.pb({i+1,i});
        }
    }
    else {
    if(n <= 9){
    s = n;
    for(int i =1; i <= 5; i++){
        s += n*pow(10,i);
        ll cal = s-(i+1);
        if(cal%(n-1) == 0){
            if(cal/(n-1) > 10000) break;
            ans.push_back({cal/(n-1),cal/(n-1)-(i+1)});
        }
      }
    }
    else if (n <=  99 ){
        int one = n%10, dec = n/10;
        s = dec;
        for(int i = 1; i <= 10; i++){
            s*=10;
            if(i%2) s+= one;
            else s+=dec;
            ll cal = s-(i+1);
            if(cal%(n-2) == 0){
                if(cal/(n-2) > 10000) break;
                if(2*cal/(n-2) - i - 1 > 10000) break;
                if(2*cal/(n-2) - i - 1 == 0) continue;
                ans.push_back({cal/(n-2),2*cal/(n-2)-(i+1)});
            }
        }
    }
    else {
         int one = n%10, dec = (n%100)/10, hun = n/100;
         s = hun;
         for(int i = 1; i <= 20; i++){
            s*=10;
            if(i%3 == 1) s+= dec;
            else if (i%3 == 2) s+=one;
            else s+=hun;
            ll cal = s-(i+1);
            if(cal%(n-3) == 0){
                if(cal/(n-3) > 10000) break;
                if(3*cal/(n-3) - i - 1 > 10000) break;
                if(3*cal/(n-3) - i - 1 == 0) continue;
                ans.push_back({cal/(n-3),3*cal/(n-3)-(i+1)});
            }
        }
    }
    }
    cout << ans.size() << "\n";
    for(auto u:ans){
        cout << u.st << " " << u.nd << "\n";
    }
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