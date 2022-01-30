//
//  CallStackParser.swift
//  Based on CallStackAnalyser.swift created by Mitch Robertson on 2016-05-20.
//
//  Created by Georgiy Malyukov on 2018-05-27.
//  Copyright © Mitch Robertson, Georgiy Malyukov. All rights reserved.
//

import Foundation

class CallStackParser {

    private static func cleanMethod(method: (String)) -> String {
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

    static func classAndMethodForStackSymbol(_ stackSymbol: String, includeImmediateParentClass: Bool? = false) -> (String, String)? {
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
                let method = CallStackParser.cleanMethod(method: String(packageClassAndMethod[numberOfComponents - 1]))
                if includeImmediateParentClass != nil {
                    if (includeImmediateParentClass == true && numberOfComponents >= 4) {
                        return (packageClassAndMethod[numberOfComponents - 3] + "." + packageClassAndMethod[numberOfComponents - 2], method)
                    }
                }
                return (String(packageClassAndMethod[numberOfComponents - 2]), method)
            }
        }
        return nil
    }

    static func getCallingClassAndMethodInScope(_ includeImmediateParentClass: Bool? = false) -> (String, String)? {
        let stackSymbols = Thread.callStackSymbols
        if (stackSymbols.count >= 3) {
            return CallStackParser.classAndMethodForStackSymbol(stackSymbols[2], includeImmediateParentClass: includeImmediateParentClass)
        }
        return nil
    }

    static func getThisClassAndMethodInScope(includeImmediateParentClass: Bool? = false) -> (String, String)? {
        let stackSymbols = Thread.callStackSymbols
        if (stackSymbols.count >= 2) {
            return CallStackParser.classAndMethodForStackSymbol(stackSymbols[1], includeImmediateParentClass: includeImmediateParentClass)
        }
        return nil
    }
}

