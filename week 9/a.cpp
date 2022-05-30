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

int cmp[10010];
int sz[10100];


int find(int x) {
	if(cmp[x]!=x)	return cmp[x]=find(cmp[x]);
	return x;
}

void join(int a, int b) {
	a=find(a);
	b=find(b);
	if(sz[a]<sz[b])	swap(a,b);
	sz[a]+=sz[b];
	cmp[b]=a;

}

int main(){

	fastio;

	set< tuple<int,int,int> > s;
	int n; cin >> n;
	
	frr(i,n)	cmp[i]=i;

	int m; cin >> m;
	ll cost = 0;
	fr(i,m) {
		int a,b;
		ll c;
		cin >> a >> b >> c;
		s.insert(make_tuple(c,a,b));
	}

	for(auto edg : s) {
		int a,b,c; 
		tie(c,a,b) = edg;
		if(find(a)!=find(b)) {
			cost += c; 
			join(a,b);
		}
	}

	cout << cost << endl;

}
