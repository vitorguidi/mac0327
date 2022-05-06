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
	int n;
	string s;
	char c;

	cin >> n >> s >> c; 
	
	vector<int> last(n+1, -1);
	ll ans = 0;
	
	for(int i=1;i<=n;i++) {
		if( s[i-1]==c ) {
			last[i]=max(last[i-1],i);
		}
		else {
			last[i]=last[i-1];
		}
		if(last[i]!=-1)	ans+=last[i];
	}
	cout << ans << endl;

}

int main(){

	fastio;
	int q; cin >> q;
	while(q--) {
		go();
	}

}
