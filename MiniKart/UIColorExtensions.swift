//
//  UIColorExtensions.swift
//  MiniKart
//
//  Created by PC on 9/29/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit
import ASCFlatUIColor

extension UIColor {

  class func primaryColor() -> UIColor {
    return UIColor(red: 242/255, green: 153/255, blue: 44/255, alpha: 1)
  }
  
  class func secondaryColor() -> UIColor {
    return ASCFlatUIColor.peterRiverColor()
  }
  
  class func invertColor() -> UIColor {
    return UIColor.whiteColor()
  }
}