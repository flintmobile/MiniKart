//
//  CheckoutBar.swift
//  MiniKart
//
//  Created by PC on 9/26/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit
import ASCFlatUIColor

class CheckoutBar: UIView {
  override init(frame: CGRect) {
    super.init(frame: frame)
    initialize()
  }
  
  required init?(coder aDecoder: NSCoder) {
    super.init(coder: aDecoder)
    initialize()
  }
  
  func initialize() {
    addSubview(cartImageBackground)
    addSubview(cartImageView)
    addSubview(messageLabel)
    addSubview(detailLabel)
  }
  
  override func layoutSubviews() {
    super.layoutSubviews()
    cartImageView.frame = cartImageViewFrame()
    cartImageBackground.frame = CGRectInset(cartImageView.frame, -5, -5)
    cartImageBackground.round()
    messageLabel.frame = messageLabelFrame(cartImageView.frame)
    detailLabel.frame = detailLabelFrame(messageLabel.frame)
  }
  
  // MARK: - UI Elelements
  
  lazy var cartImageView: UIImageView = {
    let cartImage = UIImage(named: "CartIcon")
    let _cartImageView = UIImageView(image: cartImage)
    _cartImageView.contentMode = .ScaleAspectFit
    return _cartImageView
    }()
  
  func cartImageViewFrame() -> CGRect {
    let x: CGFloat = 12
    let y: CGFloat = 12
    let height = self.bounds.size.height - 2*y
    let width = height
    
    return CGRectMake(x, y, width, height)
  }
  
  lazy var cartImageBackground: UIView = {
    let _cartImageBackground = UIView(frame: CGRectZero)
    _cartImageBackground.backgroundColor = ASCFlatUIColor.turquoiseColor()
    return _cartImageBackground
    }()
  
  lazy var messageLabel: UILabel = {
    let _messageLabel = UILabel(frame: CGRectZero)
    _messageLabel.font = UIFont(name: "Avenir", size: 18)
    _messageLabel.textColor = UIColor.whiteColor()
    _messageLabel.numberOfLines = 1
    return _messageLabel
    }()
  
  func messageLabelFrame(imageViewFrame: CGRect) -> CGRect {
    let x = CGRectGetMaxX(imageViewFrame) + 5
    let y = CGRectGetMinY(imageViewFrame)
    let width = self.bounds.size.width - x
    let height = messageLabel.sizeThatFits(CGSizeMake(width, CGFloat(MAXFLOAT))).height
    
    return CGRectMake(x, y, width, height)
  }
  
  lazy var detailLabel: UILabel = {
    let _detailLabel = UILabel(frame: CGRectZero)
    _detailLabel.font = UIFont(name: "Avenir", size: 12)
    _detailLabel.textColor = UIColor.whiteColor()
    _detailLabel.numberOfLines = 0
    return _detailLabel
    }()
  
  func detailLabelFrame(messageLabelFrame: CGRect) -> CGRect {
    let x = CGRectGetMinX(messageLabelFrame)
    let y = CGRectGetMaxY(messageLabelFrame) + 3
    let width = CGRectGetWidth(messageLabelFrame)
    let height = detailLabel.sizeThatFits(CGSizeMake(width, CGFloat(MAXFLOAT))).height
    
    return CGRectMake(x, y, width, height)
  }
}
