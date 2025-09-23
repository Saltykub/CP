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
    int q;
    cin >> q;
    priority_queue<int,vector<int>,greater<int>> pq;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            pq.push(x);
        }
        else {
            cout << pq.top() << "\n";
            pq.pop();
        }
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