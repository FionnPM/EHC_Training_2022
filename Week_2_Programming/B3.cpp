#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)

int a[10001], it[40004], t[10001];

void create_tree(int k, int l, int r) {
    if(l == r) {
        it[k] = a[l];
        t[l] = k;
        return;
    }
    int mid = (l + r) / 2;

    create_tree(k * 2, l, mid);
    create_tree(k * 2 + 1, mid + 1, r);

    it[k] = min(it[k * 2], it[k * 2 + 1]);
}

int find(int k, int l, int r, int u, int v) {
    if(l > v || r < u) return INT_MAX;
    if(u <= l && r <= v) return it[k];
    int mid = (l + r) / 2;
    return min(find(2 * k, l, mid, u, v), find(2 * k + 1, mid + 1, r, u, v));
}

void update(int index, int value) {
    int k = t[index];
    it[k] = value;
    while(k > 0) {
        if(k % 2 == 0) it[k / 2] = min(it[k], it[k + 1]);
        else it[k / 2] = min(it[k], it[k - 1]);
        //it[k/2] = min(it[k], it[k+1]);
        k /= 2;
    }
}

int main() {
    int n, q, x, l, r;
    memset(it, INT_MAX, sizeof(it));
    cin >> n >> q;
    forinc(i, 1, n) cin >> a[i];
    create_tree(1, 1, n);
    forinc(i, 1, q) {
        cin >> x >> l >> r;
        if(x == 1) cout << find(1, 1, n, l, r) << endl;
        else {
            a[l] = r;
            update(l, r);
        }
    }
}
