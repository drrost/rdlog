//
//  RDLogManager.swift
//
//
//  Created by Rostyslav Druzhchenko on 30.01.2022.
//

import Foundation

public final class RDLogManager {

    public static func getLogger() -> RDLogger {
        let item = CallStackAnalyser.getCalling()
        return RDLogger(item!.class)
    }
}
