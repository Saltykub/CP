#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
void solve (){
   ll n,m;
   cin >> n >> m;
   ll mx = 0;
   for(int i = 0; i < n; i++){
        int sz;
        cin >> sz;
        set<int> s;
        for(int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        int use = false;
        for(ll j = 0; j <= sz+1; j++){
            if(!s.count(j)){
                if(!use){
                    use = true;
                }
                else {
                    mx = max(mx,j);
                    break;
                }
            }
        }
   }
   //cout << mx << " ";
   cout << (min(mx,m)+1)*mx + (m*(m+1)/2) - (min(mx,m)*(min(mx,m)+1))/2 << "\n";
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