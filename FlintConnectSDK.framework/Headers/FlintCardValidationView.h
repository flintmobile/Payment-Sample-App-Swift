//
//  FlintCardValidationView.h
//  FlintConnect
//
//  Created by Phuoc Nguyen on 5/7/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintCardValidator.h"

@class FlintCardNumbersEditorView;

IB_DESIGNABLE

@interface FlintCardValidationView : UIView

@property (assign, nonatomic, readonly) FlintCardValidationStatus validationStatus;

/**
 *  Toggle the visibility of the status bar
 *
 *  @param visible is visible
 *  @param animate should come with animation or not
 */
- (void)toggleStatusBar:(BOOL)visible animate:(BOOL)animate;

#pragma mark - IBInspectable

/**
 *  The card number to be validate
 */
@property (strong, nonatomic) IBInspectable NSString *cardNumber;

/**
 *  The validation image of the card number
 */
@property (strong, nonatomic) IBInspectable UIImage *cardNumberImage;

/**
 *  The status icon when the card is valid
 */
@property (strong, nonatomic) IBInspectable UIImage *validIcon;

/**
 *  The status icon when the card is invalid
 */
@property (strong, nonatomic) IBInspectable UIImage *invalidIcon;

/**
 *  The font name for the number editor
 *  Default to be SDK font name
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

/**
 *  The font size for the number editor
 *  Default to be SDK button font size
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/**
 *  The color for the number editor
 *  Default to be SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

@end

@interface FlintCardValidationView (UIAccessors)

@property (strong, nonatomic, readonly) UIImageView *validationImageView;
@property (strong, nonatomic, readonly) UIImageView *cardBrandImageView;

- (UIImageView *)cardNumberImageView;
- (FlintCardNumbersEditorView *)cardNumberEditor;

@end