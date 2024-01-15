/**
binary search only 1 time, since answer for each query will lie in some exact ranges
O(nlogn) -> may be useful for problems more than nlogn
**/

void dequy(int l, int r, vector < int > poss) {
    if (poss.empty()) return;
    if (l == r) {
        // answer
        return;
    }
    int mid = (l + r) >> 1;
    vector<int> lef, rig;
    // assume the binary search is increasing
    // -> those who succeed with mid will go to vector left
    // -> those not will go to vector right
    dequy(l, mid, lef); dequy(mid + 1, rig);
}
