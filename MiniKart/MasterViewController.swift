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
  var orderItems = [MenuItem]()
  var checkoutHidden = false
  
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
    
    let payButton = UIBarButtonItem(title: "Pay", style: .Plain, target: self, action: "takePayment:")
    let addButton = UIBarButtonItem(barButtonSystemItem: .Add, target: self, action: "insertNewObject:")
    self.navigationItem.rightBarButtonItem = addButton
    self.navigationItem.leftBarButtonItem = payButton
    
    if let split = self.splitViewController {
        let controllers = split.viewControllers
        self.detailViewController = (controllers[controllers.count-1] as! UINavigationController).topViewController as? DetailViewController
    }
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
  
  func takePayment(sender: AnyObject) {
//    orderItems.removeAll()
//    splitViewController?.toggleMasterView()
//
//    // create mock order
//    let orderItem = FlintOrderItem()
//    orderItem.name = "Preset Item"
//    orderItem.quantity = 1
//    orderItem.price = 15
//    orderItem.taxAmount = 3
//    orderItems.append(orderItem)
//
//    if let paymentViewController = FlintUI.paymentViewControllerWithOrderItems(orderItems, delegate: self) {
//      let navigationController = UINavigationController(rootViewController: paymentViewController)
//      navigationController.modalPresentationStyle = .FormSheet
//      splitViewController?.presentViewController(navigationController, animated: true, completion: nil)
//    }
  }
  
  // MARK: - Checkout Bar
  
  lazy var checkoutBar: CheckoutBar = {
    let _checkoutBar = CheckoutBar(frame: CGRectMake(0, 0, 200, 200))
    _checkoutBar.backgroundColor = ASCFlatUIColor.pumpkinColor()
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
    navigationController?.setToolbarHidden(checkoutHidden, animated: true)
  }
  
  func validateCart() {
    var shouldShowCart = false
    
    for item in menuItems {
      if item.orderCount > 0 {
        shouldShowCart = true
        break
      }
    }
    
    toggleCheckoutBar(shouldShowCart)
  }
}

// MARK: - Extensions

extension MasterViewController: FlintTransactionDelegate {

  func transactionDidCancel(canceledStep: FlintTransactionCancelableStep, autoTimeout autoTimeOut: Bool) {
    splitViewController?.dismissViewControllerAnimated(true, completion: nil)
  }
  
  func transactionDidComplete(userInfo: [NSObject : AnyObject]!) {
    FlintUI.restartPaymentFlowWithOrderItems(orderItems, delegate: self)
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
    }
  }
  
  func swipeableTableViewCell(cell: SWTableViewCell!, scrollingToState state: SWCellState) {
    if state == .CellStateRight {
      toggleCheckoutBar(false)
    } else if state ==  .CellStateCenter {
      toggleCheckoutBar(true)
    }
  }
}
