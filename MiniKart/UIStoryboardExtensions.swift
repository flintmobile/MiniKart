//
//  UIStoryboardExtensions.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit

extension UIStoryboard {
  class func viewControllerWithID(storyboardID: String) -> UIViewController? {
    let mainStoryboard = UIStoryboard(name: "Main", bundle: nil)
    let viewController = mainStoryboard.instantiateViewControllerWithIdentifier(storyboardID)
    return viewController
  }
}