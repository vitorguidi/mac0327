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

int n, m, w;

bool solve(vector<int> &v, int tgt) {

	vector<int> rem(n+1);
	int add=0;
	int left = m;

	for(int i=0;i<n;i++) {
		// printf("i=%d v=%d\n",i, v[i]+add-rem[i]);
		add-=rem[i];
		if(v[i]+add>=tgt)	
			continue;
		int delta=tgt-(v[i]+add);
		if (delta>left)	
			return false;
		int right = min(n, i+w);
		rem[right]+=delta;
		add+=delta;
		left-=delta;
	}

	return true;

}

int main(){

	fastio;

	cin >> n >> m >> w;

	vector<int> v(n);

	int mx=0;

	fr(i,n) { 
		cin >> v[i];
		mx=max(mx,v[i]);
	}

	int ini=1;
	int end=mx+m;

	// solve(v,500);

	while(ini<=end) {
		int mid = (ini+end)/2;
		// cout << mid << endl;
		if(solve(v, mid)) {
			ini=mid+1;
		}
		else { 
			end=mid-1;
		}
	}

	cout << ini-1 << endl;

}
