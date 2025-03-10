#include <iostream>
#include <fstream>

using namespace std;

// Function to merge two sorted files into a third file
void mergeFiles(ifstream& file1, ifstream& file2, ofstream& outputFile) {
    int num1, num2;

    // Read the first number from each file
    file1 >> num1;
    file2 >> num2;

    // Merge the numbers from both files
    while (!file1.eof() && !file2.eof()) {
        if (num1 < num2) {
            outputFile << num1 << endl;
            file1 >> num1;
        } else {
            outputFile << num2 << endl;
            file2 >> num2;
        }
    }

    // Write remaining numbers from file1
    while (!file1.eof()) {
        outputFile << num1 << endl;
        file1 >> num1;
    }

    // Write remaining numbers from file2
    while (!file2.eof()) {
        outputFile << num2 << endl;
        file2 >> num2;
    }
}

int main() {
    string inputFile1, inputFile2, outputFile;

    // Get file names from user
    cout << "Enter the first input file name: ";
    cin >> inputFile1;
    cout << "Enter the second input file name: ";
    cin >> inputFile2;
    cout << "Enter the output file name: ";
    cin >> outputFile;

    // Open input and output files
    ifstream file1(inputFile1), file2(inputFile2);
    ofstream output(outputFile);

    // Check if files are opened successfully
    if (!file1 || !file2 || !output) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    // Call the merge function
    mergeFiles(file1, file2, output);

    // Close the files
    file1.close();
    file2.close();
    output.close();

    cout << "Files merged successfully." << endl;

    return 0;
}
