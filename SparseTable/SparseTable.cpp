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

int st[MAX][27];

int query(int i, int j) {
    int logi = log2(j - i + 1);
    return min(st[i][logi], st[j - (1 << logi) + 1][logi]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, q, i, j;
    
    cin >> n;
    loop(i, 0, n) cin >> st[i][0];
    loop(j, 1, 28) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i+(1 << (j-1))][j-1]);
        }
    }
    cin >> q;
    while(q--) {
        cin >> i >> j;
        cout << query(i, j) << "\n";
    }
}