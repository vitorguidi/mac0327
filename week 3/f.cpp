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

	int n,m,k;
	cin >> n >> m >> k;

	vector<ll> v(n+1);
	vector<tuple<int,int,ll>> ops(m+1);
	vector<ll> adder(m+1);
	vector<ll> remover(m+2);
	vector<ll> adder_v(n+1);
	vector<ll> remover_v(n+2);

	frr(i,n)	cin >> v[i];

	frr(i,m) {
		int l,r,d;
		cin >> l >> r >> d;
		ops[i] = make_tuple(l,r,d);
	}

	frr(i,k) { 
		int l,r;
		cin >> l >> r;
		adder[l]+=1;
		remover[r+1]+=1;
	}

	ll sum = 0;
	frr(i,m) {
		sum+=adder[i];
		sum-=remover[i];
		int l,r;
		ll d;
		tie(l,r,d) = ops[i];
		d *= sum;
		adder_v[l]+=d;
		remover_v[r+1]+=d;
	}

	ll sum_v = 0;
	frr(i,n) {
		sum_v+=adder_v[i];
		sum_v-=remover_v[i];
		v[i]+=sum_v;
	}

	frr(i,n) {
		cout << v[i] << " ";
	}

	cout << endl;


}
