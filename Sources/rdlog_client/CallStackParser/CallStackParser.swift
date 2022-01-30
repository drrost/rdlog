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
        let components = replaced.split(separator: " ")
        if components.count >= 4 {
            guard var itemDetails = try? parseMangledSwiftSymbol(String(components[3])).description else {
                return nil
            }
            itemDetails = itemDetails.collapseSpaces()
            let packageComponent = String(itemDetails.split(separator: " ").first!)
            let classAndMethod = packageComponent.split(separator: ".")
            let numberOfComponents = classAndMethod.count
            if numberOfComponents >= 2 {
                let method = CallStackAnalyser.cleanMethod(String(classAndMethod[numberOfComponents - 1]))
                return StackItem(
                    class: String(classAndMethod[numberOfComponents - 2]),
                    method: method
                )
            }
        }
        return nil
    }

    private static func stackItem(for index: Int) -> StackItem? {
        let stackSymbols = Thread.callStackSymbols
        if (stackSymbols.count >= index + 1) {
            return CallStackAnalyser.stackItem(for: stackSymbols[index])
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
}
