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
