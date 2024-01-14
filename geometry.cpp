typedef complex<long long> Point;
#define X real()
#define Y imag()

/** angle **/
arg(p); // 0.463648 angle of vector p according to x coordinates
polar(s, a);
// construct a vector whose length is s and points to an angle a
// A vector can be rotated by an angle a by multiplying it with length 1 and angle a

/** cross product **/
Point a = {4, 2};
Point b = {1, 2};
Point c = (conj(a) * b).Y; // 6 - cross product of a and b (x1 * y2 - x2 * y1)
// conj negates the y coordinate of a vector

// (p - s1) * (p - s2) tell us the location of point p and (s1, s2) are 2 points on a line
// this cross product tells us whether p is left or right the line (negative -> right, positive -> left, 0 -> on line)
