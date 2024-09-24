#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MXN = 1e5 + 5, BLOCK_SIZE = 316;

struct Query {
    int l, r, idx;

    bool operator<(const Query &y) const {
        // Current query x is being compared with other query y
        int x_block = l / BLOCK_SIZE;
        int y_block = y.l / BLOCK_SIZE;

        // If x and y both lie in the same block, sort in non decreasing order of endpoint
        if (x_block == y_block)
            return r < y.r;

        // x and y lie in different blocks
        return x_block < y_block;
    }
};

int A[MXN], final_ans[MXN], freq[MXN];
int cur_ans;

void operate(int idx, int delta) {
    int x = A[idx];
    if (x >= MXN) return;

    if (freq[x] == x) cur_ans--;
    freq[x] += delta;
    if (freq[x] == x) cur_ans++;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<Query> queries(M);
    for (int i = 0; i < M; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--; // 0 based indexing

        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    int i = 0, j = -1;
    for (const auto &[l, r, idx] : queries) {
        while (j < r) operate(++j, 1);
        while (i > l) operate(--i, 1);

        while (i < l) operate(i++, -1);
        while (j > r) operate(j--, -1);

        final_ans[idx] = cur_ans;
    }

    for (int i = 0; i < M; i++)
        cout << final_ans[i] << "\n";
}