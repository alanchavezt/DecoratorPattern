//
//  main.cpp
//  Program3
//
//  Created by Alan Chávez on 3/8/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#include <fstream>
#include "Output.h"
#include "StreamOutput.h"
#include "LineOutput.h"
#include "NumberedOutput.h"
#include "TeeOutput.h"
#include "FilterOutput.h"

using namespace std;

int main(int argc, const char * argv[])
{
    bool quit = true;
    string decoratorFileName;
    string outputFileName = "output.txt";
    string line;
    string teeFileName;
    string filter;
    ofstream oFileStr;
    ofstream teeOFileStr;
    string decorator;
    
    cout << "Enter the file name: ";
    getline(cin, decoratorFileName);
    ifstream iFileStr(decoratorFileName);

    if (iFileStr.is_open())
    {
        oFileStr.open(outputFileName);
        Output<string>* output = new StreamOutput<string>(oFileStr);
        
        while(quit)
        {
            cout << "\n**********Decorators**********\n";
            cout << "1 - LineOutput\n";
            cout << "2 - NumberedOutput\n";
            cout << "3 - TeeOutput\n";
            cout << "4 - FilterOutput\n";
            cout << "5 - Exit\n";
            cout << "Enter your choice and press return: ";
            getline(cin, decorator);
            
            if (decorator == "1")
            {
                output = new LineOutput<string>(output);
            }
            if (decorator == "2")
            {
                output = new NumberedOutput<string>(output);
            }
            if (decorator == "3")
            {
                if(teeFileName == "")
                {
                    cout << "Please enter a file name: ";
                    getline(cin, teeFileName);
                    teeOFileStr.open(teeFileName);
                    
                    if(teeOFileStr.is_open())
                    {
                        output = new TeeOutput<string>(output, teeOFileStr);
                    }
                }
                else
                {
                    cout << "Cannot create more files...\n";
                }
            }
            if (decorator == "4")
            {
                cout << "\n**********Filters**********" << endl;
                cout << "1 - Contains Hash(#)" << endl;
                cout << "2 - Contains ten words or less" << endl;
                cout << "Enter your choice and press return: ";
                getline(cin, filter);
                
                if(filter == "1" || filter == "2")
                {
                    output = new FilterOutput<string>(output, filter);
                }
            }
            if (decorator == "5")
            {
                cout << "End of program\n\n";
                quit = false;
            }
        }
        
        while (getline(iFileStr, line))
        {
            output->write(line);
        }
        
        iFileStr.close();
        oFileStr.close();
    }
    else
    {
        cout << "File not found!" << endl;
    }
}

