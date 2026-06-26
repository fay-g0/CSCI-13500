#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total){
    for(int i = 0; i < matrix_local_rows_total; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix_local[i][j];
        }
        std::cout << std::endl;
    }
    // Function_Start message to terminal

    // Body of the function. Do your magic!

    // Function_End message to terminal
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total)
    {
        std::cout << " Matrix Addition Start " << std::endl;

        if (matrix_one_rows_total != matrix_two_rows_total) {
            std::cout << "Error: matrices must have the same dimensions to add." << std::endl;
            std::cout << " End to addition " << std::endl;
            return;
        }

    int result[3][3];

    for (int i = 0; i < matrix_one_rows_total; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix_one[i][j] + matrix_two[i][j];
        }
    }

    Print2DArray(result, matrix_one_rows_total);

    std::cout << " Matrix Addition End " << std::endl;

}

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total){
    std::cout << " Transpose Matrix Start " << std::endl;

    int result[3][3];

    for (int i = 0; i < matrix_local_rows_total; i++) {
            for (int j = 0; j < 3; j++) {
                result[j][i] = matrix_local[i][j];
            }
        }
    Print2DArray(result, 3);

    std::cout << " Transpose Matrix End " << std::endl;

    // Function_Start message to terminal

    // body of the function

    // display resulting matrix
    // if the dimension of the resulting matrix doesn't match the print function, you could do it manually here
    // or modify the parameter of the print function so it doesn't cause errors

    // Function_End message to terminal 
}

void Determinant(const int matrix_local[][3], const int size){
    std::cout << " Determinant Start " << std::endl;

    if (size != 3) {
        std::cout << "Error: determinant only supported for 3x3 matrices here." << std::endl;
        std::cout << " Determinant End " << std::endl;
        return;
    }

    int a = matrix_local[0][0], b = matrix_local[0][1], c = matrix_local[0][2];
    int d = matrix_local[1][0], e = matrix_local[1][1], f = matrix_local[1][2];
    int g = matrix_local[2][0], h = matrix_local[2][1], i = matrix_local[2][2];

    int det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);

    std::cout << "Determinant = " << det << std::endl;

    std::cout << " Determinant End " << std::endl;
    // Function_Start message to terminal

    // check for valid dimensions

    // body of the function 

    // print the determinant value on the terminal

    // Function_End message to terminal
}

void SearchValue(const int matrix_local[][3], const int rows, const int target){
    std::cout << " SearchValue Start " << std::endl;

    bool found = false;
    int found_row = -1, found_col = -1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix_local[i][j] == target) {
                found = true;
                found_row = i;
                found_col = j;
            }
        }
    }

    if (found) {
        std::cout << target << " found at position [" << found_row << "][" << found_col << "]" << std::endl;
    } else {
        std::cout << target << " not found in matrix." << std::endl;
    }

    std::cout << " SearchValue End " << std::endl;
    // Function_Start message to terminal 

    // body of the function
        // found  or not

    // Function_End message to terminal
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3], 
                    const int rows_a, const int cols_a, 
                    const int rows_b, const int cols_b){
    std::cout << "--- MatrixMultiplication Start ---" << std::endl;

    if (cols_a != rows_b) {
        std::cout << "Error: cannot multiply, cols_a must equal rows_b." << std::endl;
        std::cout << "--- MatrixMultiplication End ---" << std::endl;
        return;
    }

    int result[3][3];

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            int sum = 0;
            for (int k = 0; k < cols_a; k++) {
                sum += matrix_a[i][k] * matrix_b[k][j];
            }
            result[i][j] = sum;
        }
    }

    Print2DArray(result, rows_a);

    std::cout << "--- MatrixMultiplication End ---" << std::endl;

    // Function_Start message to terminal
    
    // check for valid arrays

    // Body of the function

    // Print resulting matrix

    // Function_End message to terminal
}

int main(){
    // Use these two matrices for basic testing.

    int testing_matrix_one[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int testing_matrix_two[3][3] = {
        {12,65,82},
        {83,2,8},
        {10,96,67}
    };


// Not used in this class, but it is nice to know other ways to find the size of primitive array.
// This method below is similar to how you will find the size of vectors (future material)
    // DO NOT USE IN THIS PROJECT FUNCTION, but you could test it yourselves.
    // int size_row_one = std::size(testing_matrix_one);
    // int size_col_one = std::size(testing_matrix_one[0]);


    // This is a way to find the dimensions of an array without hardcoding values.
    // It dynamically reflects the array's actual declared size, so if you change
    // the array dimensions, the calculation updates automatically.
    //
    // How it works:
    //
    // To find the number of ROWS:
    //   sizeof(testing_matrix_one)      = total bytes of the whole array = 3*9*4 = 108 bytes
    //   sizeof(testing_matrix_one[0])   = total bytes of one row         = 1*9*4 =  36 bytes
    //   108 / 36 = 3 rows
    
    int size_row_one = sizeof(testing_matrix_one)/sizeof(testing_matrix_one[0]);

    // To find the number of COLUMNS:
    //   sizeof(testing_matrix_one[0])      = total bytes of one row          = 1*9*4 = 36 bytes
    //   sizeof(testing_matrix_one[0][0])   = total bytes of one element(int) = 1*4   =  4 bytes
    //   36 / 4 = 9 cols
    
    int size_col_one = sizeof(testing_matrix_one[0])/sizeof(testing_matrix_one[0][0]);

    std::cout << "row: " << size_row_one<< " col: " << size_col_one<< std::endl << std::endl;

    Print2DArray(testing_matrix_one, size_row_one);

//Testing each function's output
    int size_row_two = sizeof(testing_matrix_two)/sizeof(testing_matrix_two[0]);
    int size_col_two = sizeof(testing_matrix_two[0])/sizeof(testing_matrix_two[0][0]);

    MatrixAddition(testing_matrix_one, size_row_one, testing_matrix_two, size_row_two);
    TransposeMatrix(testing_matrix_one, size_row_one);
    Determinant(testing_matrix_one, size_row_one);
    SearchValue(testing_matrix_one, size_row_one, 5);
    MatrixMultiplication(testing_matrix_one, testing_matrix_two, size_row_one, size_col_one, size_row_two, size_col_two);

    return 0; 
}