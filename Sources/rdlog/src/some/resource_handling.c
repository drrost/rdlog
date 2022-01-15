//
//  load_resource.c
//
//
//  Created by Rostyslav Druzhchenko on 01.01.2022.
//

#include <CoreFoundation/CoreFoundation.h>
#include <resources.h>

void print_bundle_name(CFBundleRef bundle) {
    CFDictionaryRef infoDict = CFBundleGetInfoDictionary(bundle);
    CFStringRef name = (CFStringRef)CFDictionaryGetValue(infoDict, CFSTR("CFBundleName"));
    if (name == NULL) {
        printf("Can't find name for a bundle\n");
        return;
    }

    int BUFFER_SIZE = 1024*8;
    char buffer[BUFFER_SIZE];
    const char *ptr = CFStringGetCStringPtr(name, kCFStringEncodingUTF8);
    if (ptr == NULL) {
        if (CFStringGetCString(name, buffer, BUFFER_SIZE, kCFStringEncodingUTF8))
            ptr = buffer;
    }

    printf("%s\n", ptr);
}

// TODO: It's still in an experiment phase. Find a way to load data from a
// resource file from C.
//
void load_resource() {
    CFArrayRef allBundles = CFBundleGetAllBundles();
    CFIndex count = CFArrayGetCount(allBundles);

    CFBundleRef main_bundle = CFBundleGetMainBundle();
    print_bundle_name(main_bundle);

//    CFBundleRef bundle = rdlog_rdlog_SWIFTPM_MODULE_BUNDLE();
    print_bundle_name(main_bundle);

    for (int i = 0; i < count; i++) {
        CFBundleRef bundle = (CFBundleRef)CFArrayGetValueAtIndex(allBundles, i);
        print_bundle_name(bundle);
    }

    printBundleModule();

    printf("%ld", (long)count);

//    CFBundleGetPackageInfo(<#CFBundleRef bundle#>, <#UInt32 *packageType#>, <#UInt32 *packageCreator#>)
//    CFBundleCreate(<#CFAllocatorRef allocator#>, <#CFURLRef bundleURL#>)
//    CFBundleGetMainBundle
//    CFBundleGetBundleWithIdentifier
//    CFBundleCopyResourcesDirectoryURL
//    CFBundleCopyResourceURL
}
