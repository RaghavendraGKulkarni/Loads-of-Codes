// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<complex>
#include<cmath>
using namespace std;

/*
Name        : fft()
Description : Computes the DFT of a complex vector using FFT
Arguments   : The complex vector and a bool to denote the direction, in that order
Return      : A complex vector denoting the FFT
*/
vector<complex<double>> fft(vector<complex<double>> a, bool inverse = false) {
    int n = a.size();
    if(n == 1)
        return a;
    vector<complex<double>> even, odd;
    double theta = (2 * M_PI * 1.0) / n;
    if(inverse)
        theta *= -1.0;
    complex<double> w(1), wn(cos(theta), sin(theta));
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }
    odd = fft(odd, inverse);
    even = fft(even, inverse);
    for(int i = 0; i < n/2; i++) {
        a[i] = even[i] + w*odd[i];
        a[i + n/2] = even[i] - w*odd[i];
        w *= wn;
    }
    return a;
}

/*
Name        : multiply()
Description : Computes the product of two polynomials using FFT
Arguments   : Two integers denoting the degrees of the polynomials and two arrays denoting the polynomials, in that order
Return      : A vector denoting the product polynomial
*/
vector<int> multiply(int m, int n, int a[], int b[]) {

    // Declare the required local variables
    int k = (1 << ((int)ceil(log2(1.0 * (m + n + 1)))));
    vector<int> product;
    vector<complex<double>> a1(k, 0), b1(k, 0), p1(k, 0);
    
    // Copy the coefficients to complex space
    for(int i = 0; i <= m; i++)
        a1[i] = a[i];
    for(int i = 0; i <= n; i++)
        b1[i] = b[i];
    
    // Compute the DFT of the polynomials
    a1 = fft(a1);
    b1 = fft(b1);

    // Multiply the polynomials using point value representation
    for(int i = 0; i < k; i++)
        p1[i] = a1[i] * b1[i];
    
    // Compute the inverse DFT of the polynomial and extract the coefficients
    p1 = fft(p1, true);
    for(int i = 0; i <= m + n; i++) {
        p1[i] /= k;
        product.push_back(round(p1[i].real()));
    }

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