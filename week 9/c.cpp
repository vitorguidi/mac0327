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

int sz[100100];
int cmp[100100];
int cnt;
multiset<int> s;

int find(int x) {
	if(x!=cmp[x])	return cmp[x]=find(cmp[x]);
	return x;
}

void join(int a, int b) {
	a=find(a);b=find(b);
	if(a==b)	return;
	s.erase(s.find(sz[a]));
	s.erase(s.find(sz[b]));
	sz[a]+=sz[b];
	cmp[b]=a;
	s.insert(sz[a]);
	cnt--;
}

int main(){

	fastio;

	int n,q;
	cin >> n >> q;

	cnt = n;

	frr(i,n) {
		sz[i]=1;
		cmp[i]=i;
		s.insert(1);
	}

	while(q--) {
		int a,b;
		cin >> a >> b; 

		join(a,b);
		if(cnt > 1)	cout << *s.rbegin() - *s.begin() << endl;
		else		cout << 0 << endl;
	}


}
