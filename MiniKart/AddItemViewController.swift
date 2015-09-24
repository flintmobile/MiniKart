//
//  AddItemViewController.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit

class AddItemViewController: UIViewController {
  required init?(coder aDecoder: NSCoder) {
    super.init(coder: aDecoder)
    initialize()
  }
  
  init() {
    super.init(nibName: nil, bundle: nil)
    initialize()
  }
  
  func initialize() {
    self.title = "Add Item"
    self.contentSizeInPopup = CGSizeMake(320, 200)
    
    if UIDevice.isIpad() {
      self.contentSizeInPopup = CGSizeMake(420, 300)
    }
  }
}