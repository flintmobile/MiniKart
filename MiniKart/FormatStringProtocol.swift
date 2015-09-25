//
//  FormatStringProtocol.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import Foundation

protocol FormatStringProtocol {
  
  func toString(formatPrecision: Float) -> String
}

extension Float: FormatStringProtocol {
  
  func toString(formatPrecision: Float) -> String {
    let format = "%\(formatPrecision)f"
    return NSString(format: format, self) as String
  }
}