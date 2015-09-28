//
//  MenuItem.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import Foundation

class MenuItem {
  var logo: UIImage?
  var name: String?
  var price: Float?
  var taxable: Bool = true
  var orderCount: Int = 0

  func increaseCount() {
    orderCount++
  }
  
  func decreaseCount() {
    orderCount--
    if orderCount < 0 {
      orderCount = 0
    }
  }
}