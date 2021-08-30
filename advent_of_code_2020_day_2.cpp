using namespace std;

#include <iostream>
#include <vector>
#include <fstream>


struct passwordDatabase
{
    char requiredLetter;
    int min;
    int max;
    string pass;
};

vector<passwordDatabase> textToVector(string inFileName)
{
    // Create a vector array for the file
    vector<passwordDatabase> passList;
    // Create a string to output the file contents to
    string line;
    // Name a variable for the file
    ifstream inFile;
    // Open the Day 1 Input File
    inFile.open(inFileName);

    if (inFile.fail())
    {
        throw "garbage";
    }
    // a loop that iterates to write the file to a vector structure
    while (getline(inFile, line))
    {
        //New object
        passwordDatabase currentPass;
        // Beginning of line
        int index = 0;
        // Current Value string
        string currVal = "";
        // Add to the index
        while (line[index] != '-')
        {    
            currVal += line[index];
            index++;    
        }
        // Store minimum value
        currentPass.min = stoi(currVal);
        // Bypass the "-"
        index++;
        // Resetting current value
        currVal = "";
        // Add until we hit the space
        while (line[index] != ' ')
        {
            currVal += line[index];
            index++;
        }
        //store maximum value
        currentPass.max = stoi(currVal);
        // move past the space to the number
        index++;
        // Store the Required Letter
        currentPass.requiredLetter = line[index];
        // Jump over letter, - and space
        index += 3;
        // store the value of the end
        currentPass.pass = line.substr(index);
        // Jump over space
        index++;
        // send object back to vector
        passList.push_back(currentPass);
    }
    // Close the File
    inFile.close();
    return passList;
}
int part1(vector<passwordDatabase> passList)
{
    // Number of acceptable passwords
    int acceptablePasswords = 0;

    for (int i = 0; i < passList.size(); i++)
    {
        int charCount = 0;
        for (int j = 0; j < passList[i].pass.size(); j++)
        {
            if (passList[i].pass[j] == passList[i].requiredLetter)
                charCount++;
        }
        if (charCount >= passList[i].min && charCount <= passList[i].max)
            acceptablePasswords++;
    }

    return acceptablePasswords;

}



int main()
{
    // Vectors Input into class from file
    vector<passwordDatabase> passList = textToVector("input_day2.txt");
    cout << "Part 1's Result is " << part1(passList) << '\n';

    return 0;
}