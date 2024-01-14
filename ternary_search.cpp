/** double **/
double ternary_search(double l, double r) {
    double eps = 1e-9; //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1); //evaluates the function at m1
        double f2 = f(m2); //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l); //return the maximum of f(x) in [l, r]
}


/** integer (code below find the minimum) **/
int ternary_search(int l, int r) {
    int res = 0;
    while (r - l > 3) {
        int mid1 = (2 * l + r) / 3;
        int mid2 = (2 * r + l) / 3;
        int val1 = f(mid1), val2 = f(mid2);
        if (val1 <= val2) r = mid2;
        else l = mid1;
        res = min(res, min(val1, val2));
    }

    for (int i = l; i <= r; ++i) res = min(res, f(i));
    return res;
}
