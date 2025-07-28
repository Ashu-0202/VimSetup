// <-- Code By: Ashu Mittal -->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include "../.vim/testlib.h"
using namespace std;
using namespace __gnu_pbds;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T> >;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ff first
#define ss second
#define ll int64_t
#define all(sss) (sss).begin(),(sss).end()
#define pb push_back
#define pob pop_back
#define endl "\n"
#define input(ass) for(auto &x:(ass)) cin>>x;
#define iendl "\n", cout<<flush

//random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a,ll b){if(a > b){return -1;}return a + (ll)rng() % (b - a + 1);}

const int mod = 1000000007;
// const int mod = 998244353;
typedef unsigned long long ull;
typedef long double lld;

#ifdef LOCAL
#include "../.vim/dbg.h"
#else
#define dbg(...) "11-111"
#endif

// help
ll LCM(ll aaa, ll bbb) {return (aaa / __gcd(aaa, bbb)) * bbb;}
ll power(ll aaa, ll bbb) {ll ans = 1; while (bbb) {if (bbb & 1) ans = (ans * aaa)%mod; bbb >>= 1; aaa = (aaa * aaa)%mod;} return ans;}
ll mod_inv(ll a) {return power(a, mod - 2);}

/*----------------------------------x x x---------------------------------*/
void solve(char *argv[]);
int32_t main(int argc, char *argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll TT = 1;
    for (ll TEST = 1; TEST <= TT; TEST++)
        solve(argv);

}
ll N = 1e17;
void solve(char *argv[]) {
    srand(atoi(argv[1]));
    int n = rnd(1, 100);
    cout << n << endl;
    for(int i = 1; i <= n; i++) {
        cout << rnd(1, n) << " \n"[i == n - 1];
    }
}
