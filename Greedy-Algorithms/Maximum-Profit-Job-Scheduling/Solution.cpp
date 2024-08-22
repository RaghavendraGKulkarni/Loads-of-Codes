// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

/*
Name        : jobScheduling()
Description : Finds a scheduling of the jobs such that the profit of completing a job within its deadline is maximized
Arguments   : The vector of triplets denoting the jobs, and a variable to store the maximum profit, in that order
Return      : A vector of job ids completed in order of the 
*/
vector<int> jobScheduling(vector<array<int, 3>> jobs, int &maxProfit) {
    
    // Initialize the required local variables
    int profit = 0, maxDeadline;
    maxProfit = 0;

    // Sort the jobs according to their profit
    sort(jobs.begin(), jobs.end(), [](const array<int, 3> &a, const array<int, 3> &b){return a[2] > b[2];});

    // Compute the maximum deadline of the jobs
    maxDeadline = jobs[0][1];
    for(int i = 1; i < jobs.size(); i++)
        maxDeadline = max(maxDeadline, jobs[i][1]);

    vector<int> days(maxDeadline + 1, -1);

    // Scan the jobs to schedule them
    for(int i = 0; i < jobs.size(); i++) {

        // Check for an empty slot on or before the deadline of the job
        for(int j = jobs[i][1]; j > 0; j--) {
            if(days[j] == -1) {
                days[j] = jobs[i][0];
                maxProfit += jobs[i][2];
                break;
            }
        }
    }

    // Return the result
    return days;
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
    int n, id, deadline, profit, maxProfit;
    input >> n;
    vector<array<int, 3>> jobs(n);
    for(int i = 0; i < n; i++) {
        input >> id >> deadline >> profit;
        jobs[i] = {id, deadline, profit};
    }

    // Close the input file
    input.close();

    // Call the subroutine to compute the maximum profit
    vector<int> result = jobScheduling(jobs, maxProfit);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result.size() - 1 << ' ' << maxProfit << endl;
    for(int i = 1; i < result.size(); i++)
        (i == 1) ? (output << result[i]) : (output << ' ' << result[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}