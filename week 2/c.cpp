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

int go() {
	ll k,n,a,b;
	cin >> k >> n >> a >> b;

	int ini=0;
	int end=n;

	ll fin_charge = k-n*a;

	while(ini<=end) {
		ll mid = (ini+end)/2;
		if(fin_charge + mid*(a-b)>0) {
			end=mid-1;
		}
		else {
			ini=mid+1;
		}
	}

	ll ans = end+1;
	if(ans>=0 && k-(ans*b +(n-ans)*a)>0) {
		return n-ans;
	}
	return -1;
}

int main(){

	fastio;

	int q; cin >> q;
	while(q--) {
		cout <<go()<<endl;
	}

}
