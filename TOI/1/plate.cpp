#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int> mp;
    int n1,n2;
    cin >> n1 >> n2;
    while(n2--){
        int e,id;
        cin >> e >> id;
        mp[id] = e;
    }
    queue<int> q1; 
    queue<int> q2[15];
    vector<int> cnt(15,0);
    while(true){
        char o;
        cin >> o;
        if(o == 'X') {
            cout << 0; break;
        }
        if(o == 'D'){
            cout<<q2[q1.front()].front()<<"\n";
            q2[q1.front()].pop();
            if(--cnt[q1.front()] == 0) q1.pop();
        }
        if(o == 'E'){
            int x; 
            cin >> x;
            q2[mp[x]].push(x);
            if(cnt[mp[x]] == 0)q1.push(mp[x]);
            cnt[mp[x]]++;
        }
    }
}