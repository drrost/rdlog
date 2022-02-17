//
//  String+Extensions.swift
//
//
//  Created by Rostyslav Druzhchenko on 17.02.2022.
//

import Foundation

// TODO: Move to a common place.
//
extension String {

    var cString: UnsafeMutablePointer<Int8> {
        let count = utf8.count + 1
        let result = UnsafeMutablePointer<Int8>.allocate(capacity: count)
        withCString { (baseAddress) in
            result.initialize(from: baseAddress, count: count)
        }
        return result
    }
}
