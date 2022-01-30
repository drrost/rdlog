//
//  RDLogManager.swift
//
//
//  Created by Rostyslav Druzhchenko on 30.01.2022.
//

import Foundation

public final class RDLogManager {

    static func getLogger() -> RDLogger {
        let a = CallStackParser.getCallingClassAndMethodInScope()
        print(a)
        return RDLogger("")
    }
}
