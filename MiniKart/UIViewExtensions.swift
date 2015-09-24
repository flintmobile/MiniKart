//
//  UIViewExtensions.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit

extension UIView {
  func round() {
    let frame = CGRectInset(self.bounds, 0.5, 0.5)
    
    let maskPath = UIBezierPath(ovalInRect: frame)
    let maskLayer = CAShapeLayer()
    maskLayer.frame = self.bounds
    maskLayer.path = maskPath.CGPath
    
    self.layer.mask = maskLayer
  }
}
