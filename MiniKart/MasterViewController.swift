//
//  MasterViewController.swift
//  MiniKart
//
//  Created by PC on 9/21/15.
//  Copyright © 2015 Flint. All rights reserved.
//

import UIKit
import FlintConnectSDK
import SESlideTableViewCell

class MasterViewController: UITableViewController {

  var detailViewController: DetailViewController? = nil
  var objects = [AnyObject]()
  var orderItems = [FlintOrderItem]()

  override func loadView() {
    super.loadView()
    
    self.tableView.rowHeight = 60
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

  // MARK: - Segues

  override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
    if segue.identifier == "showDetail" {
        if let indexPath = self.tableView.indexPathForSelectedRow {
            let object = objects[indexPath.row] as! NSDate
            let controller = (segue.destinationViewController as! UINavigationController).topViewController as! DetailViewController
            controller.detailItem = object
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
    return objects.count
  }

  override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
    let cell = tableView.dequeueReusableCellWithIdentifier("Cell", forIndexPath: indexPath) as! SESlideTableViewCell

    let object = objects[indexPath.row] as! NSDate
    cell.textLabel!.text = object.description
    cell.addLeftButtonWithText("  +   ", textColor: UIColor.whiteColor(), backgroundColor: UIColor.greenColor())
    cell.addLeftButtonWithText(" -    ", textColor: UIColor.whiteColor(), backgroundColor: UIColor.redColor())
    return cell
  }

  override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) -> Bool {
    return true
  }

  override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
    if editingStyle == .Delete {
        objects.removeAtIndex(indexPath.row)
        tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Fade)
    } else if editingStyle == .Insert {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view.
    }
  }
  
  // MARK : - Actions
  
  func insertNewObject(sender: AnyObject) {
    objects.insert(NSDate(), atIndex: 0)
    let indexPath = NSIndexPath(forRow: 0, inSection: 0)
    self.tableView.insertRowsAtIndexPaths([indexPath], withRowAnimation: .Automatic)
  }
  
  func takePayment(sender: AnyObject) {
    orderItems.removeAll()
    splitViewController?.toggleMasterView()

    // create mock order
    let orderItem = FlintOrderItem()
    orderItem.name = "Preset Item"
    orderItem.quantity = 1
    orderItem.price = 15
    orderItem.taxAmount = 3
    orderItems.append(orderItem)

    if let paymentViewController = FlintUI.paymentViewControllerWithOrderItems(orderItems, delegate: self) {
      let navigationController = UINavigationController(rootViewController: paymentViewController)
      navigationController.modalPresentationStyle = .FormSheet
      splitViewController?.presentViewController(navigationController, animated: true, completion: nil)
    }
  }
}



extension MasterViewController: FlintTransactionDelegate {

  func transactionDidCancel(canceledStep: FlintTransactionCancelableStep, autoTimeout autoTimeOut: Bool) {
    splitViewController?.dismissViewControllerAnimated(true, completion: nil)
  }
  
  func transactionDidComplete(userInfo: [NSObject : AnyObject]!) {
    FlintUI.restartPaymentFlowWithOrderItems(orderItems, delegate: self)
  }
}
