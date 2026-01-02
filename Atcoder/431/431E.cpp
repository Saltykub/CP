#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
#define piii pair<pii,pii>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int gdi(int di, char c){
    if(c == 'A') return di;
    if(c == 'B'){
        if(di == 0) return 1;
        if(di == 1) return 0;
        if(di == 2) return 3;
        if(di == 3) return 2;
    }
    if(c == 'C'){
        // if(di == 0) return 2;
        // if(di == 1) return 3;
        // if(di == 2) return 0;
        // if(di == 3) return 1;
        return (di+2)%4;
    }
}
void solve (){
    int h,w;
    cin >> h >> w;
    vector<string> tab(h);
    for(auto &u:tab) cin >> u;
    int dis[h][w][4];
    // dis[i][j][k] = min op to make light pass through channel ith jth with direction kth 
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) for(int k = 0; k < 4; k++) dis[i][j][k] = INT_MAX;
    pii d[4] = {{0,1},{1,0},{-1,0},{0,-1}}; // r d u l 
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    if(tab[0][0] == 'A') {
        pq.push({{0,0},{0,0}});
        pq.push({{1,1},{0,0}});
        pq.push({{1,2},{0,0}});
        dis[0][0][0] = 0;
        dis[0][0][1] = 1;
        dis[0][0][2] = 1;
    }
    else if(tab[0][0] == 'B'){
        pq.push({{1,0},{0,0}});
        pq.push({{0,1},{0,0}});
        pq.push({{1,2},{0,0}});
        dis[0][0][0] = 1;
        dis[0][0][1] = 0;
        dis[0][0][2] = 1;
    }
    else if(tab[0][0] == 'C'){
        pq.push({{1,0},{0,0}});
        pq.push({{1,1},{0,0}});
        pq.push({{0,2},{0,0}});
        dis[0][0][0] = 1;
        dis[0][0][1] = 1;
        dis[0][0][2] = 0;
    }
    while(!pq.empty()){
        auto [curdi,xy] = pq.top();
        auto [cur,di] = curdi;
        auto [x,y] = xy;
        pq.pop();
        
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