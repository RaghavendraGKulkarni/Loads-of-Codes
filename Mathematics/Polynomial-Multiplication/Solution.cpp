// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
Name        : multiply()
Description : Computes the product of two polynomials
Arguments   : Two integers denoting the degrees of the polynomials and two arrays denoting the polynomials, in that order
Return      : A vector denoting the product polynomial
*/
vector<int> multiply(int m, int n, int p1[], int p2[]) {
    
    // Declare the required local variables
    vector<int> product(m + n + 1, 0);

    // Perform the multiplication
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            product[i + j] += (p1[i] * p2[j]);

    // Return the product
    return product;
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
    int m, n;
    input >> m >> n;
    int *p1 = new int[m + 1], *p2 = new int[n + 1];
    for(int i = 0; i <= m; i++)
        input >> p1[i];
    for(int i = 0; i <= n; i++)
        input >> p2[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the product of the polynomials
    vector<int> p = multiply(m, n, p1, p2);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << p.size() - 1 << endl;
    for(int i = 0; i < p.size(); i++)
        (i == 0) ? (output << p[i]) : (output << ' ' << p[i]);
    
    // Delete the arrays, close the output file and return
    delete[] p1;
    delete[] p2;
    output.close();
    return 0;
}