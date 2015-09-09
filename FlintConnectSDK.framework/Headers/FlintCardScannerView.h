//
//  FlintCardScannerView.h
//  FlintConnect
//
//  Created by PC on 4/20/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintCardScanner.h"

@class FlintCardScannerView;

@protocol FlintCardScannerViewDelegate <NSObject>

@optional
/**
 *  Give the hook for when the back button is Tapped
 */
- (void)cardScannerViewBackButtonTapped:(FlintCardScannerView *)cardScannerView;

/**
 *  Give the hook for when the done button is tapped wiht or without the image captured
 */
- (void)cardScannerView:(FlintCardScannerView *)cardScannerView useImage:(UIImage *)image;

@end

IB_DESIGNABLE

@interface FlintCardScannerView : UIView

@property (weak, nonatomic) IBOutlet id<FlintCardScannerViewDelegate>delegate;

/**
 *  Convenient pipe-through method to set the scanner settings
 *  For individual setting modification, access the imageStablizer or the cardScanner directly
 *
 *  @param scannerSettings the scanner settings
 */
- (void)applyScannerSettings:(FlintScannerSettings *)scannerSettings;

/**
 *  Convenient pipe-through method to retrieve the scanner settings
 *  To access each setting individually, use the imageStabilizer or the cardScanner accessor directly
 *
 *  @return the scanner settings
 */
- (FlintScannerSettings *)currentScannerSettings;

#pragma mark - IBInspectable

/**
 *  Color use for text, title, etc..
 *  Default to white
 */
@property (strong, nonatomic) IBInspectable UIColor *textColor;

/**
 *  color use for button title, button background, etc..
 *  Default to SDK Theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/**
 *  Font name for texts & titles on this view
 *  Default to be SDK font name
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

/**
 *  Font name for buttons on this view
 *  Default to be SDK bold font name
 */
@property (copy, nonatomic) IBInspectable NSString *boldFontName;

@end

@interface FlintCardScannerView (UIAccessors)

/**
 *  The card scanner of the view
 *  Calling startScanningSession: on this card scanner after applySettings: to start the scanning
 *  Calling stopScanningSession on this card scanner to stop the scanning
 */
@property (strong, nonatomic, readonly) FlintCardScanner *cardScanner;

@property (strong, nonatomic, readonly) UIButton *backButton;
@property (strong, nonatomic, readonly) UILabel *scanTitle;
@property (strong, nonatomic, readonly) UIButton *torchButton;

@property (strong, nonatomic, readonly) UILabel *confirmationLabel;
@property (strong, nonatomic, readonly) UILabel *securityLabel;

@property (strong, nonatomic, readonly) UIButton *reScanButton;
@property (strong, nonatomic, readonly) UIButton *doneButton;
@property (strong, nonatomic, readonly) UIButton *scanButton;
@property (strong, nonatomic, readonly) UIButton *manualButton;

@end