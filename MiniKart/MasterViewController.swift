//
//  MasterViewController.swift
//  MiniKart
//
//  Created by PC on 9/21/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit
import FlintConnectSDK
import SWTableViewCell
import ASCFlatUIColor

class MasterViewController: UITableViewController {

  var detailViewController: DetailViewController? = nil
  var menuItems = [MenuItem]()
  var orderItems = [FlintOrderItem]()
  var checkoutHidden = false
  weak var lastVisibleCell: MenuItemCell?
  
  override func loadView() {
    super.loadView()
    for item in ItemProvider.preloadedItems() {
      menuItems.append(item)
    }
  
    tableView.backgroundColor = ASCFlatUIColor.turquoiseColor()
    toolbarItems = [negativeSpacer,checkoutBarItem]
  }
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    let payButton = UIBarButtonItem(title: "Clear", style: .Plain, target: self, action: "handleClearButtonTapped:")
    let addButton = UIBarButtonItem(barButtonSystemItem: .Add, target: self, action: "insertNewObject:")
    self.navigationItem.rightBarButtonItem = addButton
    self.navigationItem.leftBarButtonItem = payButton
    
    if let split = self.splitViewController {
        let controllers = split.viewControllers
        self.detailViewController = (controllers[controllers.count-1] as! UINavigationController).topViewController as? DetailViewController
    }
    
    validateCart()
  }

  override func viewWillAppear(animated: Bool) {
    self.clearsSelectionOnViewWillAppear = self.splitViewController!.collapsed
    super.viewWillAppear(animated)
  }
  
  override func viewWillLayoutSubviews() {
    super.viewWillLayoutSubviews()
    
    if !checkoutHidden {
      if let frame = navigationController?.toolbar.frame {
        let toolbarHeight: CGFloat = 70
        var adjustedFrame = frame
        adjustedFrame.size.height = toolbarHeight
        adjustedFrame.origin.y = view.bounds.size.height - toolbarHeight
        navigationController?.toolbar.frame = adjustedFrame
      }
      
      if let bounds = navigationController?.toolbar.bounds {
        checkoutBar.frame = bounds
      }
    }
  }
  
  // MARK: - Segues

  override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
    if segue.identifier == "showDetail" {
        if let indexPath = self.tableView.indexPathForSelectedRow {
            let menuItem = menuItems[indexPath.row]
            let controller = (segue.destinationViewController as! UINavigationController).topViewController as! DetailViewController
            controller.detailItem = menuItem
            controller.navigationItem.leftBarButtonItem = self.splitViewController?.displayModeButtonItem()
            controller.navigationItem.leftItemsSupplementBackButton = true
        }
    }
  }

  // MARK: - Table View

  override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
    return 1
  }

  override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    return menuItems.count
  }

  override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
    let cell = tableView.dequeueReusableCellWithIdentifier("Cell", forIndexPath: indexPath) as! MenuItemCell

    let menuItem = menuItems[indexPath.row]
    
    // data
    cell.index = indexPath.row
    cell.productImageView.image = menuItem.logo
    cell.nameLabel.text = menuItem.name
    if let price = menuItem.price?.toString(0.2) {
      cell.priceLabel.text = "$\(price)"
    } else {
      cell.priceLabel.text = "Free"
    }
    cell.quantityLabel.text = "x \(menuItem.orderCount)"
    
    //format
    cell.productImageView.round()
    let textColor = UIColor.whiteColor()
    cell.nameLabel.textColor = textColor
    cell.priceLabel.textColor = textColor
    cell.quantityLabel.textColor = textColor
    cell.backgroundColor = UIColor.clearColor()
    if menuItem.orderCount > 0 {
      cell.quantityLabel.textColor = ASCFlatUIColor.wetAsphaltColor()
    }
    
    // action
    cell.rightUtilityButtons = rightActionCells()
    cell.delegate = self
    
    return cell
  }
  
  func rightActionCells() -> [AnyObject] {
    let actions: NSMutableArray = NSMutableArray()
    actions.sw_addUtilityButtonWithColor(ASCFlatUIColor.peterRiverColor(), title: "Add")
    actions.sw_addUtilityButtonWithColor(ASCFlatUIColor.alizarinColor(), title: "Remove")
    
    return actions as Array
  }
  
  override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) -> Bool {
    return true
  }

  override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
    if editingStyle == .Delete {
        menuItems.removeAtIndex(indexPath.row)
        tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Fade)
    } else if editingStyle == .Insert {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view.
    }
  }
  
  // MARK : - Actions
  
  func insertNewObject(sender: AnyObject) {
    guard let addItemViewController = UIStoryboard.viewControllerWithID("AddItemViewControllerID") as? AddItemViewController else {
      return
    }
    
    addItemViewController.delegate = self
    
    let popupController = MKPopupController(rootViewController: addItemViewController)
    popupController.presentInViewController(splitViewController)
  }
  
  func handleClearButtonTapped(sender: AnyObject) {
    clearCart()
  }
  
  func takePayment(sender: AnyObject) {
    splitViewController?.toggleMasterView()

    if let paymentViewController = FlintUI.paymentViewControllerWithOrderItems(orderItems, delegate: self) {
      let navigationController = UINavigationController(rootViewController: paymentViewController)
      navigationController.modalPresentationStyle = .FormSheet
      splitViewController?.presentViewController(navigationController, animated: true) {
        self.toggleCheckoutBar(false)
        
        if let _lastVisibleCell = self.lastVisibleCell {
          _lastVisibleCell.hideUtilityButtonsAnimated(true)
        }
      }
    }
  }
  
  // MARK: - Checkout Bar
  
  lazy var checkoutBar: CheckoutBar = {
    let _checkoutBar = CheckoutBar(frame: CGRectMake(0, 0, 200, 200))
    _checkoutBar.backgroundColor = ASCFlatUIColor.emeraldColor()
    _checkoutBar.userInteractionEnabled = true
    
    let tapGesture = UITapGestureRecognizer(target: self, action: "takePayment:")
    _checkoutBar.addGestureRecognizer(tapGesture)
    return _checkoutBar
    }()
  
  lazy var checkoutBarItem: UIBarButtonItem = {
    let _checkoutBarItem = UIBarButtonItem(customView: self.checkoutBar)
    return _checkoutBarItem
    }()
  
  lazy var negativeSpacer: UIBarButtonItem = {
    let _negativeSpacer = UIBarButtonItem(barButtonSystemItem: .FixedSpace, target: nil, action: nil)
    _negativeSpacer.width = -16
    return _negativeSpacer
  }()
  
  func toggleCheckoutBar(visible: Bool) {
    checkoutHidden = !visible
    if checkoutHidden {
      UIView.animateWithDuration(0.3, animations: {
          navigationController?.toolbar.alpha = 0.0
        }, completion: {
          _ in
          navigationController?.setToolbarHidden(checkoutHidden, animated: false)
      })
    } else {
      navigationController?.setToolbarHidden(checkoutHidden, animated: true)
    }
  }
  
  func validateCart() {
    orderItems.removeAll()
    var totalItem = 0
    var totalPrice: Float = 0
    
    for item in menuItems {
      if item.orderCount > 0 {
        let orderItem = FlintOrderItem()
        orderItem.name = item.name
        orderItem.quantity = item.orderCount
        orderItem.price = item.price
        orderItem.taxAmount = item.taxable ? item.price! * 0.095 : 0
        orderItems.append(orderItem)
        
        totalItem += item.orderCount
        totalPrice += orderItem.total().floatValue
      }
    }
    
    let cartNotEmpty = orderItems.count > 0
    toggleCheckoutBar(cartNotEmpty)
    navigationItem.leftBarButtonItem?.enabled = (cartNotEmpty)
    if cartNotEmpty {
      checkoutBar.setCartItem(totalItem, total:totalPrice)
    }
  }
  
  func clearCart() {
    for item in menuItems {
      item.orderCount = 0
    }
    
    validateCart()
    tableView.reloadData()
  }
}

