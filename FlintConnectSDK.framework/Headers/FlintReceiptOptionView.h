//
//  FlintReceiptOptionView.h
//  FlintConnect
//
//  Created by Phuoc Nguyen on 6/24/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintActionTextField.h"

IB_DESIGNABLE

@interface FlintReceiptOptionView : UIView <FlintActionTextFieldDelegate, UITextFieldDelegate>

#pragma mark - IBInspectable

/**
 *  The height for the text fields
 *  Default to be 50
 */
@property (assign, nonatomic) IBInspectable CGFloat textFieldHeight;

@end

@interface FlintReceiptOptionView (UIAccesors)

@property (strong, nonatomic, readonly) UIImageView *emailIconView;
@property (strong, nonatomic, readonly) FlintActionTextField *emailTextField;
@property (strong, nonatomic, readonly) UIImageView *smsIconView;
@property (strong, nonatomic, readonly) FlintActionTextField *smsTextField;

@end