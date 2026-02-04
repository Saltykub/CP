#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2)cout<<-1;
    else {
        int c1=0,c0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')c0++;
            else c1++;
        }
        if(c1!=c0)cout<<-1;
        else {
            deque<int> dq;
            int f=0,b=n;
            vector<int> ans;
            for(int i=0;i<n;i++)dq.push_back(s[i]-'0');
            while(!dq.empty()){
                if(dq.back()!=dq.front()){
                    dq.pop_back();
                    dq.pop_front();
                    f++;
                    b--;
                }
                else {
                    if(dq.front()==1){
                        dq.push_front(1);dq.pop_back();
                        ans.push_back(f);
                        f++;
                        b++;
                    }
                    else 
                    {
                        dq.pop_front();dq.push_back(0);
                        ans.push_back(b);
                        b++;
                        f++;
                    }
                }
            }
            cout<<ans.size()<<"\n";
            for(auto u: ans)cout<<u<<" ";
            ans.clear();
        }  
    }
    cout<<"\n";
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}