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


void go() {

	int n,r,m;
	scanf("%d %d %d",&n,&r,&m);

	vector<vector<int>> adj(n);
	vector<int> dad(n, -1);
	vector<int> dist(n, INF);

	queue<tuple<int,int,int>> q;

	bool overlap = false;

	fr(i,r) {
		int a,b;
		scanf("%d %d",&a,&b);

		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fr(i,m) {
		int k,s;
		scanf("%d %d",&k,&s);
		k--;

		dist[k] = 0;
		dad[k]=k;
		q.push(make_tuple(k,s,k));
	}

	while(!q.empty()) {
		tuple<int,int,int> t = q.front();
		q.pop();
		int v,s,from;
		tie(v,s,from) = t;

		if(s==0)	continue;
		for(auto x : adj[v]) {
			if(dist[x]==INF) {
				dist[x] = 1 + dist[v];
				dad[x]=from;
				q.push(make_tuple(x,s-1,from));
			}
			else if(dad[x]!=from){	
				overlap = true;
			}
		}

	}

	// fr(i,n) {
	// 	printf("%d\n",dad[i]);
	// }
	// cout << "###" << endl;

	bool allcovered = true;
	fr(i,n){
		if(dist[i]==INF)	allcovered=false;
	}

	if(allcovered && !overlap) {
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}


}

int main(){


	int t;
	scanf("%d",&t);
	while(t--) {
		go();
	}

}
