#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "myLib.h"

using namespace MySpace;
using std::cout;
using std::cin;
using std::ios;
using std::ofstream;
using std::ifstream;
using std::string;
using std::exception;

int Array::length = 5;

int main() {
    string filepath = "/Users/ivangalkin/Documents/MSU/sem2/inf/14.03.2023/1/";
    Array arr((double)0, (char*)"file1", (char*)"filename1");

    cin >> arr;

    ofstream ofs;
    
    try {
        ofs.open((filepath+arr.GetFileName()+".txt").c_str(), ios::out);
        if(ofs.is_open()) {
            ofs << arr;

            ofs.close();
        } else {
            throw "Unable to open the file";
        }
    }
    catch (char* e) {
        cout << e << endl;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

    try {
        ofs.open((filepath+arr.GetFileName()+".txt").c_str(), ios::app);
        if(ofs.is_open()) {
            ofs << arr;

            ofs.close();
        } else {
            throw "Unable to open the file";
        }
    }
    catch (char* e) {
        cout << e << endl;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    

    Array arr2((double)0);

    ifstream ifs;
    ifs.open((filepath+arr.GetFileName()+".txt"));
    ifs >> arr2;
    ifs.close();

    cout << arr2 << endl;

    try {
        cout << arr2[7];
    }
    catch (char* e) {
        cout << e << endl;
    }

    try {
        cout << arr2 / 0.0 << endl;
    }
    catch (char* e) {
        cout << e << endl;
    }

    Array arr3((double)0);
    try {
        cin >> arr3;
    }
    catch (char* e) {
        cout << e << endl;
    }

    return 0;
}