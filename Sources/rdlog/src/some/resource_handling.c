//
//  load_resource.c
//
//
//  Created by Rostyslav Druzhchenko on 01.01.2022.
//

#include <CoreFoundation/CoreFoundation.h>
#include <resources.h>
#include <rdlib.h>

char *cstr_from_cf(CFStringRef cf_str) {
    int length = CFStringGetLength(cf_str) + 1;
    char *buffer = rd_strnew(length);
    CFStringGetCString(cf_str, buffer, length, kCFStringEncodingUTF8);
    return buffer;
}

void print_bundle_name(CFBundleRef bundle) {
    CFDictionaryRef infoDict = CFBundleGetInfoDictionary(bundle);
    CFStringRef name = (CFStringRef)CFDictionaryGetValue(infoDict, CFSTR("CFBundleName"));
    if (name == NULL) {
        printf("Can't find name for a bundle\n");
        return;
    }

    char *ptr = cstr_from_cf(name);
    printf("%s\n", ptr);
    rd_strdel(&ptr);
}

// TODO: It's still in an experiment phase. Find a way to load data from a
// resource file from C.
//
void load_resource() {
    CFArrayRef allBundles = CFBundleGetAllBundles();
    CFIndex count = CFArrayGetCount(allBundles);

    CFBundleRef main_bundle = CFBundleGetMainBundle();
    print_bundle_name(main_bundle);

    print_bundle_name(main_bundle);

    for (int i = 0; i < count; i++) {
        CFBundleRef bundle = (CFBundleRef)CFArrayGetValueAtIndex(allBundles, i);
        print_bundle_name(bundle);
    }

    printBundleModule();
}
