// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
using namespace std;

// Define the class SQL
class sql {

    // Define the required private variables
    private:
        map<string, vector<vector<string>>> tables;
        map<string, int> columnNum;

    // Define the public constructor and methods
    public:

        // Define the class constructor
        sql() {

        }
        
        // Define the createTable method
        string createTable(string name, int c) {
            columnNum.insert({name, c});
            return "Table successfully created";
        }
        
        // Define the insertRow method
        string insertRow(string name, vector<string> row) {
            if(columnNum.find(name) == columnNum.end())
                return "Table does not exist";
            if(columnNum[name] != row.size())
                return "Incompatible number of columns";
            tables[name].push_back(row);
            return "Row successfully inserted";
        }
        
        // Define the deleteRow mwthod
        string deleteRow(string name, int r) {
            if(columnNum.find(name) == columnNum.end())
                return "Table does not exist";
            r--;
            if(tables[name].size() <= r)
                return "Row does not exist";
            tables[name].erase(tables[name].begin() + r);
            return "Row successfully deleted";
        }
        
        // Define the selectRow method
        vector<string> selectRow(string name, int r) {
            if(columnNum.find(name) == columnNum.end())
                return {"Table does not exist"};
            r--;
            if(tables[name].size() <= r)
                return {"Row does not exist"};
            return tables[name][r];
        }

        // Define the selectCell method
        string selectCell(string name, int r, int c) {
            if(columnNum.find(name) == columnNum.end())
                return "Table does not exist";
            r--;
            if(tables[name].size() <= r)
                return "Row does not exist";
            c--;
            if(columnNum[name] <= c)
                return "Column does not exist";
            return tables[name][r][c];
        }
};

/*
Name        : process()
Description : Processes each query on the SQL system
Arguments   : A vector denoting the queries
Return      : A vector of the outputs
*/
vector<string> process(vector<string> queries) {
    
    // Initialize the required local variables
    sql s = sql();
    string name, cell, temp;
    vector<string> result, row;
    int op, r, c;

    // Process the queries
    for(auto &query : queries) {
        
        // Parse the operation
        stringstream input(query);
        input >> op;

        // Select the operation
        switch(op) {
            case 1:input >> name >> c;
                    result.push_back(s.createTable(name, c));
                    break;
            case 2:input >> name;
                    row.clear();
                    while(input >> cell)
                        row.push_back(cell);
                    result.push_back(s.insertRow(name, row));
                    break;
            case 3:input >> name >> r;
                    result.push_back(s.deleteRow(name, r));
                    break;
            case 4:input >> name >> r;
                    row = s.selectRow(name, r);
                    temp = row[0];
                    for(int i = 1; i < row.size(); i++)
                        temp += (", " + row[i]);
                    result.push_back(temp);
                    break;
            case 5:input >> name >> r >> c;
                    result.push_back(s.selectCell(name, r, c));
                    break;
            default:
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
    int n;
    string op;
    input >> n;
    getline(input, op);
    vector<string> queries(n);
    for(int i = 0; i < n; i++) {
        getline(input, op);
        queries.push_back(op);
    }    

    // Close the input file
    input.close();

    // Call the subroutine to process the queries
    vector<string> result = process(queries);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << endl << result[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}