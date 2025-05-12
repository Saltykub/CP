#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
int cnt[N];
set<ll> ss;
string s;
priority_queue<int> pq;
void add(int x){
    if(x == 0 || x == s.size()) return;
    auto it = ss.find(x);
    if(it != ss.end()){
        int a = *prev(it), b = *next(it);
        ss.erase(it);
        cnt[x-a]--;
        cnt[b-x]--;
        cnt[b-a]++;
        pq.push(b-a);
    }
    else {
        ss.insert(x);
        it = ss.find(x);
        int a = *prev(it), b = *next(it);
        cnt[b-a]--;
        cnt[x-a]++;
        cnt[b-x]++;
        pq.push(x-a); pq.push(b-x);
    }
}
void solve (){
    cin >> s;
    ss.insert(0);
    ss.insert(s.size());
  
    for(int i = 0; i < s.size()-1; i++){
        if(s[i]!=s[i+1]) ss.insert(i+1);
    }
    for(auto it = ss.begin(); next(it) != ss.end(); it++){
        pq.push((*next(it)-*it));
        cnt[*next(it)-*it]++;
    }
    ll m;
    cin >> m;
    while(m--){
        ll x;
        cin >> x;
        add(x-1);
        add(x);
        while(!cnt[pq.top()]) pq.pop();
        cout << pq.top() << " ";
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