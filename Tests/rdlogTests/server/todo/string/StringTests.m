//
//  StringTests.m
//
//
//  Created by Rostyslav Druzhchenko on 23.01.2022.
//

#import <XCTest/XCTest.h>
#import <rd_todo.h>
#import <mem_utils.h>

@interface StringTests : XCTestCase

@property (nonatomic, assign) NSInteger allocCount;

@end

@implementation StringTests

- (void)setUp {
    self.allocCount = rd_get_alloc_counter();
}

- (void)tearDown {
    NSInteger after = rd_get_alloc_counter();
    XCTAssertEqual(self.allocCount, after);
}

- (void)testSprintf {
    // Given

    // When
    char *s = rd_sprintf("Abc%d%d%s%c !!!%s\n", 3, 5, "aaa", 'D', "???\n");

    // Then
    XCTAssertTrue(rd_strcmp(s, "Abc35aaaD !!!???\n\n"));
    rd_strdel(&s);
}

@end
