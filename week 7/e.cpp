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

ll dfs(int v, vector<vector<int>> &adj, vector<int> &vis) {
	if(vis[v])	
		return 0;

	ll ans = 1;
	vis[v]=1;

	for(auto x : adj[v]) {
		ans += dfs(x,adj,vis);
	}

	return ans;
}


void go() {

	int n,m;
	cin >> n >> m;

	ll MOD = 1e9+7;

	vector<vector<int>> adj(n);
	vector<int> vis(n);

	fr(i,m) {
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	ll ans = 1;
	int cnt = 0;

	for(int i=0;i<n;i++) {
		if(!vis[i])	{ans = (ans*dfs(i,adj,vis))%MOD;cnt++;}
	}

	cout << cnt << " " << ans << endl;


}

int main(){

	fastio;

	int q; cin >> q;
	while(q--)	go();

}
