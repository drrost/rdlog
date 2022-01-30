//
//  CallStackParser.swift
//  Based on CallStackAnalyser.swift created by Mitch Robertson on 2016-05-20.
//
//  Created by Georgiy Malyukov on 2018-05-27.
//  Copyright © Mitch Robertson, Georgiy Malyukov. All rights reserved.
//

import Foundation

public struct StackItem {
    let `class`: String
    let method: String
}

class CallStackParser {

    private static func cleanMethod(_ method: (String)) -> String {
        var result = method
        if result.count > 1 {
            let firstChar: Character = result[result.startIndex]
            if firstChar == "(" {
                result = String(result[result.startIndex...])
            }
        }
        if !result.hasSuffix(")") {
            result = result + ")"
        }
        return result
    }

    static func stackItem(for stackSymbol: String, includeImmediateParentClass: Bool? = false) -> StackItem? {
        let replaced = stackSymbol.replacingOccurrences(of: "\\s+", with: " ", options: .regularExpression, range: nil)
        let components = replaced.split(separator: " ")
        if (components.count >= 4) {
            guard var packageClassAndMethodStr = try? parseMangledSwiftSymbol(String(components[3])).description else {
                return nil
            }
            packageClassAndMethodStr = packageClassAndMethodStr.replacingOccurrences(
                of: "\\s+",
                with: " ",
                options: .regularExpression,
                range: nil
            )
            let packageComponent = String(packageClassAndMethodStr.split(separator: " ").first!)
            let packageClassAndMethod = packageComponent.split(separator: ".")
            let numberOfComponents = packageClassAndMethod.count
            if (numberOfComponents >= 2) {
                let method = CallStackParser.cleanMethod(String(packageClassAndMethod[numberOfComponents - 1]))
                if includeImmediateParentClass != nil {
                    if (includeImmediateParentClass == true && numberOfComponents >= 4) {
                        return StackItem(
                            class: String(packageClassAndMethod[numberOfComponents - 3] + "." + packageClassAndMethod[numberOfComponents - 2]),
                            method: method
                        )
                    }
                }
                return StackItem(
                    class: String(packageClassAndMethod[numberOfComponents - 2]),
                    method: method
                )
            }
        }
        return nil
    }

    private static func stackItem(for index: Int) -> StackItem? {
        let stackSymbols = Thread.callStackSymbols
        if (stackSymbols.count >= index + 1) {
            return CallStackParser.stackItem(for: stackSymbols[index])
        }
        return nil
    }

    static func getCallingClassAndMethodInScope() -> StackItem? {
        stackItem(for: 3)
    }

    static func getThisClassAndMethodInScope() -> StackItem? {
        stackItem(for: 2)
    }
}

