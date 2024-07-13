// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

/*
Name        : matmul()
Description : Multiplies two matrices and stores the result in first matrix
Arguments   : The two 2D matrix
Return      : None
*/
void matmul(int a[2][2], int b[2][2]) {

    // Initialize the required local variables
    int c[2][2];

    // Perform the multiplication
    c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    // Copy the result to first matrix
    a[0][0] = c[0][0];
    a[0][1] = c[0][1];
    a[1][0] = c[1][0];
    a[1][1] = c[1][1];

    // Return
    return;
}

/*
Name        : power()
Description : Computes the matrix power n in Log time iteratively
Arguments   : The 2D matrix and an integer denoting n, in that order
Return      : None
*/
void power(int mat[2][2], int n) {
    
    // Handle the base case
    if(n == 1)
        return;

    // Initialize the required local variables
    int result[2][2] = {{1, 0}, {0, 1}}, power[2][2];
    power[0][0] = mat[0][0];
    power[0][1] = mat[0][1];
    power[1][0] = mat[1][0];
    power[1][1] = mat[1][1];

    // Compute x power n
    while(n) {
        
        // If exponent is odd
        if(n % 2 == 1)
            matmul(result, power);
        
        // Divide exponent by 2
        n /= 2;
        matmul(power, power);
    }

    // Copy the result to original matrix
    mat[0][0] = result[0][0];
    mat[0][1] = result[0][1];
    mat[1][0] = result[1][0];
    mat[1][1] = result[1][1];
    
    // Return
    return;
}

/*
Name        : nthFibonacciNumber()
Description : Computes the nth Fibonacci Number
Arguments   : A single non-negative integer denoting n
Return      : A single non-negative integer denoting the nth Fibonacci Number
*/
int nthFibonacciNumber(int n) {
    
    // Handle the base case
    if(n <= 1)
        return n;

    // Declare the required local variables
    int mat[2][2] = {{0, 1}, {1, 1}}, a = 0, b = 1;

    // Compute the power of matrix in log time
    power(mat, n - 1);

    // Multiply with the matrix to get nth fibonacci number
    int c = a*mat[0][1] + b*mat[1][1];

    // Return the result
    return c;
}

/*
Name        : main()
Description : Handles I/O and calls the required subroutines
Arguments   : None
Return      : Integer 0
*/
int main() {

    // Open the input file and handle the exception
    ifstream input;
    input.open("Input.txt");
    if(input.fail()) {
        cerr << "Please provide the correct Input File...!!!" << endl;
        exit(0);
    }

    // Declare the required variables and read the input
    int n;
    input >> n;

    // Close the input file
    input.close();

    // Call the subroutine to compute the Fibonacci Number
    int result = nthFibonacciNumber(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;
    
    // Close the output file and return
    output.close();
    return 0;
}