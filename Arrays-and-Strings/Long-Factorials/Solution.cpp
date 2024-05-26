// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : multiply()
Description : Multiplies a large number stored in an array with a given number
Arguments   : A vector denoting the large number and an integer denoting the number to be multiplied with, in that order
Return      : A vector denoting the product of the multiplication
*/
vector<int> multiply(vector<int> factorial, int number) {
    
    // Declare the required local variables
    int zeros = 0, dig, pro, carry, sum;
    vector<int> product;

    // For every digit in the number
    while(number) {

        // Extract the digit and update the number
        dig = number % 10;
        number /= 10;

        // Initialize the subproduct and carry to 0
        vector<int> subproduct(zeros, 0);
        carry = 0;

        // Multiply the digit with the large number and store it in the subproduct
        for(int i = factorial.size() - 1; i >= 0; i--) {
            pro = (factorial[i]*dig + carry);
            carry = pro / 10;
            pro %= 10;
            subproduct.insert(subproduct.begin(), pro);
        }

        // Add the carry at the beginning of the subproduct, if any
        while(carry) {
            subproduct.insert(subproduct.begin(), carry % 10);
            carry /= 10;
        }

        // If this is first subproduct, assign this as the product
        if(zeros == 0)
            product = subproduct;
        
        // Else, add the subproduct to the total product
        else {

            // Add extra zeros at the beginning of product to equalize the lengths
            while(product.size() < subproduct.size())
                product.insert(product.begin(), 0);
            
            // Initialize the carry and perform the addition
            carry = 0;
            for(int i = subproduct.size() - 1; i >= 0; i--) {
                sum = (product[i] + subproduct[i] + carry);
                carry = sum / 10;
                sum %= 10;
                product[i] = sum;
            }

            // Add the carry at the beginning of the product, if any
            while(carry) {
                product.insert(product.begin(), carry % 10);
                carry /= 10;
            }
        }

        // Left shift for next subproduct
        zeros++;
    }

    // Return the large product
    return product;
}

/*
Name        : computeFactorial()
Description : Computes the factorial of n
Arguments   : A single non-negative integer denoting n
Return      : A vector denoting the factorial of n
*/
vector<int> computeFactorial(int n) {

    // Initialize the factorial with base case
    vector<int> factorial = {1};

    // Multiply each number from 1 to n
    for(int i = 1; i <= n; i++)
        factorial = multiply(factorial, i);
    
    // Return the factorial
    return factorial;
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

    // Call the subroutine to compute the Factorial
    vector<int> factorial = computeFactorial(n);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < factorial.size(); i++)
        output << factorial[i];
    
    // Close the output file and return
    output.close();
    return 0;
}