#include <iostream>
#include <string>
//#include "parser.h"
//#include "waveform.h"
#include <algorithm>
#include <iomanip>
#include <climits>
#include <fstream>
#include <cstdlib>

using namespace std;

/*interface with termwave to do commands like 
open file.vcd
quit
add x_var
etc...
on console created using replxx*/

void open_file (const char *file_name) //open vcd file and print contents on screen
{
    string contents;
    ifstream infile;
    infile.open(file_name);
    cout << "Reading from file:" << endl;
    if (infile.fail())
    {
        cout << "Error! This file cannot be read." << endl;
    }
    else
    {
        while(!infile.fail() && !infile.eof())
        {
            infile >> contents;
            cout << contents << endl;
        }
    }
}

void exit_shell() //exits the termwave terminal
{
    string quit_terminal;
    if (quit_terminal == "quit")
    {
        exit(0);
    }
}

void add_to_file(const char *file_name, char var, string name) //adds variable to file and asks about the value to show on waveform
{                                                   //and how much time that value is that particular value
    ofstream outfile;
    outfile.open(file_name, ios::app);
    outfile << var << name << endl;
    int value;
    int time = 0;
    int cycle = 0;
    int ans;
    cout << "Do you want to define a value and amount of time for this variable? (Enter 1 or 0)" << endl;
    cin >> ans;
    while (ans == 1)
    {
        cout << "What is the value of this variable? (Enter 1 or 0)" << endl;
        cin >> value;
        cycle += time;
        outfile << "#" << cycle << endl;
        outfile << value << var << endl;
        cout << "For how long will it be this value?" << endl;
        cin >> time;
        cout << "Do you want to define a value and amount of time for this variable? (Enter 1 or 0)" << endl;
        cin >> ans;
    }
}

void go_to(const char *file_name, int time) //goes to a given cycle inside the vcd file
{
    int num;
    string contents;
    ifstream infile;
    infile.open(file_name);
    if (infile.fail)
    {
        cout << "Error! Couldn't open the file." << endl;
    }
    else
    {
        while (infile >> num)
        {
            infile >> contents;
            if (num == time )
            {
                cout << contents << endl;
                break;
            }
            else
            {
                cout << "This time is not valid." << endl;
            }
        }
    }
}

void show_file(const char *file_name, int time) //shows the added files for the period of time after the goto function
{
    ifstream infile;
    infile.open(file_name);
    go_to(file_name, time);
}