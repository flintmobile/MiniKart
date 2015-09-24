//
//  LineTextField.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit

@IBDesignable

class LineTextField: UITextField {
  @IBInspectable var lineWidth: CGFloat = 0.5 {
    didSet {
      setNeedsDisplay()
    }
  }
  
  @IBInspectable var lineColor = UIColor.lightGrayColor() {
    didSet {
      setNeedsDisplay()
    }
  }
  
  override func drawRect(rect: CGRect) {
    let context = UIGraphicsGetCurrentContext();
    CGContextSetStrokeColorWithColor(context, self.lineColor.CGColor);
    CGContextSetLineWidth(context, lineWidth);
    CGContextBeginPath(context);
    CGContextMoveToPoint(context, self.bounds.origin.x, CGRectGetHeight(self.bounds) - lineWidth);
    CGContextAddLineToPoint(context, self.bounds.origin.x + CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds) - lineWidth);
    CGContextClosePath(context);
    CGContextStrokePath(context);
  }
}