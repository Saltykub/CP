#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> def,atk;
    for(int i = 0; i < n; i++){
        string po;
        int str;
        cin >> po >> str;
        if(po == "DEF") def.pb(str);
        else atk.pb(str);
    }
    vector<int> card(m);
    multiset<int> s;
    for(int i = 0; i < m; i++) cin >> card[i];
    for(auto u:card) s.insert(u);
    bool can = true;
    for(auto u:def){
        auto it = s.upper_bound(u);
        if(it == s.end()) {
            can = false;
            break;
        }
        else s.erase(it);
    }
    ll ans1 = 0, ans2 = 0;
    sort(atk.begin(),atk.end());
    if(can){
        vector<int> temp;
        for(auto u:s) temp.pb(u);
        sort(temp.begin(),temp.end(),greater<int>());
        bool cann = true;
        for(int i = 0; i < min(temp.size(),atk.size()); i++){
            if(temp[i] < atk[i]) {
                cann = false;
                break;
            }
            ans1+=temp[i]-atk[i];
        }
        if(temp.size() > atk.size() && cann){
            for(int i =  atk.size(); i < temp.size(); i++){
                ans1+=temp[i];
            }
        }
        ll ans3 = 0;
        sort(atk.begin(),atk.end(),greater<int>());
        cann = true;
        for(int i = 0; i < min(temp.size(),atk.size()); i++){
             if(temp[i] < atk[i]) {
                cann = false;
                break;
            }
            ans3+=temp[i]-atk[i];
        }
        if(temp.size() > atk.size() && cann){
            for(int i =  atk.size(); i < temp.size(); i++){
                ans3+=temp[i];
            }
        }
        ans1 = max(ans1,ans3);
    }
    sort(atk.begin(),atk.end());
    sort(card.begin(),card.end(),greater<int>());
    for(int i = 0; i < min(card.size(),atk.size()); i++){
        if(card[i] < atk[i]) break;
        ans2+=card[i]-atk[i];
    }
    cout << max(ans1,ans2);
    
    

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}