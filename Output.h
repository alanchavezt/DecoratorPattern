//
//  Output.h
//  Program3
//
//  Created by Alan Chávez on 3/8/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef Output_h
#define Output_h

#include <string>
#include <iostream>
#include <sstream>

template<typename T>

class Output
{
    public:
        virtual ~Output(){}
        virtual void write(const T&) = 0;
        virtual void writeString(const std::string&) = 0;
};

#endif /* Output_h */
