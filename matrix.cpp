struct Matrix {
	int m, n; // m rows, n columns
	int d[2][2];

	Matrix(int _m = 0, int _n = 0) {
		m = _m; n = _n;
		memset(d, 0, sizeof d);
	}

	Matrix operator + (const Matrix &a) const {
		Matrix res(m, n);
		for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
			res.d[i][j] = d[i][j] + a.d[i][j];
		return res;
	}

	Matrix operator * (const Matrix &a) const {
		int p = a.n;
		Matrix res(m, p);
		for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		for (int k = 0; k < p; k++) res.d[i][k] += d[i][j] * a.d[j][k];
		return res;
	}

	Matrix operator ^ (long long k) const {
		Matrix res(n, n);
		Matrix mul = *this;
		for (int i = 0; i < n; i++) res.d[i][i] = 1;

		while (k > 0) {
			if (k & 1) res = res * mul;
			mul = mul * mul;
			k >>= 1;
		}

		return res;
	}
};
