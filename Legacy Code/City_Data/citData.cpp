/* 
    Prompt:
        (Data Processing)
        a. You have collected infomations about cities in your state. You decide to store each city's name, population, and mayor
        in a file. Write a C++ program to accept data for a number of cities from the keyboard and store the data in a file in the
        order in which it's entered.

        b. Reat the file created in Exercise 7a, sort the data alphabetically by citry name, and display the data.
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    I would typically be tempted to over build this with classes for each independent city. A class for IO stream handling with
    some public functions to write to a file that accepts a sting as input that can be returned from another public function or 
    cities. I could also build out something like a REPL for user inputs to be add aditional cities to a vector which can then be 
    written to a file.

    After that we can reconstruct our city classes to be sorted based on city name. Again details or what exactly is being looked 
    for in our implementation. If I were to take my typical over built method I would build a recursive merge sort algorithm to 
    sort strings particularly our city names. I would perhaps even attempt a merge in place system based on pointers so I could 
    simply write that to the console. I would also want to separate my classes into indpendent header files and so on which I know
    would only serve to make grading a simple assignment more of a pain.

    Considering how little information is given as to the MVP (Minimum Viable Product) I am actually not going to puruse such an 
    intricate and overbuilt solution to a simple problem. It is clearly a very deep rabit-hole I need not dig myself insto when I 
    can fulfil the prompt all without a single line outside of my main function.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string cityName,
        cityPop,
        cityMayor,
        line;
    int commandCode;

    bool addingCities = 1;

    vector<string> cities;

    ofstream outFile;
    ifstream inFile;
    
    char outFilename[11] = "cities.dat";
    outFile.open(outFilename);
    if (outFile.fail()) {
        cout << "Failed to open the output file" << endl;
        exit(1);
    };

    char inFilename[11] = "cities.dat";
    inFile.open(inFilename);
    if (inFile.fail()) {
        cout << "Failed to open the input file" <<endl;
        exit(1);
    };


    while(addingCities){
        cout << "Please Enter a command code (1 = Add more cities, 2 = Use random list of saved cities, 0 = Finished Entering Cities): ";
        cin >> commandCode;

        switch(commandCode){
            case 1: 
                cout << "Please enter a City Name: ";
                cin >> cityName;
                cout << "Please enter the Mayor's Name: ";
                cin >> cityMayor;
                cout << "Please enter the city's population: ";
                cin >> cityPop;
                outFile << cityName << ", " << cityMayor << ", " << cityPop << endl;
                break;
            case 0: 
                addingCities = 0;
                continue;
                break ;        
            default: 
                addingCities = 0;
                outFile << "Los Angeles, Eric Garceti, 4000000" << endl;
                outFile << "Sacramento, Darell Steinberg, " << endl;
                outFile << "Santa Clarita, Marsha McLean, 300000" << endl;
                outFile << "Bakerfield, Karen Goh, 375000" << endl;
                outFile << "San Diego, Todd Gloria, 1400000" << endl;
                continue;
        }

    }

   
    cout << "\n\033[4mReading from the file directly the list is:\033[0m\n" << endl;
    while(getline(inFile, line)){
        cout << line << endl;
        cities.push_back(line);
    };

    // Why reinvent the wheel this is my easy and lazy option.
    sort(cities.begin(), cities.end());
    cout << "\033[4mAfter data processing the sorted list of cities by City name is.\033[0m\n" << endl;
    for( int i = 0; i < cities.size(); i++){
        cout << cities[i] << endl;
    }
    

    inFile.close();
    outFile.close();

    return 0;
};