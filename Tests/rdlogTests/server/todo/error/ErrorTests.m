//
//  ErrorTests.m
//  
//
//  Created by Rostyslav Druzhchenko on 29.01.2022.
//

#import <XCTest/XCTest.h>
#import <mem_utils.h>
#include "rdlog.h"

@interface ErrorTests : XCTestCase

@property (nonatomic, assign) NSInteger allocCount;

@end

@implementation ErrorTests

- (void)setUp {
    self.allocCount = rd_get_alloc_counter();
}

- (void)tearDown {
    NSInteger after = rd_get_alloc_counter();
    XCTAssertEqual(self.allocCount, after);
}

- (void)testCreate {
    // Given
    int code = 1;
    char *message = "Something went wrong";

    // When
    t_error *error = rd_error_new(code, message);

    // Then
    XCTAssertTrue(error->code == code);
    XCTAssert(rd_strcmp(message, error->message) == 0);
    rd_error_del(&error);
}

- (void)testCreateEllipsis {
    // Given
    int code = 1;
    char *message = "Something %s %s %d";

    // When
    t_error *error = rd_error_new(code, message, "went", "wrong", 20);

    // Then
    XCTAssertTrue(error->code == code);
    XCTAssert(rd_strcmp("Something went wrong 20", error->message) == 0);
    rd_error_del(&error);
}

@end
