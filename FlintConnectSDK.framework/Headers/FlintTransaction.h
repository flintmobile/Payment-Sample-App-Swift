//
//  FlintTransaction.h
//  FlintConnect
//
//  Created by Phuoc Nguyen on 6/23/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FlintOrder.h"
#import "FlintPayment.h"
#import "FlintScanResult.h"
#import "FlintInvoice.h"
#import "FlintTransactionLimits.h"

typedef NS_ENUM(NSInteger, FlintTransactionCancelableStep) {
  TransactionCancelOnUnknownStep,
  TransactionCancelOnPaymentSelection,
  TransactionCancelOnScanCardDetails,
  TransactionCancelOnScanCardVerification,
  TransactionCancelOnCardSignature
};

/**
 *  The key containing the FlintOrder object in the userInfo dictionary upon transaction completed
 */
extern NSString *const FlintTransactionOrderKey;

/**
 *  The key containing the FlintPayment object in the userInfo dictionary upon transaction completed
 */
extern NSString *const FlintTransactionPaymentKey;

/**
 *  The key containing the FlintInvoice object in the userInfo dictionary upon transaction completed
 */
extern NSString *const FlintTransactionInvoiceKey;

/**
 *  The key containing the NSError object if any error happens during transaction process
 */
extern NSString *const FlintTransactionErrorKey;

@protocol FlintTransactionDelegate <NSObject>

@optional
/**
 *  Delegate call back if transaction is cancelled before submitting
 *
 *  @param canceledStep the screen on which the cancellation happen
 *  @param autoTimeOut  if the cancellation is caused by automatic timeout instead of user initiate
 */
- (void)transactionDidCancel:(FlintTransactionCancelableStep)canceledStep autoTimeout:(BOOL)autoTimeOut;

/**
 *  Delegate call back if transaction is submitted for processing and whether the processing complete successfully or error
 *  If an error occurs, this will contain FlintTransactionErrorKey
 *  If a payment success processing, this will contain FlintTransactionOrderKey and FlintTransactionPaymentKey
 *  If an invoice success sending, this will contain FlintTransactionOrderKey and FlintTransactionInvoiceKey
 *
 *  @param userInfo the userInfo that contains the result objects
 */
- (void)transactionDidComplete:(NSDictionary *)userInfo;

@end

@interface FlintTransaction : NSObject

@end