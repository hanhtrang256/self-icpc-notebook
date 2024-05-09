/** The difference of this technique compared to normal D&Q is that
    [l, m) will influence [m, r) **/

/** Convert from 3D problem to 2D problem (sort 1 axis) and use 1D BIT **/
/** Suppose processing range [l, r)
    Divide it into 2 subproblems [l, m) & [m, r)
    Solve 2 subproblems first recursively
    While solving we also sort another axis in the processing range
    Add the influenced amount of each element in [l, m) to each element in [m, r)
    Then merge sort according to other axis
    Released memory that has been used **/

/** Ex: For each Point (xi, yi, zi) find number of Point (xj, yj, zj) that has
    xi < xj, yi < yj, zi < zj

    Solve: Sort x axis descending
    In [l, m) & [m, r), we will always have ( min xi in [l, m) ) > ( max xi in [m, r) ) (since we sort)
    We'll solve subproblems [l, m) & [m, r) recursively first then merge sort them according to y axis,
    so that the bigger query is still proper and will be handled easier
**/

void cdq(int l, int r) {
    if (l + 1 == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid); cdq(mid, r);
    int i = l, j = mid; // iterator of left and right subproblem

    vector<int> record; // save updated-nodes to reset it later (reduce complexity)
    vector<point> tmp; // sort the current range according to y axis for bigger query

    // Remember the left array and right array has been sorted descending according to y axis
    // The ( min xi in [l, m) ) > ( max xi in [m, r) ) still remain

    int tot = 0;
    // save the total number of left elements that has y axis larger than the current right one
    while (i < mid && j < r) {
        if (P[i].y > P[j].y) {
            bit.upd(P[i].z, 1);
            ++tot;
            record.pb(P[i].z);
            tmp.pb(P[i++]);
        }
        else {
            res[P[j].index] += sum - bit.get(P[j].z); // count number of left elements with z > P[j].z
            tmp.pb(P[j++]);
        }
    }

    while (i < mid) tmp.pb(P[i++]);
    while (j < r) {
        res[P[j].index] += sum - bit.get(P[j].z);
        tmp.pb(P[j++]);
    }

    for (int t = l; t < r; ++i) P[t] = tmp[t - l]; // merge sort the current range according to y axis
    // reset BIT
    for (int t = 0; t < (int)record.size(); ++t) bit.upd(record[t], -1);
    // release memory
    vector<int>().swap(record);
    vector<point>().swap(tmp);
}
