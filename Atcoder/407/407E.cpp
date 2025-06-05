#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 4e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vector<int> arr(2*n);
    for(auto &x:arr) cin >> x;
    priority_queue<int> pq;
    ll sm = 0;
    for(int i = 0; i < n; i++){
        if(i == 0) pq.push(arr[i]);
        else {
            pq.push(arr[2*i-1]);
            pq.push(arr[2*i]);
        }
        sm += pq.top();
        pq.pop();
    }
    cout << sm << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}