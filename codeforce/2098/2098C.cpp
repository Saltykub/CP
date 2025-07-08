#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> cnt;
    for(auto &x:v) cin >> x,cnt[x]++;
    vector<pii> cal;
    for(auto [val,c]:cnt){
        cal.pb({val,c});
    }
    sort(cal.begin(),cal.end());
    bool start = false;
    for(int i = 0; i < cal.size(); i++){
        auto [val,c] = cal[i];
        if(c >= 4) {
            cout << "Yes\n";
            return;
        }
        else if(c >= 2 && !start){
            start = true;
        }
        else if(c >= 2 )

    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}