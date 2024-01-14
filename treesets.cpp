#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class X> using Tree = tree<X, null_type, less<X>, rb_tree_tag, tree_order_statistics_node_update>;

Tree<int> tr;

// find_by_order(k) -> k-th largest element (counting from 0)
// order_of_key(X)  -> number of elements < X
tr.insert(1); tr.insert(2); tr.insert(4); tr.insert(8); tr.insert(16);

*tr.find_by_order(1) // 2
*tr.find_by_order(2) // 4
*tr.find_by_order(4) // 16
end(X)==X.find_by_order(6)// true

X.order_of_key(-5)  // 0
X.order_of_key(1)   // 0
X.order_of_key(3)   // 2
X.order_of_key(4)   // 2
X.order_of_key(400) // 5
