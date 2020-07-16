//
//  SGHTextCppClass.cpp
//  ObjectiveCDemo20200321
//
//  Created by blue on 2020/7/16.
//  Copyright © 2020 远平. All rights reserved.
//

#include "SGHTextCppClass.hpp"

void MyCppClass::ShowMsg(const char *text) {
    printf("%s", text);
}

float result[32];
float * GetDotClass:: GetDot() {
    return result;
}
