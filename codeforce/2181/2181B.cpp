#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,m;
    cin >> n >> m;
    priority_queue<int> pqa,pqb;
    while(n--){
        int x;
        cin >> x;
        pqa.push(x);
    }
    while(m--){
        int x;
        cin >> x;
        pqb.push(x);
    }
    while(!pqa.empty() && !pqb.empty()){
        int ta = pqa.top(), tb = pqb.top();
        pqb.pop();
        if(ta < tb) pqb.push(tb-ta);
       // cout << ta << " " << tb << "\n";
        if(pqa.empty() || pqb.empty()) break;
        ta = pqa.top(); tb = pqb.top();
        pqa.pop();
        if(tb < ta) pqa.push(ta-tb);
       // cout << p << " " << pqb.top() << "\n";
    }
    if(pqa.empty()) cout << "Bob" << "\n";
    else cout << "Alice\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}