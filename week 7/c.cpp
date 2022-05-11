#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

void dfs(int v, vector<int> &vis, vector<vector<int>> &adj) {

	if(vis[v])	return;
	vis[v]=1;

	for(auto x : adj[v]){
		dfs(x,vis,adj);
	}

}

void go() {
	int n,m,l;
	cin >> n >> m >> l;

	vector<vector<int>> adj(n);
	
	for(int i=0;i<m;i++) {
		int x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].push_back(y);
	}

	vector<int> vis(n);

	for(int i=0;i<l;i++) {
		int x; cin >> x;
		x--;
		dfs(x, vis, adj);
	}

	int cnt = 0;
	for(auto x : vis) {
		cnt+= x;
	}

	cout << cnt << endl;

}

int main(){

	fastio;

	int q; cin >> q;
	while(q--) {
		go();
	}

}