// MARK: - Extensions

extension MasterViewController: FlintTransactionDelegate {

  func transactionDidCancel(canceledStep: FlintTransactionCancelableStep, autoTimeout autoTimeOut: Bool) {
    splitViewController?.dismissViewControllerAnimated(true) {
      self.validateCart()
      self.splitViewController?.toggleMasterView()
    }
  }
  
  func transactionDidComplete(userInfo: [NSObject : AnyObject]!) {
    splitViewController?.dismissViewControllerAnimated(true) {
      self.clearCart()
      self.splitViewController?.toggleMasterView()
    }
  }
}

extension MasterViewController: AddItemViewControllerDelegate {
  
  func addItemViewController(itemViewController: AddItemViewController, didAddMenuItem item: MenuItem) {
    menuItems.insert(item, atIndex: 0)
    let indexPath = NSIndexPath(forRow: 0, inSection: 0)
    self.tableView.insertRowsAtIndexPaths([indexPath], withRowAnimation: .Automatic)
  }
  
  func addItemViewController(itemViewController: AddItemViewController, didCancel cancel: Bool) {
    
  }
}

extension MasterViewController: SWTableViewCellDelegate {
  
  func swipeableTableViewCell(cell: SWTableViewCell!, didTriggerRightUtilityButtonWithIndex index: Int) {
    let menuCell = cell as? MenuItemCell
    
    if let menuIndex = menuCell?.index {
      let menuItem = menuItems[menuIndex]
      if index == 0 {
        menuItem.increaseCount()
      } else if index == 1 {
        menuItem.decreaseCount()
      }
      
      menuCell?.quantityLabel.text = "x \(menuItem.orderCount)"
      if menuItem.orderCount > 0 {
        menuCell?.quantityLabel.textColor = ASCFlatUIColor.wetAsphaltColor()
      } else {
        menuCell?.quantityLabel.textColor = UIColor.whiteColor()
      }
      
      validateCart()
    }
  }
  
  func swipeableTableViewCell(cell: SWTableViewCell!, scrollingToState state: SWCellState) {
    if state == .CellStateRight {
      if let _lastVisibleCell = lastVisibleCell {
        _lastVisibleCell.hideUtilityButtonsAnimated(true)
      }
      
      lastVisibleCell = cell as? MenuItemCell
    } else if state == .CellStateCenter {
      lastVisibleCell = nil
    }
  }
}
