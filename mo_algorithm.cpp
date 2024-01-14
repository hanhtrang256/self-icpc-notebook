int BLOCK = (int)sqrt(n);

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
    if (x.first / BLOCK != y.first / BLOCK) return x.first < y.first;
    return x.second < y.second;
}

sort(lines + 1, lines + 1 + n);

// solve for query 1

int l = query[1].first, r = query[1].second;

for (int i = 2; i <= q; ++i) {
    int u = query[i].first, v = query[i].second;

    while (l < u) {
        --cnt[a[l]];
        ++l;
    }

    while (l > u) {
        --l;
        ++cnt[a[l]];
    }

    while (r < v) {
        ++r;
        ++cnt[a[r]];
    }

    while (r > v) {
        --cnt[a[r]];
        --r;
    }
}
