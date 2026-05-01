#ifndef PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_STATIC_MATRIX_H
#define PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_STATIC_MATRIX_H
#include <stdexcept>

template<typename T,int row,int col>
class StaticMatrix {
    T array[row][col]{};
public:
    StaticMatrix() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                array[i][j] = T{};
            }
        }
    }

    static int Col() {
        return col;
    }

    static int Row() {
        return row;
    }
    T& at(int A, int B) {
        return array[A][B];
    }
    const T& at(int A, int B) const{
        return array[A][B];
    }

    friend StaticMatrix operator+(StaticMatrix& A,StaticMatrix& B) {
        StaticMatrix C;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                C.at(i,j) = A.at(i,j) + B.at(i,j);
            }
        }
        return C;
    }

    template <int P>
    friend StaticMatrix<T, row, P> operator*(const StaticMatrix<T, row, col>& A,const StaticMatrix<T, col, P>& B) {
        StaticMatrix<T, row, P> C;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < P; ++j) {
                C.at(i,j) = T{};
                for (int k = 0; k < col; ++k) {
                    C.at(i,j) += A.at(i,k) * B.at(k,j);
                }
            }
        }
        return C;
    }
    T determinant() {
        if (row != col){throw std::invalid_argument("La matriz no es cuadrada");}
        if (row == 1) return array[0][0];
        if (row == 2) return array[0][0]*array[1][1] - array[0][1]*array[1][0];
        T det = T{};
        for (int j = 0; j < col; ++j) {
            StaticMatrix<T, row-1, col-1> M;
            for (int r = 1; r < row; ++r) {
                int cc = 0;
                for (int c = 0; c < col; ++c) {
                    if (c == j) continue;
                    M.at(r-1, cc++) = array[r][c];
                }
            }
            T sign = (j % 2 == 0) ? T{1} : T{-1};
            det += sign * array[0][j] * M.determinant();
        }
        return det;
    }
};


#endif //PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_STATIC_MATRIX_H