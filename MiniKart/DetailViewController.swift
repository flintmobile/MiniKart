//
//  DetailViewController.swift
//  MiniKart
//
//  Created by PC on 9/21/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit

class DetailViewController: UIViewController {

  @IBOutlet weak var collectionView: UICollectionView!
  var collectionViewSize: CGSize?
  
  var detailItem: MenuItem? {
    didSet {
        // Update the view.
        self.configureView()
    }
  }

  func configureView() {
    
  }

  override func viewDidLoad() {
    super.viewDidLoad()
    self.configureView()
  }

  override func viewWillTransitionToSize(size: CGSize, withTransitionCoordinator coordinator: UIViewControllerTransitionCoordinator) {
    super.viewWillTransitionToSize(size, withTransitionCoordinator: coordinator)
    collectionViewSize = size
    let oldFrame = collectionView.frame
    collectionView.frame = CGRectMake(CGRectGetMinX(oldFrame), CGRectGetMinY(oldFrame), size.width, size.height)
    collectionView.collectionViewLayout.invalidateLayout()
  }
}

// MARK: - Extensions

extension DetailViewController : UICollectionViewDelegateFlowLayout, UICollectionViewDataSource {

  func numberOfSectionsInCollectionView(collectionView: UICollectionView) -> Int {
    return 1
  }
  
  func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
    return 20
  }
  
  func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
    let cell = collectionView.dequeueReusableCellWithReuseIdentifier("GalleryCell", forIndexPath: indexPath) as! GalleryCell
    
    cell.imageView.image = UIImage(named: "Gallery\(indexPath.item + 1)")
    return cell
  }
  
  func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAtIndexPath indexPath: NSIndexPath) -> CGSize {
    
    let actualSize: CGSize = collectionView.bounds.size
    
    let width: CGFloat
    let height: CGFloat
    if self.traitCollection.userInterfaceIdiom == .Pad {
      width = actualSize.width / 5
      height = actualSize.height / 4
    } else {
      width = actualSize.width / 2
      height = actualSize.height / 3
    }
    
    return CGSizeMake(width, height)
  }
  
  func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumInteritemSpacingForSectionAtIndex section: Int) -> CGFloat {
    return 0
  }
  
  func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumLineSpacingForSectionAtIndex section: Int) -> CGFloat {
    return 0
  }
}

