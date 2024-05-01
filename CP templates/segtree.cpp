#define MAX 200005

//********* build(a, 1, 0, n-1) ********************
//********* sum(1, 0, n-1, l, r) ********************
//********* update(1, 0, n-1, pos, val) ********************
//********* minimum finding e l>r e INT_MAX *********************

int ta[4*MAX];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        ta[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        ta[v] = ta[v*2] + ta[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return ta[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        ta[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        ta[v] = ta[v*2] + ta[v*2+1];
    }
}