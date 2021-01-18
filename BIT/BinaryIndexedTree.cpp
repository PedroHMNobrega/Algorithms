#include <bits/stdc++.h>

using namespace std;

int n = 8;
vector<int> bit(n + 1, 0); 

int sum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[k];
        k -= k&-k;
    }
    return s;
}

void add(int k, int x) {
    while(k <= n) {
        bit[k] += x;
        k += k&-k;
    }
}

int main() {
    int array[] = {1, 3, 4, 8, 6, 1, 4, 2};

    for(int i = 0; i < n; i++) {
        add(i+1, array[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << bit[i] << " ";
    } cout << "\n";

    int q = 5;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << sum(y) - sum(x - 1) << "\n";
        add(4, 80);
    }
}
