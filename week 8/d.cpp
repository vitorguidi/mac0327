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

	string s; cin >> s;
	int n = s.size();

	vector<vector<int>> adj(26);
	vector<int> dist(n+1, 1e9);

	dist[0]=0;
	queue<int> q;
	q.push(0);

	fr(i,n) {
		adj[ s[i]-'0' ].push_back(i);
	}

	while(!q.empty()) {
		int v = q.front();
		q.pop();

		if(v-1>=0 && dist[v-1]==1e9) {
			dist[v-1]=1+dist[v];
			q.push(v-1);
		}

		if(v+1<n && dist[v+1]==1e9) {
			dist[v+1]=1+dist[v];
			q.push(v+1);
		}

		for(auto x : adj[ s[v]-'0' ]) {
			if (dist[x]==1e9){
				dist[x]=1+dist[v];
				q.push(x);
			}
		}
		adj[s[v]-'0'].clear();

	} 

	cout << dist[n-1]<<endl;


}
