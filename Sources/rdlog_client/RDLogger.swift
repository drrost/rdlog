//
//  RDLogClient.swift
//
//
//  Created by Rostyslav Druzhchenko on 30.01.2022.
//

import Foundation
import rdlib

public enum Level {
    case off
    case fatal
    case error
    case warn
    case info
    case debug
    case trace
    case all
}

public protocol ILogger {

    var name: String { get }

    func debug(_ message: String)
    func error(_ message: String)
    func fatal(_ message: String)
    func info(_ message: String)
    func trace(_ message: String)
    func warn(_ message: String)

    func log(_ level: Level, _ message: String)
}

public class RDLogger: ILogger {

    public let name: String

    init(_ name: String) {
        self.name = name
    }

    public func debug(_ message: String) {
        log(.debug, message)
    }

    public func error(_ message: String) {
        log(.error, message)
    }

    public func fatal(_ message: String) {
        log(.fatal, message)
    }

    public func info(_ message: String) {
        log(.info, message)
    }

    public func trace(_ message: String) {
        log(.trace, message)
    }

    public func warn(_ message: String) {
        log(.warn, message)
    }

    public func log(_ level: Level, _ message: String) {
        let cAddress = makeCString(from: "127.0.0.1")
        let cMessage = makeCString(from: message)
        rd_send_to(cAddress, 7778, cMessage)
    }

    // TODO: Move to a common place.
    //
    func makeCString(from str: String) -> UnsafeMutablePointer<Int8> {
        let count = str.utf8.count + 1
        let result = UnsafeMutablePointer<Int8>.allocate(capacity: count)
        str.withCString { (baseAddress) in
            result.initialize(from: baseAddress, count: count)
        }
        return result
    }
}
