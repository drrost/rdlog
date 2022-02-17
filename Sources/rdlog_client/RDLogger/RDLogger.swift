//
//  RDLogClient.swift
//
//
//  Created by Rostyslav Druzhchenko on 30.01.2022.
//

import Foundation
import rdlib

public enum Level: Int {
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
        let appName = Bundle.main.infoDictionary!["CFBundleName"] as! String
        let json = "{\"message\":\"\(message)\",\"sender\":\"\(appName)\"," +
            "\"version\":1,\"log_level\": \(level.rawValue)}"
        let cAddress = "127.0.0.1".cString
        let cJson = json.cString
        rd_send_to(cAddress, 7778, cJson)
    }
}
