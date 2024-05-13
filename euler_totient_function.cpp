/** Also known as phi-function: phi(n)
- Count numbers of integers from 1 to n, which is co-prime to n (greatest common divisor = 1)
- Some properties:
    + If p is prime, gcd(p, q) = 1 with 1 <= q < p
      -> phi(p) = p - 1
    + If p is prime & k >= 1, there are exactly p^(k - 1) numbers in range [1, p^k] are divisible by p
      -> phi(p^k) = p^k - p^(k - 1)
    + If a & b is two co-prime integers
      -> phi(ab) = phi(a) * phi(b)
    + General a, b
      -> phi(ab) = phi(a) * phi(b) * d / phi(d)
         d = gcd(a, b)
    + Using first 3 properties -> compute phi(n) through factorization
      phi(n) = phi(p1^a1) * phi(p2^a2) * ... * phi(pk^ak)
             = (p1^a1 - p1^(a1-1)) * (p2^a2 - p2^(a2-1)) * ... * (pk^ak - pk^(ak - 1))
             = p1^a1 * (1 - 1/p1) * p2^a2 * (1 - 1/p2) * ... * pk^ak * (1 - 1/pk)
             = n * (1 - 1 / p1) * (1 - 1 / p2) * ... * (1 - 1 / pk)
    + Compute phi(k) for k from 1 to n
      Code based on sieve of eratothenes
      If x is prime -> apply same formula for all numbers that are divisible by x
**/

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        while (n % i == 0) n /= i;
        result -= result / i;
    }
    if (n > 1) result -= result / n;
    return result;
}

void phi_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; ++i) phi[i] = i;

    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] = phi[j] - phi[j] / i;
        }
    }
}


