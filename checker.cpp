#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define ll long long
#define all(sss) (sss).begin(),(sss).end()
#define pb push_back
#define pob pop_back
#define endl "\n"
#define input(ass) for(auto &x:(ass)) cin>>x;
#define iendl "\n", cout<<flush

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
ll power(ll aaa, ll bbb, int md = mod) {ll ans = 1; while (bbb) {if (bbb & 1) ans = (ans * aaa) % md; bbb >>= 1; aaa = (aaa * aaa) % md;} return ans;}
ll mod_inv(ll a, int md = mod) {return power(a, md - 2, md);}

/*--------------------------------- 8===> ---------------------------------*/
void solve();
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int TT = 1;
    //cin >> TT;
    for (int TEST = 1; TEST <= TT; TEST++)
        solve();

}
struct node {
    int val;
    node(int val_ = 0) : val(val_) {}
    friend node merge(const node &a, const node &b, bool op) {
        node tmp;

        if (op) tmp.val = min(a.val, b.val);
        else tmp.val = max(a.val, b.val);
        return tmp;
    }
};

class STREE {
private:
    node _default;
    int n;
    bool op;
    vector<node> tree;

    void build(const vector<int> &v, int cur, int l, int r) {
        if(l == r) {
            tree[cur].val = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(v, 2 * cur, l, mid);
        build(v, 2 * cur + 1, mid + 1, r);
        tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1], op);
    }

public:
    STREE(const vector<int> &v, int _op) : op(_op) {
        n = int(v.size());
        _default = (op ? INT_MAX : 0);
        tree.resize(4 * n);
        build(v, 1, 0, n - 1);
     }

    void update(int i, int val, int cur = 1, int l = 0, int r = -1) {
          if(r < 0) r += n;
          if (r == l && i == l) {
               tree[cur].val = val;
               return;
          }
          int mid = (l + r) / 2;
          if (i <= mid) update(i, val, 2 * cur, l, mid);
          else update(i, val, 2 * cur + 1, mid + 1, r);
          tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1], op);
     }

    node query(int i1, int i2, int cur = 1, int l = 0, int r = -1) {
          if(r < 0) r += n;
          if (l >= i1 && r <= i2) return tree[cur];
          else if (l > i2 || r < i1) return _default;

          int mid = (l + r) / 2;
          node val1 = query(i1, i2, 2 * cur, l, mid);
          node val2 = query(i1, i2, 2 * cur + 1,  mid + 1, r);
          return merge(val2, val1, op);
     }
};

void solve() {
    int n; cin >> n;
    vector<int> v(n); input(v);

    STREE Tmx(v, 0);
    STREE Tmn(v, 1);

    long long ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= n - i; j++) {
        ans += Tmx.query(j, j + i - 1).val * 1LL * Tmn.query(j, j + i - 1).val;
        ans %= mod;
    }

    cout << ans << endl;
}
