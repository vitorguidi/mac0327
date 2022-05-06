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

	ll mod = 998244353;

	ll fat[1010];
	fat[0]=1;
	for(ll i=1;i<=1000;i++) {
		fat[i]=(i*fat[i-1])%mod;
	}

	int q; cin >> q;
	while(q--) {
		ll n; cin >> n;
		if(n%2==1) {
			cout << 0 << endl;
			continue;
		}
		n = (n/2);
		ll ans = (fat[n]*fat[n])%mod;
		cout << ans << endl;
	}

}



//1 0		0
//2 1^2		1
//3 0	    0
//4 2^2		4
//5 0		0
//6 6^2		36
//7 0 		0
//8 24^2	576
//9 0		0
//10 120^2	14400
//11 		0
//12 720^2     518400

// 1 2 6 24 120 720
// 1! 2! 3! 4! 5! 6!


