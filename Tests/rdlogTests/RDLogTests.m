//
//  RDLogTests.m
//
//
//  Created by Rostyslav Druzhchenko on 01.01.2022.
//

#import <XCTest/XCTest.h>

#import "resources.h"
#import <mem_utils.h>
#include <rdlib.h>

bool rd_str_has_suffix(const char *s, const char *suffix) {
    int length_s = rd_strlen(s);
    int length_suffix = rd_strlen(suffix);
    if (length_s < length_suffix) {
        return false;
    }

    for (int i = 0; i < length_suffix; i++) {
        if (s[length_s - i] != suffix[length_suffix - i]) {
            return false;
        }
    }

    return true;
}

@interface Test : XCTestCase

@end

@implementation Test

- (void)setUp {
}

- (void)tearDown {
}

- (void)testExample {

    int alloc_count_before = rd_get_alloc_counter();
    load_resource();
    int alloc_count_after = rd_get_alloc_counter();
    XCTAssertEqual(alloc_count_before, alloc_count_after);
}

- (void)testPathForResource {
    // Given
    char *resource = "data.json";

    // When
    int alloc_count_before = rd_get_alloc_counter();
    char *path = path_for_res(resource);

    // Then
    int alloc_count_after = rd_get_alloc_counter();
    XCTAssertEqual(alloc_count_before, alloc_count_after);
    XCTAssertTrue(rd_str_has_suffix(path, "/data.json"));
}

@end
