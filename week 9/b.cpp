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

map<int,int> sz;
map<int,int> cmp;

int ans;
int find(int a) {
	if(a!=cmp[a])	return cmp[a]=find(cmp[a]);
	else			return a;
}

void join(int a, int b) {
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	sz[a]+=sz[b];
	cmp[b]=a;
	ans--;
}

int main(){

	fastio;

	int n,m;
	cin >> n >> m;

	ans = n;

	fr(i,m) {
		int a,b;
		cin >> a >> b; 
		if(sz.find(a)==sz.end()) {
			sz[a]=1;
			cmp[a]=a;
		}
		if(sz.find(b)==sz.end()) {
			sz[b]=1;
			cmp[b]=b;
		}
		if (find(a)!=find(b)) {
			join(a,b);
		}
	}
	
	cout << ans << endl;

}
