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

void dfs(int v, vector<vector<int>> &adj, vector<int> &vis) {
	if(vis[v])	return;
	vis[v]=1;
	for(auto x : adj[v]){
		dfs(x, adj, vis);
	}
}

int main(){

	fastio;
	int n,m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<int> vis(n);

	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b; 
				a--;b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, adj, vis);

	for(int i=0;i<n;i++) {
		if(!vis[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << (m==n ? "FHTAGN!" : "NO") << endl;

}
