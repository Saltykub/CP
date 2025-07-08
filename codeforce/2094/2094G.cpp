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
    int q;
    cin >> q;
    deque<int> dq;
    ll s = 0, sm = 0;
    bool bk = true;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int bn;
            if(bk){
                bn = dq.back();
                dq.pop_back();
                dq.push_front(bn);
            }
            else {
                bn = dq.front();
                dq.pop_front();
                dq.push_back(bn);
            }
            s = s-(dq.size()-1)*bn + sm - bn;
        }
        else if(op == 2){
            s = sm*(dq.size() + 1) - s;
            bk = !bk;
        }
        else if(op == 3){
            int k;
            cin >> k;
            if(bk) dq.push_back(k);
            else dq.push_front(k);
            s += dq.size()*k;
            sm += k;
        }
        cout << s << "\n";
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