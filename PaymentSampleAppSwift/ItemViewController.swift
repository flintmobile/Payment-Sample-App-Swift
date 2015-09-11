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
}

// MARK: - FlintTransactionDelegate

extension ItemViewController : FlintTransactionDelegate {

}

// MARK: - UITextFieldDelegate

extension ItemViewController : UITextFieldDelegate {
  
  func textFieldShouldReturn(textField: UITextField) -> Bool {
    textField.resignFirstResponder()
    return true
  }
}
