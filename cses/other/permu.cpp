#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb emplace_back
using namespace std;
const int N = 1e6+3, mod = 1e9+7;
int main(){
   int n;
   cin >> n;
   if(n == 1) {cout << 1; return 0;}
   if(n <= 3) {cout << "NO SOLUTION"; return 0;}
   deque<int> dq;
   dq.push_back(2);
   dq.push_back(4);
   dq.push_back(1);
   dq.push_back(3);
   for(int i = 5; i <= n; i++){
     if(i % 2) dq.push_front(i);
     else dq.push_back(i);
   }
   while(!dq.empty()){
     cout << dq.front() << " ";
     dq.pop_front();
   }
    
}