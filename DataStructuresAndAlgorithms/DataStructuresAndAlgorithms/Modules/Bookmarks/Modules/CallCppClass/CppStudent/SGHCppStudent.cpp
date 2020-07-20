//
//  SGHCppStudent.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//

#include "SGHCppStudent.hpp"
#include <iostream>
using namespace std;

class Student {
public:
    void getWeight() {
        cout<<"Object C与C++混合编程。体重为："<<weight<<"kg";
        printf("调用C＋＋语言。getWeight");
    }
    
    void setWeight(int x) {
        weight = x;
        printf("调用C＋＋语言。setWeigth");
    }
    
    
private:
    int weight;
};
