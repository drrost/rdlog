//
//  CallStackTests.swift
//
//
//  Created by Rostyslav Druzhchenko on 30.01.2022.
//

import XCTest

@testable import rdlog_client

class CallStackTests: XCTestCase {

    // MARK: - Variables

    var sut: NSObject!

    // MARK: - Tests routines

    override func setUp() {
        sut = NSObject()
    }

    // MARK: - Init tests

    func testCreation() {
        // Given
        // When
        let result = CallStackParser.getThisClassAndMethodInScope()

        // Then
        XCTAssertEqual("CallStackTests", result?.0)
        XCTAssertEqual("testCreation()", result?.1)
    }

    func testCalling() {
        // Given
        // When
        let result = internalFunction()

        // Then
        XCTAssertEqual("CallStackTests", result?.0)
        XCTAssertEqual("testCalling()", result?.1)
    }
}

private extension CallStackTests {

    func internalFunction() -> (String, String)? {
        CallStackParser.getCallingClassAndMethodInScope()
    }
}
