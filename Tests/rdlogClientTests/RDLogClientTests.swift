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
        sut = RDLogger("")
    }

    // MARK: - Init tests

    func testCreation() {
        // Given
        // When
        // Then
    }

    func testSunnyDayFlow() {
        // Given
        let logger = RDLogManager.getLogger()
        // Connect to the server
        // Send a message

        // When
        // Then
    }
}
