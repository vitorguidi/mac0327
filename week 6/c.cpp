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

ll comb(ll n, ll k) {
	ll ans = 1;
	k = min(k,n-k);
	for (ll i=1;i<=k;i++) {
		ll gcd = __gcd(n-i+1,i);
		ans *= (n-i+1)/gcd;
		ans /= i/gcd;
	}
	return ans;
}



int main(){

	fastio;

	int q;
	cin >> q;
	while(q--) {
		ll n,k; 
		cin >> n >> k;
		if(n==k) {
			cout << 1 << endl;
			continue;
		}
		cout << comb(n-1,k-1) << endl;
	}

}


//star bars: n els, k colors = C(n+k-1,k-1)

//problem equivalent to n-k els, k colors = C(n+k-1-k,k-1) = C(n-1, k-1)


// n n-1 n-k+1 
// 1 2    k