//
//  FlintCardSigningView.h
//  FlintConnect
//
//  Created by PC on 5/4/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintTipSelectionView.h"
#import "FlintSignatureView.h"

@class FlintCardSigningView;

@protocol FlintCardSigningViewDelegate <NSObject>

@optional
/**
 *  Delegate firing this when other tip option is selected
 *  Use tipAmount property to configure the custom tip
 *
 *  @param cardSigningView the card signing view
 */
- (void)cardSigningViewSelectOtherTipOption:(FlintCardSigningView *)cardSigningView;

/**
 *  Delegate firing this when user cancel the signing via cancel button
 *
 *  @param cardSigningView the card signing view
 */
- (void)cardSigningViewCancelSigning:(FlintCardSigningView *)cardSigningView;

/**
 *  Delegate firing this when user complete the signing via done button
 *
 *  @param cardSigningView the card signing view
 *  @param amount          the total amount (base amount + tip)
 *  @param signatureImage  the signature image, can be nil if user tap done without signing
 */
- (void)cardSigningView:(FlintCardSigningView *)cardSigningView signedForAmount:(CGFloat)amount signatureImage:(UIImage *)signatureImage;

@end

IB_DESIGNABLE

@interface FlintCardSigningView : UIView

@property (weak, nonatomic) IBOutlet id<FlintCardSigningViewDelegate>delegate;

/**
 *  The tip amount in value
 */
@property (assign, nonatomic) CGFloat tipAmount;

/**
 *  Base amount + tip in value
 */
@property (assign, nonatomic, readonly) CGFloat totalAmount;

#pragma mark - IBInspectable

/**
 *  The color for UIControl such as tip button, done button, etc...
 *  Default is SDK Theme Color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/**
 *  The height for header section which include the amount value, tip, etc...
 *  Default to be 75.0f
 */
@property (assign, nonatomic) IBInspectable CGFloat headerHeight;

/**
 *  the font name for all text on this view
 *  default to be SDK font name
 */
@property (strong, nonatomic) IBInspectable NSString *fontName;

/**
 *  The sub-total amount before tip
 *  Default to be 0
 */
@property (assign, nonatomic) IBInspectable CGFloat baseAmount;

/**
 *  The tip selection values
 *  Default to be [0.05,0.1,0.15]
 */
@property (assign, nonatomic) IBInspectable NSString *tipSelections;

@end

@interface FlintCardSigningView (UIAccessors)

@property (strong, nonatomic, readonly) UILabel *amountTitleLabel;
@property (strong, nonatomic, readonly) UILabel *amountValueLabel;
@property (strong, nonatomic, readonly) UILabel *tipTitleLabel;
@property (strong, nonatomic, readonly) FlintTipSelectionView *tipSelectionView;
@property (strong, nonatomic, readonly) FlintSignatureView *signatureView;

@end