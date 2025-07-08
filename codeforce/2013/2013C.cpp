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
    string ans = "";
    for(int i = 0; i < n; i++){
        if(ans.size() == n) break;
        string t0 = ans, t1 = ans;
        t0+="0";
        t1+="1";
        int q1 = 1,q0 = 1;
        cout << "? " << t0 << endl;
        cin >> q0;
        if(q0) ans = t0;  
        else {cout << "? " << t1 << endl;
        cin >> q1; }
        if(!q0 && !q1) break;
        if(!q0 && q1) ans = t1;
    }
    if(ans.size() == n) {
        cout << "! " << ans << endl;
        return;
    }
    int sz = ans.size();
    for(int i = sz; i < n; i++){
        string t0 = "0"+ans, t1 = "1"+ans;
        int q0 = 1;
        cout << "? " << t0 << endl;
        cin >> q0;
        if(q0) ans = t0;
        else ans = t1;
        if(ans.size() == n) break;
    }
    cout << "! " << ans << endl;
    return;
    
}
int main(){   
   // ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }
 
}
