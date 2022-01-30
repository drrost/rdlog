//
//  CallStackAnalyser.swift
//

import Foundation

public struct StackItem {
    let `class`: String
    let method: String
}

class CallStackAnalyser {

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

    static func stackItem(for stackSymbol: String) -> StackItem? {
        let replaced = stackSymbol.collapseSpaces()
        let components = replaced.split(by: " ")
        if components.count >= 4 {
            guard var itemDetails = try? parseMangledSwiftSymbol(components[3]).description else {
                return nil
            }
            itemDetails = itemDetails.collapseSpaces()
            let packageComponent = itemDetails.split(by: " ").first!
            let classAndMethod = packageComponent.split(by: ".")
            let count = classAndMethod.count
            if count >= 2 {
                return StackItem(
                    class: classAndMethod[count - 2],
                    method: cleanMethod(classAndMethod[count - 1])
                )
            }
        }
        return nil
    }

    private static func stackItem(for index: Int) -> StackItem? {
        let stackSymbols = Thread.callStackSymbols
        if (stackSymbols.count >= index + 1) {
            return stackItem(for: stackSymbols[index])
        }
        return nil
    }

    static func getCalling() -> StackItem? {
        stackItem(for: 3)
    }

    static func getThis() -> StackItem? {
        stackItem(for: 2)
    }
}

private extension String {

    func collapseSpaces() -> String {
        replacingOccurrences(
            of: "\\s+", with: " ", options: .regularExpression, range: nil
        )
    }

    func split(by: Character) -> [String] {
        split(separator: by).map { String($0) }
    }
}
