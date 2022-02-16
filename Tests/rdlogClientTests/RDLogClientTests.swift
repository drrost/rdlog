//
//  RDLogClientTests.swift
//
//
//  Created by Rostyslav Druzhchenko on 30.01.2022.
//

import XCTest

@testable import rdlog_client

class RDLogClientTests: XCTestCase {

    // MARK: - Variables

    var sut: ILogger!

    // MARK: - Tests routines

    override func setUp() {
        sut = RDLogManager.getLogger()
    }

    // MARK: - Init tests

    func testCreation() {
        // Given
        // When
        let logger = RDLogManager.getLogger()

        // Then
        XCTAssertEqual("RDLogClientTests", logger.name)
    }

    func testSunnyDayFlow() {
        // Given
        // Connect to the server
        // Send a message
        let logger = RDLogManager.getLogger()

        // When
        logger.log(.all, "test message")

        // Then
    }
}
