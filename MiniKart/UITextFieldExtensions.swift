//
//  UITextFieldExtensions.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit

extension UITextField {
  func floatValue() -> Float? {
    guard let textValue = self.text where !textValue.isEmpty else {
      return nil;
    }
    
    return Float(textValue)
  }
}
