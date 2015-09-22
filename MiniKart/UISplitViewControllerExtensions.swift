//
//  UISplitViewControllerExtensions.swift
//  MiniKart
//
//  Created by PC on 9/22/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import Foundation
import UIKit

extension UISplitViewController {
  func toggleMasterView() {
    let barButtonItem = self.displayModeButtonItem()
    UIApplication.sharedApplication().sendAction(barButtonItem.action, to: barButtonItem.target, from: nil, forEvent: nil)
  }
}