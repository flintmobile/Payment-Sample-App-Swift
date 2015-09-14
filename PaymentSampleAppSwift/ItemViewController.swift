//
//  ItemViewController.swift
//  PaymentSampleAppSwift
//
//  Created by PC on 9/9/15.
//  Copyright © 2015 PC. All rights reserved.
//

import UIKit
import FlintConnectSDK

class ItemViewController : UIViewController {
  
  @IBOutlet weak var nameTextField: TextField!
  @IBOutlet weak var priceTextField: TextField!
  @IBOutlet weak var taxTextField: TextField!
  @IBOutlet weak var totalLabel: UILabel!
  
  var orderItems = [FlintOrderItem]()
  var total: Float = 0
  
// MARK: - Life Cycle
  
  override func viewDidLoad() {  
    super.viewDidLoad()
  }
  
// MARK: - Storyboard
  
  @IBAction func handleAddItemTapped(sender: AnyObject) {
    guard let price = priceTextField.floatValue(), name = nameTextField.text where !name.isEmpty else {
      let alertController = UIAlertController(title: "Error", message: "Name and price can't be empty", preferredStyle: .Alert)
      let okButton = UIAlertAction(title: "Ok", style: .Cancel, handler: nil)
      alertController.addAction(okButton)
      
      presentViewController(alertController, animated: true, completion: nil)
      return
    }
    
    /*************************************************************************
    * A FlintOrderItem is the smallest unit of the payment work flow
    * By default, the item type is OrderItemTypeCustomAmount (addition)
    * To implement discount, set the item type to OrderItemTypeCustomDiscount (subtraction),
    * The other item types are for Flint internal usage.
    **************************************************************************/
    let item = FlintOrderItem()
    item.name = name;
    item.quantity = 1
    item.price = price;
    item.taxAmount = taxTextField.floatValue()
    
    orderItems.append(item)
    refreshTotalLabel()
    
    // reset
    nameTextField.text = nil;
    priceTextField.text = nil;
    taxTextField.text = nil;
    dismissKeyboard()
  }
  
  @IBAction func handleResetTapped(sender: AnyObject) {
    orderItems.removeAll()
    refreshTotalLabel()
  }
  
  @IBAction func handleTakePaymentTapped(sender: AnyObject) {
    if total > 0 {
      /******************************************************************************
      * FlintUI is the main entrance into the drop-in payment work flow
      * Configure an array of FlintOrderItem(s) and then
      * either use the convenient method to start the workflow as a modal view
      * or use the view controller method to implement your own navigation stack
      * Implement FlintTransactionDelegate to receive transaction status call back
      ******************************************************************************/
      FlintUI.takePaymentForOrderItems(orderItems, fromViewController: self)
    } else {
      showAlertMessage(NSLocalizedString("Amount to take payment must be greater than 0. Try adding some items", comment: ""))
    }
  }
  
// MARK: - Private
  
  func refreshTotalLabel() {
    total = 0
    for orderItem in orderItems {
      if let orderTotal = orderItem.total()?.floatValue {
        total += orderTotal
      }
    }
    
    totalLabel.text = "$ \(total.toString(0.2))"
  }
  
  func dismissKeyboard() {
    for subView in view.subviews {
      if let textField = subView as? UITextField where textField.isFirstResponder() {
        textField.resignFirstResponder()
      }
    }
  }
  
  func showAlertMessage(message: String?) {
    let alertController = UIAlertController(title: NSLocalizedString("Error", comment: ""), message: message, preferredStyle: .Alert)
    let okAction = UIAlertAction(title: "Ok", style: .Cancel, handler: nil)
    alertController.addAction(okAction)
    presentViewController(alertController, animated: true, completion: nil)
  }
}

// MARK: - FlintTransactionDelegate

extension ItemViewController : FlintTransactionDelegate {
  
  func transactionDidCancel(canceledStep: FlintTransactionCancelableStep, autoTimeout autoTimeOut: Bool) {
    handleResetTapped(true)
    dismissViewControllerAnimated(true, completion: nil)
  }
  
  func transactionDidComplete(userInfo: [NSObject : AnyObject]!) {
    handleResetTapped(true)
    dismissViewControllerAnimated(true, completion: nil)
  }
}

// MARK: - UITextFieldDelegate

extension ItemViewController : UITextFieldDelegate {
  
  func textFieldShouldReturn(textField: UITextField) -> Bool {
    textField.resignFirstResponder()
    return true
  }
}
