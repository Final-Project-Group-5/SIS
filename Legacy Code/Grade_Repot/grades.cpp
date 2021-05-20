#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class IOStreamHandler{
    public:
        IOStreamHandler();
        void openStreams();
        void cleanUp();
        void seedGradeFile();
        string readFromFile();
        void writeToFile();
    private:
        ofstream outFile;
        ifstream inFile;
};

IOStreamHandler::IOStreamHandler(){

};

void IOStreamHandler::openStreams(){
    char outFilename[11] = "grades.dat";
    outFile.open(outFilename);
    if (outFile.fail()) {
        cout << "Failed to open the output file" << endl;
        exit(1);
    };

    char inFilename[11] = "grades.dat";
    inFile.open(inFilename);
    if (inFile.fail()) {
        cout << "Failed to open the input file" <<endl;
        exit(1);
    };
}

void IOStreamHandler::seedGradeFile(){
    
};

string IOStreamHandler::readFromFile(){
    string line;
    while(!inFile.eof()){
        string temp;
        inFile >> temp;
        line += " " + temp;
    }
    // inFile >> line;
    return line;
};

void IOStreamHandler::writeToFile(){
    // outFile <<  << endl;
};

void IOStreamHandler::cleanUp(){
    inFile.close();
    outFile.close();
};

int main() {
    IOStreamHandler iostream = IOStreamHandler();

    iostream.openStreams();
    
    iostream.writeToFile();
    cout << iostream.readFromFile();


    iostream.cleanUp();
    return 0;
};