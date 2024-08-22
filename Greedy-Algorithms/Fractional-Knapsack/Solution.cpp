// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

/*
Name        : fractionalKnapSack()
Description : Finds the maximum profit attained by putting items into a Knapsack in fractional manner
Arguments   : The vector of items, the capacity of the knapsack and a variable to store the maxprofit obtained, in that order
Return      : A vector of items information included in the knapsack
*/
vector<pair<pair<int, int>, double>> fractionalKnapSack(vector<pair<int, int>> items, int capacity, double &maxProfit) {
    
    // Initialize the required local variables
    int weight = 0, remain;
    maxProfit = 0;
    vector<pair<pair<int, int>, double>> result;

    // Sort the items according to value/weight ratio
    sort(items.begin(), items.end(), [](const pair<int, int> &a, const pair<int, int> &b){return (((double)a.second)/((double)a.first)) > (((double)b.second)/((double)b.first));});

    // Scan the items to enter into the knapsack
    for(int i = 0; i < items.size(); i++) {

        // Check if complete item can be included
        if(weight + items[i].first <= capacity) {
            weight += items[i].first;
            maxProfit += items[i].second;
            result.push_back({items[i], 1.0});
        }

        // Take a fraction of the current item
        else {
            remain = capacity - weight;
            maxProfit += (items[i].second / (double) items[i].first) * (double) remain;
            result.push_back({items[i], ((double)remain/items[i].first)});
            break;
        }
    }

    // Return the result
    return result;
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
    int n, capacity, w, v;
    double maxProfit;
    input >> n >> capacity;
    vector<pair<int, int>> items(n);
    for(int i = 0; i < n; i++) {
        input >> w >> v;
        items[i] = {w, v};
    }

    // Close the input file
    input.close();

    // Call the subroutine to compute the maximum profit
    vector<pair<pair<int, int>, double>> result = fractionalKnapSack(items, capacity, maxProfit);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result.size() << ' ' << maxProfit;
    for(int i = 0; i < result.size(); i++)
        output << endl << result[i].first.first << ' ' << result[i].first.second << ' ' << result[i].second;
    
    // Close the output file and return
    output.close();
    return 0;
}