//
//  AddItemViewController.swift
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit
import TOCropViewController
import ASCFlatUIColor

class AddItemViewController: UIViewController {
  
  @IBOutlet weak var logoImageView: UIImageView!
  @IBOutlet weak var nameTextField: LineTextField!
  @IBOutlet weak var priceTextField: LineTextField!
  @IBOutlet weak var taxSwitch: UISwitch!
  @IBOutlet weak var taxLabel: UILabel!
  @IBOutlet weak var addLogoLabel: UILabel!
  @IBOutlet weak var cancelButton: UIButton!

  weak var cropViewHolder: MKACropViewController?
  var delegate: AddItemViewControllerDelegate?
  
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
    self.contentSizeInPopup = CGSizeMake(310, 230)
    
    if UIDevice.isIpad() {
      self.contentSizeInPopup = CGSizeMake(420, 230)
    }
  }
  
  override func viewDidLoad() {
    super.viewDidLoad()
    logoImageView.round()
    cancelButton.setTitleColor(UIColor.redColor(), forState: .Normal)
    taxLabel.textColor = ASCFlatUIColor.turquoiseColor()
  }
  
  // MARK: - Interaction
  
  @IBAction func handleAddLogoButtonTapped(sender: AnyObject) {
    openPhotoAlbum()
  }
  
  @IBAction func handleAddButtonTapped(sender: AnyObject) {
    let menuItem = MenuItem()
    menuItem.logo = logoImageView.image
    menuItem.name = nameTextField.text
    menuItem.price = priceTextField.floatValue()
    menuItem.taxable = taxSwitch.on
    
    delegate?.addItemViewController(self, didAddMenuItem: menuItem)
    self.popupController?.dismiss()
  }
  
  @IBAction func handleCancelButtonTapped(sender: AnyObject) {
    self.popupController?.dismiss()
  }

  // MARK: - Image Handling
  
  func openPhotoAlbum() {
    let imagePickerController = UIImagePickerController()
    imagePickerController.sourceType = .PhotoLibrary
    imagePickerController.allowsEditing = false
    imagePickerController.delegate = self
    
    presentViewController(imagePickerController, animated: true, completion: nil)
  }
}

// MARK: - Extensions

extension AddItemViewController: UIImagePickerControllerDelegate {

  func imagePickerController(picker: UIImagePickerController, didFinishPickingImage image: UIImage, editingInfo: [String : AnyObject]?) {
    
    picker.dismissViewControllerAnimated(true) {
      let cropViewController = MKACropViewController(image: image)
      cropViewController.delegate = self
      self.cropViewHolder = cropViewController
      
      self.presentViewController(cropViewController, animated: true) {
        cropViewController.toolbar.clampButton.enabled = false
        cropViewController.toolbar.resetButtonTapped = { [unowned self] in
          self.cropViewHolder?.cropView.resetLayoutToDefaultAnimated(true);
          self.cropViewHolder?.cropView.setAspectLockEnabledWithAspectRatio(CGSizeMake(1, 1), animated: true)
          self.cropViewHolder?.toolbar.clampButtonGlowing = false;
        }
        
        cropViewController.cropView.setAspectLockEnabledWithAspectRatio(CGSizeMake(1, 1), animated: true)
      }
    }
  }
  
  func imagePickerControllerDidCancel(picker: UIImagePickerController) {
    picker.dismissViewControllerAnimated(true, completion: nil)
  }
}

extension AddItemViewController: UINavigationControllerDelegate {

}

extension AddItemViewController: TOCropViewControllerDelegate {
  
  func cropViewController(cropViewController: TOCropViewController!, didCropToImage image: UIImage!, withRect cropRect: CGRect, angle: Int) {
    logoImageView.image = image
    addLogoLabel.text = "Tap to change\nitem logo"
    cropViewController.dismissViewControllerAnimated(true, completion: nil)
  }
  
  func cropViewController(cropViewController: TOCropViewController!, didFinishCancelled cancelled: Bool) {
    if cancelled {
      cropViewController.dismissViewControllerAnimated(true, completion: nil)
    }
  }
}

// MARK: - Protocol

protocol AddItemViewControllerDelegate {
  func addItemViewController(itemViewController: AddItemViewController, didAddMenuItem item: MenuItem);
  func addItemViewController(itemViewController: AddItemViewController, didCancel cancel: Bool);
}