//
//  SGHTabBarViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/16.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHTabBarViewController.h"
#import "SGHContactsViewController.h"
#import "SGHBookmarksViewController.h"

@interface SGHTabBarViewController ()

@end

@implementation SGHTabBarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UINavigationController *bookmarksNavController = ({
        UINavigationController *navigationController = [[UINavigationController alloc]initWithRootViewController:[SGHBookmarksViewController new]];
        navigationController.tabBarItem = [[UITabBarItem alloc]initWithTabBarSystemItem:UITabBarSystemItemBookmarks tag:0];
        navigationController;
    });
    
    UINavigationController *contactsNavController = ({
        UINavigationController *navigationController = [[UINavigationController alloc]initWithRootViewController:[SGHContactsViewController new]];
        navigationController.tabBarItem = [[UITabBarItem alloc]initWithTabBarSystemItem:UITabBarSystemItemContacts tag:1];
        navigationController;
    });
    
    self.viewControllers = @[bookmarksNavController, contactsNavController];
    
    //设置选中的tabBarItem颜色
    if (@available(iOS 8.0, *)) {
        self.tabBar.tintColor = [UIColor redColor];
        //[self.tabBar setSelectedImageTintColor:[UIColor redColor]];
    } else {
        self.tabBar.tintColor = [UIColor redColor];//iOS5.0
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
