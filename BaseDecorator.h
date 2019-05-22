//
//  BaseDecorator.h
//  Program3
//
//  Created by Alan Chávez on 3/8/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef BaseDecorator_h
#define BaseDecorator_h

#include "Output.h"

template<typename T>

class BaseDecorator : public Output<T>
{
    Output<T>* output;
    
    public:
        BaseDecorator(Output<T>* os)
        {
            output = os;
        }
    
        void write(const T& t)
        {
            output->write(t);
        }
    
        virtual void writeString(const std::string&) = 0;
};

#endif /* BaseDecorator_h */
