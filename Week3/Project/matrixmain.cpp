#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total){

    // Function_Start message to terminal

    std::cout << "[Print2DArray] Function called." << std::endl;

    // Body of the function. Do your magic!

    for (int row = 0; row < matrix_local_rows_total; row++){
        std::cout << "[ ";
        for (int col = 0; col < 3; col++){
            std::cout << matrix_local[row][col];
            if (col < 2){
                std::cout << " | ";
            }
        }
        std::cout << " ]" << std::endl;
    }

    // Function_End message to terminal
    std::cout << "[Print2DArray] Function finished." << std::endl;
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total)
    {
    // Function_Start message to terminal
    std::cout << "[MatrixAddition] Function called." << std::endl;

    // Body of the function.

    int result[3][3] = {};

    for (int row = 0; row < matrix_one_rows_total; row++){
        for (int col = 0; col < 3; col++){
            result[row][col] = matrix_one[row][col] + matrix_two[row][col];
        }
    }

    std::cout << "[MatrixAddition] Resulting matrix:" << std::endl;
    Print2DArray(result, matrix_one_rows_total);

    // Function_End message to terminal
    std::cout << "[MatrixAddition] Function finished." << std::endl;
    }

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total){
    // Function_Start message to terminal
    std::cout << "[TransposeMatrix] Function called." << std::endl;

    // body of the function

    int result[3][3] = {};

    for (int row = 0; row < matrix_local_rows_total; row++){
        for (int col = 0; col < 3; col++){
            result[col][row] = matrix_local[row][col];
        }
    }

    // display resulting matrix
    // if the dimension of the resulting matrix doesn't match the print function, you could do it manually here
    // or modify the parameter of the print function so it doesn't cause errors
    std::cout << "[TransposeMatrix] Resulting transposed matrix:" << std::endl;
    Print2DArray(result, 3);

    // Function_End message to terminal 
    std::cout << "[TransposeMatrix] Function finished." << std::endl;
}

void Determinant(const int matrix_local[][3], const int size){
    // Function_Start message to terminal
    std::cout << "[Determinant] Function called." << std::endl;

    // check for valid dimensions
    if (size != 2 && size != 3){
        std::cout << "[Determinant] Invalid matrix dimension. "
                   << "Only 2x2 or 3x3 matrices are supported." << std::endl;
        std::cout << "[Determinant] Function finished." << std::endl;
        return;
    }

    // body of the function 

    int det = 0;

    if (size == 2){
        det = (matrix_local[0][0] * matrix_local[1][1]) -
              (matrix_local[0][1] * matrix_local[1][0]);
    } else {
        // size == 3, expansion by the first row (cofactor expansion).
        det = matrix_local[0][0] * (matrix_local[1][1] * matrix_local[2][2] -
                                     matrix_local[1][2] * matrix_local[2][1]) -
              matrix_local[0][1] * (matrix_local[1][0] * matrix_local[2][2] -
                                     matrix_local[1][2] * matrix_local[2][0]) +
              matrix_local[0][2] * (matrix_local[1][0] * matrix_local[2][1] -
                                     matrix_local[1][1] * matrix_local[2][0]);
    }

    // print the determinant value on the terminal
    std::cout << "[Determinant] The determinant is: " << det << std::endl;

    // Function_End message to terminal
    std::cout << "[Determinant] Function finished." << std::endl;
}

void SearchValue(const int matrix_local[][3], const int rows, const int target){
    // Function_Start message to terminal 
    std::cout << "[SearchValue] Function called." << std::endl;

    // body of the function

    bool found = false;

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < 3; col++){
            // found  or not
            if (matrix_local[row][col] == target){
                std::cout << "Found " << target << " at [" << row << "]" << "[" << col << "]" << std::endl;
                found = true;
            }
        }
    }

    if (!found){
        std::cout << target << " was not found in the matrix" << std::endl;
    }

    // Function_End message to terminal
    std::cout << "[SearchValue] Function finished." << std::endl;
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3], 
                    const int rows_a, const int cols_a, 
                    const int rows_b, const int cols_b){
    
    // Function_Start message to terminal
    std::cout << "[MatrixMultiplication] Function called." << std::endl;
    
    // check for valid arrays
    if (cols_a != rows_b){
        std::cout << "[MatrixMultiplication] Invalid dimensions: the number of "
                   << "columns in matrix_a must equal the number of rows in matrix_b."
                   << std::endl;
        std::cout << "[MatrixMultiplication] Function finished." << std::endl;
        return;
    }

    // Body of the function
    // Inputs are not modified; result is stored in a new local array.

    int result[3][3] = {};

    for (int row = 0; row < rows_a; row++){
        for (int col = 0; col < cols_b; col++){
            int sum = 0;
            for (int k = 0; k < cols_a; k++){
                sum += matrix_a[row][k] * matrix_b[k][col];
            }
            result[row][col] = sum;
        }
    }

    // Print resulting matrix
    std::cout << "[MatrixMultiplication] Resulting matrix:" << std::endl;
    Print2DArray(result, rows_a);

    // Function_End message to terminal
    std::cout << "[MatrixMultiplication] Function finished." << std::endl;
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

    int size_row_two = sizeof(testing_matrix_two)/sizeof(testing_matrix_two[0]);

    std::cout << std::endl << "~ Testing MatrixAddition() ~" << std::endl;
    MatrixAddition(testing_matrix_one, size_row_one, testing_matrix_two, size_row_two);

    std::cout << std::endl << "~ Testing TransposeMatrix() ~" << std::endl;
    TransposeMatrix(testing_matrix_one, size_row_one);

    std::cout << std::endl << "~ Testing Determinant() (3x3) ~" << std::endl;
    Determinant(testing_matrix_one, size_row_one);

    // A separate 2x2 matrix to test Determinant() with a smaller, valid size.
    int testing_matrix_2x2[3][3] = {
        {4,7,0},
        {2,6,0},
        {0,0,0},
    };
    std::cout << std::endl << "~ Testing Determinant() (2x2) ~" << std::endl;
    Determinant(testing_matrix_2x2, 2);

    std::cout << std::endl << "~ Testing SearchValue() ~" << std::endl;
    SearchValue(testing_matrix_one, size_row_one, 5);
    SearchValue(testing_matrix_one, size_row_one, 100);

    std::cout << std::endl << "~ Testing MatrixMultiplication() ~" << std::endl;
    MatrixMultiplication(testing_matrix_one, testing_matrix_two,
                          size_row_one, 3, size_row_two, 3);

    return 0; 
}