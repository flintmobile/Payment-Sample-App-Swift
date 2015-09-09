//
//  FlintCardEntryView.h
//  FlintConnect
//
//  Created by PC on 4/10/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FlintTextField;
@class FlintCardNumberEntryView;
@class FlintDateEntryView;
@class FlintNumberEntryView;
@class FlintCardEntryView;

@protocol FlintCardEntryViewDelegate <NSObject>

@optional
- (void)cardEntryView:(FlintCardEntryView *)cardEntryView completeEntryForTextField:(FlintTextField *)textField;

@end

IB_DESIGNABLE

@interface FlintCardEntryView : UIView

@property (weak, nonatomic) IBOutlet id<FlintCardEntryViewDelegate>delegate;

#pragma mark - IBInspectable

/**
 *  The font for both the text and place holder of the textfield entries
 *  This font also apply for the validation label
 *  Default to be SDK font name
 *  If you are using custom font, please make sure to follow the steps in one of these blogs
 *  http://www.neevtech.com/blog/2013/11/22/how-to-add-custom-font-to-your-ios-based-app/
 */
@property (strong, nonatomic) IBInspectable NSString *fontName;

/**
 *  The font size for both the text and place holder of the texfield entries
 *  Default to be 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/**
 *  The font size for the validation label
 *  Default to be 12
 */
@property (assign, nonatomic) IBInspectable CGFloat errorFontSize;

/**
 *  The text to be displayed when validation failed
 *  Default to be @"Invalid Card Number"
 */
@property (copy, nonatomic) IBInspectable NSString *errorText;

/**
 *  Foreground color apply for all text field text
 *  Default to be black color
 */
@property (strong, nonatomic) IBInspectable UIColor *foregroundColor;

/**
 *  Miscellaneous color apply for place holder, underline color,...
 *  To customize different color, access each component via accessors
 *  Default to be light gray color
 */
@property (strong, nonatomic) IBInspectable UIColor *miscColor;

/**
 *  Error color apply for textfield validation color & validation label
 *  Default to be red color
 */
@property (strong, nonatomic) IBInspectable UIColor *errorColor;

/**
 *  The fix height apply for all text field. 
 *  Setting this with value higher than 0 disable dynamic vertical scaling
 *  Default to 0 for dynamic scaling
 */
@property (assign, nonatomic) IBInspectable CGFloat textfieldHeight;

@end

@interface FlintCardEntryView (UIAccessors)

@property (strong, nonatomic, readonly) FlintCardNumberEntryView *cardNumberView;
@property (strong, nonatomic, readonly) FlintDateEntryView *expirationDateView;
@property (strong, nonatomic, readonly) FlintNumberEntryView *cvvView;
@property (strong, nonatomic, readonly) FlintNumberEntryView *zipcodeView;

@end