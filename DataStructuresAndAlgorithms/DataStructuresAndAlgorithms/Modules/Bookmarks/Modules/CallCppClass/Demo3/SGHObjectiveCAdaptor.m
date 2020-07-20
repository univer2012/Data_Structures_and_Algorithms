//
//  SGHObjectiveCAdaptor.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHObjectiveCAdaptor.h"
#include "SGHCPlusPlusClass.hpp"

@implementation SGHObjectiveCAdaptor

- (instancetype)init
{
    self = [super init];
    if (self) {
        testObj = new CPlusPlusClass();
    }
    return self;
}

- (void)dealloc
{
    if (testObj != NULL) {
        delete testObj;
        testObj = NULL;
    }
    //[super dealloc];
}
- (void)objectiveFunc {
    testObj-> setInt(5);
    testObj->func();
}

@end
