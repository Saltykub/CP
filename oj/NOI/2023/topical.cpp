#include<bits/stdc++.h>
#define ll long long 
#define st first
#define nd second 
#define pii pair<int,int>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> u(n,vector<int>(k)),r(n,vector<int>(k));
    for(int i = 0; i < n; i++)for(int j = 0; j < k; j++) cin >> r[i][j];
    for(int i = 0; i < n; i++)for(int j = 0; j < k; j++) cin >> u[i][j];
    vector<int> cur (k,0), cntcol(k,0), cntrow(n,0), use(n,0);
    vector<pii> vec[k];
    queue<int> q;
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool can = true;
        for(int j = 0; j < k; j++){
            if(r[i][j] > 0) can = false;
            vec[j].push_back({r[i][j],i});
        }
        if(can){
            q.push(i);
            use[i] = 1;
        }
    }
    for(int i = 0; i < k; i++)sort(vec[i].begin(),vec[i].end());
    while(!q.empty()){
        int fr = q.front();
        ans++;
        q.pop();
        for(int i = 0; i < k; i++){
            cur[i] += u[fr][i];
            while(cntcol[i] < n && vec[i][cntcol[i]].st <= cur[i]){
                cntrow[vec[i][cntcol[i]].nd]++;
                if(cntrow[vec[i][cntcol[i]].nd] == k && !use[vec[i][cntcol[i]].nd]){
                    q.push(vec[i][cntcol[i]].nd);
                    use[vec[i][cntcol[i]].nd] = 1;
                }
                cntcol[i]++;
            }
        }
    }
    cout << ans;
   
}