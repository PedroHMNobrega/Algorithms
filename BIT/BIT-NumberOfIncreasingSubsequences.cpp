#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define loopBack(i, a, b) for(int i = a; i >= b; i--)
#define INF INT_MAX
#define LINF LLONG_MAX
#define DINF DBL_MAX
#define MAX 100050
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

int n, sz;
ll bit[MAX][11];

ll sum(int k, int j) {
    ll s = 0;
    while(k > 0) {
        s += bit[k][j];
        k -= k & -k;
    }
    return s;
}

void add(int k, int j, ll x) {
    while(k <= n) {
        bit[k][j] += x;
        k += k & -k;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int aux;
    ll ans = 0, x;
    memset(bit, 0, sizeof(bit));

    cin >> n >> sz;
    loop(i, 0, n) {
        cin >> x;
        add(x, 1, 1);
        loop(j, 2, sz+2) add(x, j, sum(x-1, j-1));
    }
    
    ans = sum(n, sz+1);
    cout << ans << "\n";
}