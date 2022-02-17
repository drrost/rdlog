//
//  RDLoggingEvent.swift
//
//
//  Created by Rostyslav Druzhchenko on 30.01.2022.
//

import Foundation

final class RDLoggingEvent {

    let level: Level
    let message: String

    init(_ level: Level, _ message: String) {
        self.level = level
        self.message = message
    }
}
