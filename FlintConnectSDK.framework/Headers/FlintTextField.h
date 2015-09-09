//
//  FlintTextField.h
//  FlintConnect
//
//  Created by PC on 4/7/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FlintTextField;

typedef NS_ENUM(NSInteger, FlintTextFieldState) {
  TextFieldStateValid,
  TextFieldStateInvalid,
};

typedef NS_ENUM(NSInteger, FlintTextFieldValidationMode) {
  TextFieldValidationRaw,
  TextFieldValidationWithMask
};

typedef void(^FlintTextFieldFormatHandler)(FlintTextField *textField, FlintTextFieldState validationState);
typedef void(^FlintTextFieldValidationHandler)(FlintTextFieldState validationState);

@protocol FlintTextFieldValidation <NSObject>

/**
 *  Validating the text
 *
 *  @param textField            the text field
 *  @param text                 depend on validationMode that this supply rawText or maskedText
 *  @param validationCompletion call this when validation complete
 */
@optional
- (void)textField:(FlintTextField *)textField validateText:(NSString *)text completion:(FlintTextFieldValidationHandler)validationCompletion;

@end

@interface FlintTextField : UITextField

/**
 *  The masking value, e.g. @"(###)###-####"
 */
@property (copy, nonatomic) NSString *mask;

/**
 *  The raw / non-mask text value
 */
@property (copy, nonatomic, readonly) NSString *rawText;

/**
 *  Specify which value to hand to the validator for validating
 *  Default to be TextFieldValidationRaw
 */
@property (assign, nonatomic) FlintTextFieldValidationMode validationMode;

/**
 *  Specify the validation rule for the text field
 */
@property (weak, nonatomic) id<FlintTextFieldValidation>validator;

/**
 *  Different states of the text field
 *  Initial to be TextFieldStateValid
 */
@property (assign, nonatomic) FlintTextFieldState validationState;

/**
 *  Formatting the textfield look and feel for different states
 */
@property (copy, readwrite) FlintTextFieldFormatHandler formatHandler;

/**
 *  Secure the maskable value with dot and keep format of the mask
 *  e.g. oo/oo/oooo for securing date
 *  Default to be NO
 */
@property (assign, nonatomic) BOOL shouldSecureMaskText;

/**
 *  Specify how much of the string we want to mask. 
 *  0 mean mask everything if shouldSecureMaskText set to YES
 *  Default to be 0
 */
@property (assign, nonatomic) NSInteger secureMaskLength;

/**
 *  Set the text programatically with masking apply
 *
 *  @param text the raw text
 */
- (void)applyMaskOnText:(NSString *)text;

/**
 *  return YES if validation state valid and text field length > 0
 *
 *  @return NO otherwise
 */
- (BOOL)passValidation;

#pragma mark - Delegate Pipe

/**
 *  In order for validation to work, text field delegate MUST call this method in 
 *  textField:shouldChangeCharactersInRange:replacementString:
 *
 *  @param range  the range from the delegate
 *  @param string the string from the delegate
 *
 *  @return YES to receive input, NO to stop
 */
- (BOOL)shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

@end
