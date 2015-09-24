//
//  AddItemViewController.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit

class AddItemViewController: UIViewController {
  
  @IBOutlet weak var logoImageView: UIImageView!
  var photoActionController: UIAlertController?
  
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
  
  @IBAction func handleAddLogoButtonTapped(sender: AnyObject) {
    let actionController = UIAlertController(title: nil, message: nil, preferredStyle: .ActionSheet)
    let photoAction = UIAlertAction(title: "Photo", style: .Default) { _ in
      self.openPhotoAlbum()
    }
    let cameraAction = UIAlertAction(title: "Camera", style: .Default) { _ in
      self.showCamera()
    }
    
    actionController.addAction(photoAction)
    actionController.addAction(cameraAction)
    photoActionController = actionController
    presentViewController(actionController, animated: true, completion: nil)
  }
  
  // MARK: Image Handling
  
  func showCamera() {
    if let _photoActionController = photoActionController {
      _photoActionController.dismissViewControllerAnimated(true, completion: nil)
    }
  }
  
  func openPhotoAlbum() {
    if let _photoActionController = photoActionController {
      _photoActionController.dismissViewControllerAnimated(true, completion: nil)
    }
  }
}