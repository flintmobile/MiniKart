//
//  ItemProvider.swift
//  MiniKart
//
//  Created by PC on 9/25/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import Foundation

class ItemProvider {
  class func preloadedItems() -> [MenuItem] {
    var items = [MenuItem]()
    
    for index in 1...5 {
      let menuItem = MenuItem()
      menuItem.logo = UIImage(named: "Preload\(index)")
      menuItem.name = nameForIndex(index)
      menuItem.price = Float(index) * 2.99
      
      items.append(menuItem)
    }
    
    return items
  }
  
  class func nameForIndex(index: Int) -> String? {
    switch index {
    case 1:
      return "Single M."
    case 2:
      return "Effect M."
    case 3:
      return "Acoustic"
    case 4:
      return "Electric"
    case 5:
      return "Gold Ed"
    default:
      return nil
    }
  }
}