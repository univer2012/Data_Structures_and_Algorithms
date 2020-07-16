//
//  UIViewController+ExecuteMethod.h
//  ObjectiveCDemo20200321
//
//  Created by 远平 on 2020/4/25.
//  Copyright © 2020 远平. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (ExecuteMethod)

- (void)executeSelectorWith:(NSString *)selText;

@end

NS_ASSUME_NONNULL_END
