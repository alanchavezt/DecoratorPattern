//
//  TeeOutput.h
//  Program3
//
//  Created by Alan Chávez on 3/8/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef TeeOutput_h
#define TeeOutput_h

#include "BaseDecorator.h"

template<typename T>

class TeeOutput : public BaseDecorator<T>
{
    std::ostream& teeOust;
    
    public:
        TeeOutput(Output<T> *out, std::ostream& oust) : teeOust(oust), BaseDecorator<T>(out){}
        ~TeeOutput(){}
    
        void write(const T& t)
        {
            BaseDecorator<T>::write(t);
            teeOust << t;
        }
    
        void writeString(const std::string&) {};
};

#endif /* TeeOutput_h */
