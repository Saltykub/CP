#include <bits/stdc++.h>
#define ii pair<int, int>
#define st first
#define nd second
using namespace std;
ii a[100001];
int main(){
	int N;
	scanf("%d", &N);
	for(int i = 1, x; i <= N; i++){
		scanf("%d", &x);
		a[x].first = i;
	}
	for(int i = 1, x; i <= N; i++){
		scanf("%d", &x);
		a[x].second = i;
		if(a[x].second > a[x].first) swap(a[x].first, a[x].second);
	}
	sort(a + 1, a + N + 1);
	int old = 0, cnt = 0;
	for(int i = 1; i <= N; i++){
		if(a[i].second >= old){
			cnt++; old = a[i].first;
		}
	}
	printf("%d", cnt);
}