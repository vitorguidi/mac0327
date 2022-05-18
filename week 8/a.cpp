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

int main(){

	fastio;

	vector<int> dist(110, 1e9);
	set<tuple<int,int>> q;
	vector< vector<tuple<int,int>> > adj(110);

	int n,t,e,m;
	cin >> n >> e >> t >> m;

	fr(i,m) {
		int a,b,d;
		cin >> a >> b >> d;
		adj[b].push_back(make_tuple(a,d));
	}

	dist[e] = 0;
	q.insert( make_tuple(0,e) );

	while(!q.empty()) {

		tuple<int,int> t = *q.begin();
		q.erase(q.begin());

		int d,v;
		tie(d,v) = t;

		for(auto p : adj[v]) {
			int cost, u;
			tie(u,cost) = p;
			if(dist[u] > cost + d) {
				q.insert(make_tuple(cost + d, u));
				dist[u] = cost + d;
			}
		}
	}

	int amt = 0;
	for(int i=1;i<=n;i++) {
		amt += (dist[i]<=t);
	}

	cout << amt << endl;


}
