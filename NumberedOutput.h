//
//  NumberedOutput.h
//  Program3
//
//  Created by Alan Chávez on 3/8/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef NumberedOutput_h
#define NumberedOutput_h

#include "BaseDecorator.h"

template<typename T>

class NumberedOutput : public BaseDecorator<T>
{
    int number = 1;
    
    public:
    
        NumberedOutput(Output<T> *o) : BaseDecorator<T>(o){}
        ~NumberedOutput(){}
    
        void write(const T& t)
        {
            BaseDecorator<T>::write("\t" + std::to_string(number) + ": " + t );
            number++;
        }
    
        void writeString(const std::string&){};
};

#endif /* NumberedOutput_h */
