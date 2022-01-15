//
//  ResourceHelper.swift
//  
//
//  Created by Rostyslav Druzhchenko on 15.01.2022.
//

import Foundation

@objc
public class ResourceHelper: NSObject {

    public override init() {}

    @objc
    public func path_for_res() -> UnsafeMutablePointer<CChar> {
        let path = "/usr/local/bin"
        let result = makeCString(from: path)
        return result
    }
}


func makeCString(from str: String) -> UnsafeMutablePointer<Int8> {
    let count = str.utf8.count + 1
    let result = UnsafeMutablePointer<Int8>.allocate(capacity: count)
    str.withCString { (baseAddress) in
        result.initialize(from: baseAddress, count: count)
    }
    return result
}
