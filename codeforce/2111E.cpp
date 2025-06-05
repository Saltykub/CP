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
    int n,q;
    cin >> n >> q;
    set<int> bc,ba,cb,ca;
    string s;
    cin >> s;
    for(int i = 0; i < q; i++){
        char l,r;
        cin >> l >> r;
        if(l == 'b' && r == 'c') bc.insert(i);
        if(l == 'b' && r == 'a') ba.insert(i);
        if(l == 'c' && r == 'b') cb.insert(i);
        if(l == 'c' && r == 'a') ca.insert(i);
    }
    string ans = "";
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') ans += "a";
        else if (s[i] == 'b'){
            if(!ba.empty()){
                ba.erase(ba.begin());
                ans += "a";
            }
            else {
                if(!bc.empty() && !ca.empty()){
                    auto lb = ca.lower_bound(*bc.begin());
                    if(lb != ca.end()){
                        ans += "a";
                        bc.erase(bc.begin());
                        ca.erase(lb);
                    }
                    else {
                        ans += "b";
                    }
                }
                else{
                    ans += "b";
                }
            }
        }
        else {
            if(!ca.empty()){
                ca.erase(ca.begin());
                ans += "a";
            }
            else {
                if(!cb.empty()){
                    if(!ba.empty()){
                        auto lb = ba.lower_bound(*cb.begin());
                        if(lb != ba.end()){
                            ans += "a";
                            ba.erase(lb);
                        }
                        else {
                           ans += "b";
                        }
                        cb.erase(cb.begin());

                    }
                    else {
                        ans += "b";
                        cb.erase(cb.begin());
                    }
                }
                else {
                    ans += "c";
                }
            }
        }
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}