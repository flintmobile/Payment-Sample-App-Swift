//
//  UITextFieldExension.swift
//  PaymentSampleAppSwift
//
//  Created by PC on 9/10/15.
//  Copyright © 2015 PC. All rights reserved.
//

import Foundation
import UIKit

extension UITextField {
  func floatValue() -> Float? {
    guard let textValue = self.text where !textValue.isEmpty else {
      return nil;
    }
    
    return Float(textValue)
  }
}