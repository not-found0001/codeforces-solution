#include <bits/stdc++.h>

using namespace std;

int N,Q;
int arr[100005], Ans[100005];
bool mark[100005];

void solve(int pos, int res)
{
	if(pos == -1) return ;
	
	if(!mark[arr[pos]]){
		mark[arr[pos]] = 1;
		Ans[pos] = ++res;
		solve(pos-1, res);
	}
	else{
		Ans[pos] = res;
		solve(pos-1, res);
	} 
}

int main()
{
	ios::sync_with_stdio(false);
	
	N, Q;
	cin>>N>>Q;
	for(int i=0 ; i<N ; i++) cin>>arr[i];
	
	solve(N-1, 0);
	
	while(Q--){
		int x;
		cin>>x;
		cout << Ans[x-1] <<endl;
	}
	
	return 0;
} 
