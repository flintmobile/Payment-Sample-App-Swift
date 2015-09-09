//
//  FlintTipInputView.h
//  FlintConnect
//
//  Created by Phuoc Nguyen on 7/16/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FlintTipInputView;

@protocol FlintTipInputViewDelegate <NSObject>

@optional
/**
 *  fire this on delegate when the add tip button is tapped
 *
 *  @param tipInputView the tip input view
 *  @param tipAmount    the tip amount added
 */
- (void)tipInputView:(FlintTipInputView *)tipInputView addedTipValue:(CGFloat)tipValue;

@end

IB_DESIGNABLE

@interface FlintTipInputView : UIView

@property (weak, nonatomic) IBOutlet id<FlintTipInputViewDelegate>delegate;

#pragma mark - IBInspectable

/**
 *  The font name for the input pad
 *  Default to SDK font name
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

/**
 *  The font size for the input pad
 *  Default to 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/**
 *  The main color
 *  Default to SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/**
 *  Return the button size
 *  Default to 220x44
 */
@property (assign, nonatomic) IBInspectable CGSize buttonSize;

/**
 *  The base amount before adding tip
 *  Default to 0.0f
 */
@property (assign, nonatomic) IBInspectable CGFloat baseAmount;

/**
 *  If the value is display as percentage
 *  Default to YES
 */
@property (assign, nonatomic, getter=isPercentage) IBInspectable BOOL percentage;

/**
 *  The tip amount in percentage or value
 */
@property (assign, nonatomic) IBInspectable CGFloat tipAmmount;

/**
 *  The dolar value of the tip
 *
 *  @return the dolar value for tip regardless of percentage mode or value mode
 */
- (CGFloat)tipValue;

@end
