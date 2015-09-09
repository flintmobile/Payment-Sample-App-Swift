//
//  FlintCreditCardValidator.h
//  FlintConnect
//
//  Created by PC on 4/8/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FlintModelEnum.h"

typedef NS_ENUM(NSInteger, FlintCardValidationStatus) {
  CardValidationStatusUnknown,
  CardValidationStatusSuccess,
  CardValidationStatusFailed,
};

@interface FlintCardValidator : NSObject

/**
 *  Validate card brand using Regex
 *  http://www.regular-expressions.info/creditcard.html
 *
 *  @param cardNumberText the card number in string format
 *
 *  @return the card brand
 */
+ (FlintCreditCardType)cardBrandForCardNumberText:(NSString *)cardNumberText;

/**
 *  Use mod 10 check sum algorithm
 *  http://web.eecs.umich.edu/~bartlett/credit_card_number.html
 *
 *  @param cardNumberText the card number in string format
 *
 *  @return YES if validation passed, NO otherwise
 */
+ (BOOL)checkSumForCardNumberText:(NSString *)cardNumberText;

@end

/**************************
 *  FlintCardConfig
 ***************************/
@interface FlintCardConfig : NSObject

+ (instancetype)cardConfigForBrand:(FlintCreditCardType)cardBrand;

@property (copy, nonatomic, readonly) NSString *logoName;
@property (copy, nonatomic, readonly) NSString *digitGroupMask;
@property (assign, nonatomic, readonly) NSInteger secureLength;

@end
