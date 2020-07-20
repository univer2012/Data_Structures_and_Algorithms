//
//  SGHCPlusPlusClass.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef SGHCPlusPlusClass_hpp
#define SGHCPlusPlusClass_hpp

#include <stdio.h>

class CPlusPlusClass {
public:
    CPlusPlusClass();
    virtual ~CPlusPlusClass();
    void func();
    void setInt(int i) {
        m_i = i;
    }
private:
    int m_i;
};


#endif /* SGHCPlusPlusClass_hpp */
