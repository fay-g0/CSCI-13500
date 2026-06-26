#include <iostream>
#include <vector>

// Prints a matrix in [a|b|c] format, one row per line.
void PrintMatrix(const std::vector<std::vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j];
            if (j != matrix[i].size() - 1) {
                std::cout << "|";
            }
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

int main() {

    // Create a 3x3 and a 6x6 zero-initialized matrix.
    int size_small = 3;
    int size_large = 6;

    std::vector<std::vector<int>> matrix3(size_small, std::vector<int>(size_small, 0));
    std::vector<std::vector<int>> matrix6(size_large, std::vector<int>(size_large, 0));

    // 1s above the diagonal, 0s on/below it
    std::cout << " 3x3 Array" << std::endl;
    for (int i = 0; i < size_small; i++) {
        for (int j = 0; j < size_small; j++) {
            if (j < size_small - i) {
                matrix3[i][j] = 1;
            } else {
                matrix3[i][j] = 0;
            }labs
        }
    }
    PrintMatrix(matrix3);

    std::cout << " 6x6 Array " << std::endl;
    for (int i = 0; i < size_large; i++) {
        for (int j = 0; j < size_large; j++) {
            if (j < size_large - i) {
                matrix6[i][j] = 1;
            } else {
                matrix6[i][j] = 0;
            }
        }
    }
    PrintMatrix(matrix6);

    // X shape (main diagonal + anti-diagonal)

    std::vector<std::vector<int>> matrix3_x(size_small, std::vector<int>(size_small, 0));
    std::vector<std::vector<int>> matrix6_x(size_large, std::vector<int>(size_large, 0));

    std::cout << " 3x3 Array " << std::endl;
    for (int i = 0; i < size_small; i++) {
        for (int j = 0; j < size_small; j++) {
            if (i == j || (i + j == size_small - 1)) {
                matrix3_x[i][j] = 1;
            }
        }
    }
    PrintMatrix(matrix3_x);

    std::cout << " 6x6 Array " << std::endl;
    for (int i = 0; i < size_large; i++) {
        for (int j = 0; j < size_large; j++) {
            if (i == j || (i + j == size_large - 1)) {
                matrix6_x[i][j] = 1;
            }
        }
    }
    PrintMatrix(matrix6_x);


    // Row sums and column sums
    std::vector<std::vector<int>> matrix_t3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = static_cast<int>(matrix_t3.size());

    std::vector<std::vector<int>> sums(2, std::vector<int>(n, 0));

    // Row sums
    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += matrix_t3[i][j];
        }
        sums[0][i] = row_sum;
    }

    // Column sums
    for (int j = 0; j < n; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++) {
            col_sum += matrix_t3[i][j];
        }
        sums[1][j] = col_sum;
    }

    std::cout << " Original Matrix " << std::endl;
    PrintMatrix(matrix_t3);

    std::cout << " Row sums (top) / column sums (bottom) " << std::endl;
    PrintMatrix(sums);

    // Task 4: diagonal X-sum, center counted once
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        d1 += matrix_t3[i][i];           // main diagonal
        d2 += matrix_t3[i][n - 1 - i];   // anti-diagonal
    }

    /*
    Center cell only exists for odd-sized matrices; subtract it once
     since it's added by both diagonal sums above.
    */
    int c = 0;
    if (n % 2 == 1) {
        int mid = n / 2;
        c = matrix_t3[mid][mid];
    }

    int S = d1 + d2 - c;

    std::cout << " X-sum " << std::endl;
    std::cout << "d1 = " << d1 << std::endl;
    std::cout << "d2 = " << d2 << std::endl;
    std::cout << "c  = " << c << std::endl;
    std::cout << "S  = " << S << std::endl;

    return 0;
}