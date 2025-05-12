#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool findd[N];
int main()
{
    string s;
    cin>>s;
    int cur=1;
    int ans=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])cur++;
        else cur=1;
        ans=max(ans,cur);
    }
    cout<<ans;
}