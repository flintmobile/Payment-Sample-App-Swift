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
  
  let orderItems = [FlintOrderItem]()
  var total: Float = 0
  
  override func viewDidLoad() {
    super.viewDidLoad()
  }
  
  @IBAction func handleAddItemTapped(sender: AnyObject) {
    guard let price = priceTextField.floatValue(), name = nameTextField.text where !name.isEmpty else {
      let alertController = UIAlertController(title: "Error", message: "Name and price can't be empty", preferredStyle: .Alert)
      let okButton = UIAlertAction(title: "Ok", style: .Cancel, handler: nil)
      alertController.addAction(okButton)
      self.presentViewController(alertController, animated: true, completion: nil)
      return
    }
    
    let item = FlintOrderItem()
    item.name = name;
    item.price = price;
    item.taxAmount = self.taxTextField.floatValue()
  }
  
  @IBAction func handleResetTapped(sender: AnyObject) {
    
  }
  
  @IBAction func handleTakePaymentTapped(sender: AnyObject) {
    
  }
}

// MARK: FlintTransactionDelegate

extension ItemViewController : FlintTransactionDelegate {

}

// MARK: UITextFieldDelegate

extension ItemViewController : UITextFieldDelegate {
  
  func textFieldShouldReturn(textField: UITextField) -> Bool {
    textField.resignFirstResponder()
    return true
  }
}
