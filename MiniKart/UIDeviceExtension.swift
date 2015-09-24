//
//  UIDeviceExtension.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import Foundation

extension UIDevice {
  class func isIpad() -> Bool {
    return UIDevice.currentDevice().userInterfaceIdiom == .Pad
  }
}