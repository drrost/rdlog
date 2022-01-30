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
        let result = CallStackAnalyser.getThis()

        // Then
        XCTAssertEqual("CallStackTests", result?.class)
        XCTAssertEqual("testCreation()", result?.method)
    }

    func testCalling() {
        // Given
        // When
        let result = internalFunction()

        // Then
        XCTAssertEqual("CallStackTests", result?.class)
        XCTAssertEqual("testCalling()", result?.method)
    }
}

private extension CallStackTests {

    func internalFunction() -> StackItem? {
        CallStackAnalyser.getCalling()
    }
}
