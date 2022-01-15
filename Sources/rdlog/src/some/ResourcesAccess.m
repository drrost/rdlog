//
//  ResourcesAccess.m
//  
//
//  Created by Rostyslav Druzhchenko on 14.01.2022.
//

#import <Foundation/Foundation.h>

@import reswrapper;

void printBundleModule() {
    ResourceHelper *resHelper = [ResourceHelper new];
    char *path = [resHelper path_for_res];
    NSLog(@"bundle: %s", path);
}
