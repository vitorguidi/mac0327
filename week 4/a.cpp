#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;

ll fastxp(ll a, ll b) {
	if(b==0)	return 1;
	if(b==1)	return a;

	if(b%2)	return (a*fastxp(a,b-1))%10;

	ll ans = fastxp(a, b/2)%10;

	return (ans*ans)%10;

}

int main(){

	fastio;

	int q; cin >> q;
	while(q--){
		ll a,b; 
		cin >> a >> b;
		cout << fastxp(a,b) << endl;
	}
	return 0;

}
