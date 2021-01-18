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
#define MAX 400400
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct Node {
    ll sum = 0;
    ll lazy = 0;
};
Node tree[4*MAX];

void lazy(int k, int x, int y) {
    if(tree[k].lazy != 0) {
        int esq = k*2, dir = k*2+1;
        tree[k].sum += tree[k].lazy * (y - x + 1);
        if(x != y) {
            tree[esq].lazy += tree[k].lazy;
            tree[dir].lazy += tree[k].lazy;
        }
        tree[k].lazy = 0;
    }
}

void update(int ql, int qr, int k, int x, int y, ll add) {
    lazy(k, x, y);
    
    int mid = (x + y) / 2, esq = k*2, dir = k*2+1;
    if(x > qr or y < ql) return;
    else if(x >= ql and y <= qr) {
        tree[k].sum += (y - x + 1) * add;
        if(x != y) {
            tree[esq].lazy += add;
            tree[dir].lazy += add;
        }
        return;
    }
    else {
        update(ql, qr, esq, x, mid, add);
        update(ql, qr, dir, mid+1, y, add);
        tree[k].sum = tree[esq].sum + tree[dir].sum;
    }
}

ll query(int ql, int qr, int k, int x, int y) {
    lazy(k, x, y);

    int mid = (x + y) / 2, esq = k*2, dir = k*2+1;
    if(x > qr or y < ql) return 0;
    else if(x >= ql and y <= qr) return tree[k].sum;
    else return query(ql, qr, esq, x, mid) + query(ql, qr, dir, mid+1, y);
}

void build(int array[], int x, int y, int k) {
    if(x > y) return;
    if(x == y) {
        tree[k].sum = array[x];
        return;
    }
    int mid = (x + y) / 2, esq = k*2, dir = k*2+1;
    build(array, x, mid, esq);
    build(array, mid+1, y, dir);
    tree[k].sum = tree[esq].sum + tree[dir].sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n, c, type, p, q, v;
        cin >> n >> c;

        while(c--) {
            cin >> type >> p >> q;
            p--; q--;
            if(p > q) swap(p, q);
            if(type == 0) {
                cin >> v;
                update(p, q, 1, 0, n-1, v);
            } else 
                cout << query(p, q, 1, 0, n-1) << "\n";
            
        }
        memset(tree, 0, sizeof(tree));
    }
}