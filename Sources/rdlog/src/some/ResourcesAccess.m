//
//  ResourcesAccess.m
//  
//
//  Created by Rostyslav Druzhchenko on 14.01.2022.
//

#import <Foundation/Foundation.h>

@import reswrapper;

@interface BundleHelper : NSObject

@end

//NSBundle *rdlog_rdlog_SWIFTPM_MODULE_BUNDLE(void);

@implementation BundleHelper

+ (NSBundle *)getBundle {
//#if SWIFT_PACKAGE
//    rdlog_rdlog_SWIFTPM_MODULE_BUNDLE();
//    SWIFTPM_MODULE_BUNDLE;
    return nil;
//#else
//    return [NSBundle bundleForClass:[ABTTestUtilities class]];
//#endif
}

@end

void printBundleModule() {
    ResourceHelper *resHelper = [ResourceHelper new];
    char *path = [resHelper path_for_res];
    NSBundle *bundle = [BundleHelper getBundle];
    NSLog(@"bundle: %@", bundle);
}
