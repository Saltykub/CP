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
    for(auto &u:v) cin >> u;
    sort(v.begin(),v.end());
    vector<pii> cal;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1]) cnt++;
        else {
            cal.pb({v[i-1],cnt});
            cnt = 1;
        }
        if(cnt >= 4){
            cout << "Yes\n";
            return;
        }
    }
    cal.pb({v[n-1],cnt});
    bool start = false;
    if(cal[0].nd >= 2) start = true;
    for(int i = 1; i < cal.size(); i++){
        if(cal[i].nd >= 2){
            if(cal[i].st-1 == cal[i-1].st && start){
                cout << "Yes\n";
                return;
            }
            start = true;
        } 
        else if(cal[i].st-1 != cal[i-1].st){
            start = false;
        }
    }
    cout << "No\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}