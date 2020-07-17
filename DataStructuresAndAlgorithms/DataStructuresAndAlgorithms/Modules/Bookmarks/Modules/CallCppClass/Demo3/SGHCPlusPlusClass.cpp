//
//  SGHCPlusPlusClass.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//

#include "SGHCPlusPlusClass.hpp"
#include <stdio.h>

CPlusPlusClass::CPlusPlusClass() : m_i(0) {
    printf("CPlusPlusClass::CPlusPlusClass()\n");
    func();
}

CPlusPlusClass::~CPlusPlusClass() {
    printf("CPlusPlusClass::~CPlusPlusClass()\n");
}

void CPlusPlusClass::func() {
    printf("CPlusPlusClass func print: %d\n",m_i);
}

