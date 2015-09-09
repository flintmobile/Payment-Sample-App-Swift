//
//  FlintOrder.h
//  FlintConnect
//
//  Created by Nidhi Jain on 4/13/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"
#import "FlintOrderItem.h"
#import "FlintPayment.h"
#import "FlintContact.h"
#import "FlintInvoice.h"

@class FlintOrderCreateTemplate;

typedef NS_ENUM(NSInteger, FlintOrderStatus) {
  FlintOrderStatusOpen,
  FlintOrderStatusClosed,
  FlintOrderStatusVoided,
};

typedef NS_ENUM(NSInteger, FlintOrderFinancialStatus) {
  FlintOrderFinancialStatusUnpaid,
  FlintOrderFinancialStatusPaid,
  FlintOrderFinancialStatusRefunded,
};

@interface FlintOrder : FlintDomainObject

/**
 *  Date when the order is created
 *  This is auto generated by Flint
 */
@property (strong, nonatomic) NSDate *createdDate;

/**
 *  The customer contact inforamtion, if different than order contact.
 *  Leave this empty if the invoice is to be sent to the same contact information
 *  that is on the order. Atleast one of the contact information should be there
 *  to send an Invoice.
 */
@property(strong, nonatomic) NSString *customerName;

/**
 *  Consumer email address
 */
@property(strong, nonatomic) FlintEmailAddress *emailAddress;

/**
 *  Consumer phone number
 *  @optional
 */
@property(strong, nonatomic) FlintPhoneNumber *phoneNumber;

/**
 *  This indicates if the order was fulfilled by the merchant.
 *  When an order is created, the default value will be NO unless 
 *  specified otherwise. The user should call fulfillOrder: to update
 *  the status, once the order is fulfilled by the merchant.
 */
@property (assign, nonatomic) BOOL fulfilled;

/**
 *  Array of FlintOrderItem
 */
@property (copy, nonatomic) NSArray *lineItems;

/**
 *  The display, human readable way to track an order
 *  This should be unique but not completely guaranted
 */
@property (copy, nonatomic) NSString *orderNumber;

/**
 *  The way to identify where the order is originally created
 *  Cannot use the reserved words.
 *  Reserved words : 'FlintWeb'
 */
@property (copy, nonatomic) NSString *origin;

/**
 *  The array of FlintPayment
 */
@property (copy, nonatomic) NSArray *payments;

/**
 *  The last email addresses to which the order receipt has been sent to
 */
@property (copy, nonatomic) NSSet *receiptEmailAddresses;

/**
 *  The last phone number to which the order receipt has been sent to
 */
@property (copy, nonatomic) NSSet *receiptPhoneNumbers;

/**
 *  This is the composite status of the order
 *  Check FlintOrderStatus enum for possible values. An order is in FlintOrderStatusOpen when it's
 *  created. An order which is both paid and fulfilled will have status FlintOrderStatusClosed. And order
 *  can be voided before it's closed. If a paid order is voided, the payment will be refunded.
 */
@property (assign, nonatomic) FlintOrderStatus orderStatus;

/**
 *  This is the composite payment status of the order
 *  Check FlintOrderFinancialStatus enum for possible values.
 */
@property (assign, nonatomic) FlintOrderFinancialStatus orderFinancialStatus;

/**
 *  The subtotal from the subtotal of all order items
 */
@property (strong, nonatomic) NSNumber *subTotal;

/**
 *  Tip
 */
@property (copy, nonatomic) NSNumber *tipAmount;

/**
 *  Total amount - sub total +/- any discount, tax, tip
 */
@property (strong, nonatomic) NSNumber *total;

/**
 *  the total discount from all the order items
 */
@property (copy, nonatomic) NSNumber *totalDiscount;

/**
 *  the total tax from all the order items
 */
@property (copy, nonatomic) NSNumber *totalTax;

/**
 *  Order Id
 */
@property (copy, nonatomic) NSString *uid;

/**
 *  Use this template to create a new order
 *  You should configure the properties of this template to provide order information. When you are
 *  ready to submit the order, call createWithTemplate:completion: to generate an order from this template.
 *
 *  @return the base template.
 */
+ (FlintOrderCreateTemplate *)templateToCreate;

/**
 *  Create an order from template.
 *  You should retrieve the template from the class method templateToCreate rather than initialize a new one.
 *  Once an order has been created it cannot be updated by the user.
 *
 *  @param createTemplate the template for creation
 *  @param completion     the completion block to be called after order created. Upon success, a FlintOrder object is returned
 */
+ (void)createWithTemplate:(FlintOrderCreateTemplate *)createTemplate completion:(FlintRequestHandler)completion;

//--TODO:should these three methods be just one?
- (void)applyCashPayment:(FlintCashPaymentCreateTemplate *)paymentTemplate completion:(FlintRequestHandler)completion;

- (void)applyCheckPayment:(FlintCheckPaymentCreateTemplate *)paymentTemplate completion:(FlintRequestHandler)completion;

- (void)applyCardPayment:(FlintCreditCardPaymentCreateTemplate *)paymentTemplate completion:(FlintRequestHandler)completion;

- (void)fulfillWithCompletion:(FlintRequestHandler)completion;

- (void)cancelWithCompletion:(FlintRequestHandler)completion;

- (void)sendInvoice:(FlintInvoiceCreateTemplate *)invoiceTemplate completion:(FlintRequestHandler)completion;

@end

/**
 *  The template to create a new order
 */
@interface FlintOrderCreateTemplate : NSObject

/**
 *  Array of FlintOrderItem
 */
@property (copy, nonatomic) NSArray *lineItems;

/**
 *  The way to identify where the order is originally created
 *  Cannot use one of the reserved words.
 *  Reserved words : 'flint-web'
 */
@property (copy, nonatomic) NSString *origin;

/**
 *  Tip
 */
@property (copy, nonatomic) NSNumber *tipAmount;

/**
 *  The customer contact inforamtion, if different than order contact.
 *  Leave this empty if the invoice is to be sent to the same contact information
 *  that is on the order. Atleast one of the contact information should be there
 *  to send an Invoice.
 */
@property(strong, nonatomic) NSString *customerName;

/**
 *  Consumer email address
 */
@property(strong, nonatomic) FlintEmailAddress *emailAddress;

/**
 *  Consumer phone number
 *  @optional
 */
@property(strong, nonatomic) FlintPhoneNumber *phoneNumber;

/**
 *  Calculated subtotal
 *
 *  @return the subtotal before tax, tip & discount
 */
- (NSNumber *)subTotal;

/**
 *  Calculated total
 *
 *  @return the total amount with tax, tip and discount applied
 */
- (NSNumber *)total;

/**
 *  The total tax paid on all order items
 *
 *  @return the tax amount
 */
- (NSNumber *)totalTax;

/**
 *  The total disount apply
 *
 *  @return the discount amount
 */
- (NSNumber *)totalDiscount;

@end
