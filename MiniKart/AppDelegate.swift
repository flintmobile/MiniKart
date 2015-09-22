//
//  AppDelegate.swift
//  MiniKart
//
//  Created by PC on 9/21/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit
import FlintConnectSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, UISplitViewControllerDelegate {

  var window: UIWindow?


  func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
    // Override point for customization after application launch.
    let splitViewController = self.window!.rootViewController as! UISplitViewController
    let navigationController = splitViewController.viewControllers[splitViewController.viewControllers.count-1] as! UINavigationController
    navigationController.topViewController!.navigationItem.leftBarButtonItem = splitViewController.displayModeButtonItem()
    splitViewController.delegate = self
    
    FlintAPIConfig.sharedInstance().APIKey = "4d72de8c70d3ba2e0fef18bd6231bdb7"
    FlintAPIConfig.sharedInstance().environment = .EnvironmentStaging
    FlintAPIConfig.sharedInstance().username = "test0001@mailinator.com"
    FlintAPIConfig.sharedInstance().password = "T3st1ng1"
    FlintAPIConfig.sharedInstance().logLevel = .APILogLevelDebug
    
    FlintService.sharedInstance().startServiceWithCompletion {
      status, userInfo -> Void in
      
      if let serviceError = userInfo[FlintServiceErrorKey] {
        print("!!! Service error: \(serviceError)")
      }
    }
    
    return true
  }

  // MARK: - Split view

  func splitViewController(splitViewController: UISplitViewController, collapseSecondaryViewController secondaryViewController:UIViewController, ontoPrimaryViewController primaryViewController:UIViewController) -> Bool {
      guard let secondaryAsNavController = secondaryViewController as? UINavigationController else { return false }
      guard let topAsDetailController = secondaryAsNavController.topViewController as? DetailViewController else { return false }
      if topAsDetailController.detailItem == nil {
          // Return true to indicate that we have handled the collapse by doing nothing; the secondary controller will be discarded.
          return true
      }
      return false
  }

}

