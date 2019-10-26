template<int sz> struct Matrix {
    ll mat[sz + 1][sz + 1];

    Matrix() {
        fill(mat[0], mat[sz] + sz + 1, 0);
    }
    
    Matrix operator + (Matrix m) {
        Matrix c = Matrix();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                c[i][j] = (mat[i][j] + m.mat[i][j]) % MOD;
            }
        }
        return c;
    }
    
    Matrix operator - (Matrix m) {
        Matrix c = Matrix();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                c[i][j] = ((mat[i][j] - m.mat[i][j]) % MOD + MOD) % MOD;
            }
        }
        return c;
    }

    Matrix operator * (Matrix m) {
        Matrix c = Matrix();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    c.mat[i][k] = (c.mat[i][k] + (mat[i][j] * m.mat[j][k]) % MOD) % MOD;
                }
            }
        }
        return c;
    }

    Matrix operator ^ (ll n) {
        if (n == 1) {
            return *this;
        } else if (n == 2) {
            return (*this) * (*this);
        }
        Matrix p = (*this) ^ (n / 2);
        p = p * p;
        if (n & 1) {
            p = p * (*this);
        }
        return p;
    }

    void print() {
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};
