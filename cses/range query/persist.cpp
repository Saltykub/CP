#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
int arr[N];
struct Node{
    ll val;
    Node *l,*r;
    Node(ll x) : val(x), l(nullptr), r(nullptr){}
    Node(Node *a, Node *b){
        l = a, r = b;
        val = 0;
        if (l) val += l->val;
        if (r) val += r->val;
    }
    Node(Node *node) : val(node->val), l(node->l), r(node->r){}
};
int lv=1;
Node *t[4*N];
Node *build(int tl,int tr){
    if(tl == tr) {return new Node(arr[tl]); }
    int m = (tl + tr)/2;
    return new Node(build(tl,m),build(m+1,tr));
}
Node *update(Node *node,int tl, int tr, int val,int pos){
    if(tl == tr) return new Node(val);
    int m = (tl + tr)/2;
    if(pos > m) return new Node(node -> l,update(node -> r,m+1,tr,val,pos));
    else return new Node(update(node -> l,tl,m,val,pos),node -> r);
}
ll query(Node *node,int tl,int tr,int l,int r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return node->val;
    int m = (tl + tr)/2;
    return query(node->l,tl,m,l,r) + query(node ->r,m+1,tr,l,r);
}
int main(){
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> arr[i];
    t[lv++]=build(1,n);
    while(q--){
        int o;
        cin >> o;
        if( o == 1){
            int k,pos,val;
            cin>>k>>pos>>val;
            t[k] = update(t[k],1,n,val,pos);
        }
        else if(o==2){
            int k, l, r;
            cin >> k >> l >> r;
            cout << query(t[k],1,n,l,r)<<"\n";
        }
        else {
            int k; cin >> k;
            t[lv++] = new Node(t[k]);
        }
    }
}