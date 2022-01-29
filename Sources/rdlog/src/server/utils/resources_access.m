//
//  ResourcesAccess.m
//
//
//  Created by Rostyslav Druzhchenko on 14.01.2022.
//

#import <Foundation/Foundation.h>

@import reswrapper;

char *path_for_res(const char *name) {
    if (name == 0) {
        return 0;
    }

    ResourceHelper *resHelper = [ResourceHelper new];
    NSString *resource = [NSString stringWithCString:name encoding:NSASCIIStringEncoding];
    char *path = [resHelper path_for_res: resource];
    return  path;
}
