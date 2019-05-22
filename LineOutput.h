//
//  LineOutput.h
//  Program3
//
//  Created by Alan Chávez on 3/8/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef LineOutput_h
#define LineOutput_h

#include "BaseDecorator.h"

template<typename T>

class LineOutput : public BaseDecorator<T>
{
    public:
        LineOutput(Output<T> *o) : BaseDecorator<T>(o){}
        ~LineOutput(){}
    
        void write(const T& t)
        {
            BaseDecorator<T>::write(t + "\n\n");
        }
    
        void writeString(const std::string&){};
};

#endif /* LineOutput_h */
