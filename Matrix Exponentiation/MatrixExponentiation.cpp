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
#define MAX 51
#define MOD 1000
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

ll matAux[MAX][MAX];

ll sum(ll a, ll b) {
    return (a + b) % MOD;
}

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

void multMat(ll mat1[][MAX], ll mat2[][MAX], int n) {
    memset(matAux, 0, sizeof(matAux));
    
    loop(i, 0, n)
        loop(j, 0, n)
            loop(k, 0, n)
                matAux[i][j] = sum(matAux[i][j], mult(mat1[i][k], mat2[k][j]));
    
    loop(i, 0, n)
        loop(j, 0, n)
            mat1[i][j] = matAux[i][j];
}

void matExp(ll mat[][MAX], ll e, int n) {
    ll matExpAux[MAX][MAX];
    
    loop(i, 0, n) {
        loop(j, 0, n) {
            matExpAux[i][j] = mat[i][j];
            mat[i][j] = i == j ? 1 : 0;
        }
    }
    
    while(e) {
        if(e & 1) multMat(mat, matExpAux, n);
        multMat(matExpAux, matExpAux, n);
        e >>= 1;
    }
}

ll mat[MAX][MAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        memset(mat, 0, sizeof(mat));
        int n, r, aux, num;
        cin >> n >> r;
        vector<int> arrIni(n);
        loop(i, 0, n) cin >> arrIni[i];
        loop(i, 0, n) {
            cin >> aux;
            loop(j, 0, aux) {
                cin >> num;
                mat[i][num] = 1;
            }
        }

        matExp(mat, r, n);

        int ans;
        loop(i, 0, n) {
            ans = 0;
            loop(j, 0, n) ans = sum(ans, mult(mat[i][j], arrIni[j]));
            if(i != 0) cout << " ";
            cout << ans;
            ans = 0;
        } 
        cout << '\n';
    }
}