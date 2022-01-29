//
//  DBCreationTEsts.m
//
//
//  Created by Rostyslav Druzhchenko on 22.01.2022.
//

#import <XCTest/XCTest.h>
#import <mem_utils.h>
#include "rdlog.h"

// SUT

int create_db_dir(t_db_settings *settings);
t_error *create_db_file(t_db_settings *settings);

@interface DBCreationTEsts : XCTestCase

@property (nonatomic, assign) NSInteger allocCount;

@end

@implementation DBCreationTEsts

- (void)setUp {

    rd_dir_delete("/usr/local/var/log_test");
    rd_dir_delete("/tmp/rdlog");

    self.allocCount = rd_get_alloc_counter();
}

- (void)tearDown {
    NSInteger after = rd_get_alloc_counter();
    XCTAssertEqual(self.allocCount, after);
}

- (void)testCreateDir {
    // Given
    XCTAssertFalse(rd_file_exists("/usr/local/var/log_test"));

    t_db_settings settings;
    settings.dir = "/usr/local/var/log_test";
    settings.file = "rdlog.sqlite";
    settings.sript_name = "message.sql";

    // When
    int result = create_db_dir(&settings);

    // Then
    XCTAssertTrue(rd_file_exists("/usr/local/var/log_test"));
    XCTAssertEqual(0, result);
}

- (void)testCreateDbFile {
    // Given
    t_db_settings settings;
    settings.dir = "/usr/local/var/log_test";
    settings.file = "rdlog.sqlite";
    settings.sript_name = "message.sql";

    // When
    t_error *error = create_db_file(&settings);

    // Then
    XCTAssertTrue(error == 0);
    XCTAssertTrue(rd_file_exists("/tmp/rdlog/message.sql"));
    XCTAssertTrue(rd_file_exists("/tmp/rdlog/rdlog.sqlite"));
}

- (void)testCreateDbFile_Fail {
    // Given
    t_db_settings settings;
    settings.dir = "/abc";

    // When
    t_error *error = create_db_file(&settings);

    // Then
    XCTAssertTrue(error != 0);
    XCTAssertTrue(rd_strcmp("Resource \"<NULL>\" not found", error->message) == 0);
    rd_error_del(&error);
}

@end
