//
//  StreamOutput.h
//  Program3
//
//  Created by Alan Chávez on 3/8/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef StreamOutput_h
#define StreamOutput_h

#include "Output.h"

template<typename T>

class StreamOutput : public Output<T>
{
    std::ostream& sink;
    
    public:
        explicit StreamOutput(std::ostream& stream) : sink(stream) {}
    
        void write(const T& t)
        {
            sink << t;
        }
    
        void writeString(const std::string& s)
        {
            sink << s;
        }
};


#endif /* StreamOutput_h */
