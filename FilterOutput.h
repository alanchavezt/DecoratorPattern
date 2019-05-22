//
//  FilterOutput.h
//  Program3
//
//  Created by Alan Chávez on 3/8/19.
//  Copyright © 2019 Alan Chávez. All rights reserved.
//

#ifndef FilterOutput_h
#define FilterOutput_h

#include "BaseDecorator.h"

template<typename T>

class FilterOutput : public BaseDecorator<T>
{
    std::string filter;
    
    public:
        FilterOutput(Output<T> *o, std::string s) : filter(s), BaseDecorator<T>(o) {}
        ~FilterOutput() {}
    
        void write(const T& t)
        {
            if (filter == "1")
            {
                if (ContainsHash(t))
                {
                    BaseDecorator<T>::write(t);
                }
            }
            else if(filter == "2")
            {
                if (ContainsTenWordsOrLess(t))
                {
                    BaseDecorator<T>::write(t);
                }
            }
        }
    
        void writeString(const std::string&){};
    
        bool ContainsHash(T t)
        {
            if (t.find("#") != std::string::npos)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
        bool ContainsTenWordsOrLess(T t)
        {
            int count = 0;
            std::istringstream words(t);
            std::string word;
            
            while(words >> word)
            {
                count++;
            }
            
            if (count <= 10)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

#endif /* FilterOutput_h */
