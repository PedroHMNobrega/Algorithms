#include<bits/stdc++.h>
#define INF 1000000005;
using namespace std;

const int n = 8;
vector<int> tree (2*n, 0);
vector<int> treeMin(2*n, 0);

int sum(int a, int b) {
    a += n; b += n;
    int s = 0;
    while(a <= b) {
        if(a % 2 == 1) s += tree[a++];
        if(b % 2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int mini(int a, int b) {
    a += n; b += n;
    int m = INF;
    while(a <= b) {
        if(a % 2 == 1) m = min(m, treeMin[a++]);
        if(b % 2 == 0) m = min(m, treeMin[b--]);
        a /= 2; b /= 2;
    }
    return m;
}

void addSum(int k, int x) {
    k += n;
    tree[k] += x;
    for(k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k] + tree[2*k+1];
    }
}

void addMin(int k, int x) {
    k += n;
    treeMin[k] = x;
    for(k /= 2; k >= 1; k /= 2) {
        treeMin[k] = min(treeMin[2*k], treeMin[2*k+1]);
    }
}

int main() {
    //n = pow(2, ceil(log2(n)));
    int arr[n] = {5, 8, 6, 3, 2, 7, 2, 6};
    
    //Sum 
    for(int i = 0; i < n; i++) {
        addSum(i, arr[i]);
    }
    for(int i = 0; i < 2*n; i++) {
        cout << tree[i] << " ";
    } cout << "\n";
    cout << sum(6, 7) << "\n";

    //Min
    int arr2[n] = {5, 8, 6, 3, 1, 7, 2, 6};
    for(int i = 0; i < n; i++) {
        addMin(i, arr2[i]);
    }
    for(int i = 0; i < 2*n; i++) {
        cout << treeMin[i] << " ";
    } cout << "\n";
    cout << mini(2, 7) << "\n";
}