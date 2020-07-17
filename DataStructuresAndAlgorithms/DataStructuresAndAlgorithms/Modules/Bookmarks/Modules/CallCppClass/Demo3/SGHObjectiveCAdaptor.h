//
//  SGHObjectiveCAdaptor.h
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//

#import <Foundation/Foundation.h>

class CPlusPlusClass;

NS_ASSUME_NONNULL_BEGIN

@interface SGHObjectiveCAdaptor : NSObject {
    @private
    CPlusPlusClass *testObj;
}

- (void)objectiveFunc;

@end

NS_ASSUME_NONNULL_END
