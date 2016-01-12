//
/*! @file FlintPayment.h */
//  FlintConnect
//
//  Created by Nidhi Jain on 4/23/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"
#import "FlintCreditCard.h"
#import "FlintModelEnum.h"

typedef NS_ENUM(NSUInteger, FlintPaymentMethod) {
  PaymentMethodUnknown = 0,
  PaymentMethodCash,
  PaymentMethodCheck,
  PaymentMethodCreditCard
};

typedef NS_ENUM(NSInteger, FlintCreditCardEntryType) {
  CreditCardEntryTypeManual = 1,
  CreditCardEntryTypeScan
};

typedef NS_ENUM(NSInteger, FlintChargeType) {
  ChargeTypeDebit,
  ChargeTypeCredit
};

typedef NS_ENUM(NSUInteger, FlintReceiptMethod) {
  ReceiptMethodEmail = 1,
  ReceiptMethodSMS
};

@class FlintPaymentCreateTemplate;

@class FlintCashPayment;
@class FlintCashPaymentCreateTemplate;

@class FlintCheckPayment;
@class FlintCheckPaymentCreateTemplate;

@class FlintCreditCardPayment;
@class FlintCreditCardPaymentCreateTemplate;

/************************
 *  FlintBasePayment
 ************************/
@interface FlintPayment : FlintDomainObject

/**
 *  First name of individual who processed this transaction
 */
@property (copy, nonatomic) NSString *acceptedByFirstName;

/**
 *  Last name of individual who processed this transaction
 */
@property (copy, nonatomic) NSString *acceptedByLastName;

/**
 *  Amount paid
 */
@property (copy, nonatomic) NSNumber *amount;

/**
 *  Email address of the receipt recipient if a receipt was sent. 'nil' otherwise.
 */
@property (copy, nonatomic) NSString *contactEmail;

/**
 *  Creation timestamp
 */
@property (strong, nonatomic) NSDate *createdDate;

/**
 *  Fees charged
 */
@property (copy, nonatomic) NSString *feeAmount;

/**
 *  Unique identifier for the payment
 */
@property (copy, nonatomic) NSString *key;

/**
 *  Memo
 */
@property (copy, nonatomic) NSString *memo;

/**
 *  Payment Method
 */
@property (assign, nonatomic, readonly) FlintPaymentMethod method;

/**
 *  Amount owed to the merchant after fees
 */
@property (copy, nonatomic) NSString *netAmount;

/**
 *  Order Id to to which this payment belongs
 */
@property (copy, nonatomic) NSString *orderId;

/**
 *  Human readable identifier for the payment
 */
@property (copy, nonatomic) NSString *paymentNumber;

/**
 *  Payment status
 */
@property (copy, nonatomic) NSString *status;

/**
 *  Custom payment identifier assigned by client
 */
@property (copy, nonatomic) NSString *trackingId;

/**
 *  Email the payment receipt to the customer.
 *
 *  @param emailAddress     The email address to send the receipt
 *  @param completionHandler    The block to call when the receipt is sent.
 */
- (void)emailReceipt:(NSString *)emailAddress completionHandler:(FlintRequestHandler)handler;

/**
 *  Refund the payment. The entire amount will be refunded. 
 *
 *  @param completionHandler    The block to call when the refund is processed.
 *  On success, the status of the payment will be updated to 'voided"
 */
- (void)refundWithCompletionHandler:(FlintRequestHandler)handler;

/**
 *  SMS the payment receipt to the customer.
 *
 *  @param phoneNumber     The phone number to text the receipt
 *  @param completionHandler    The block to call when the receipt is sent.
 */
- (void)smsReceipt:(NSString *)phoneNumber completionHandler:(FlintRequestHandler)handler;

@end


/*******************************
 *  FlintPaymentCreateTemplate
 ******************************/
@interface FlintPaymentCreateTemplate : NSObject

/**
 *  Amount paid
 *  @warning Must not be `nil`.
 */
@property (copy, nonatomic) NSNumber *amount;

/**
 *  Memo
 */
@property (copy, nonatomic) NSString *memo;

/**
 *  Custom payment identifier assigned by client
 */
@property (copy, nonatomic) NSString *trackingId;

/**
 *  The method based on which subclass is instantiated
 */
@property (assign, nonatomic, readonly) FlintPaymentMethod method;

@end


/************************
 *  FlintCashPayment
 *************************/
@interface FlintCashPayment : FlintPayment

/**
 *  Preconfigured template to create the cash payment
 *
 *  @return the template to create the cash payment
 */
+ (FlintCashPaymentCreateTemplate *)templateToCreate;

@end


/***********************************
 *  FlintCashPaymentCreateTemplate
 ************************************/
@interface FlintCashPaymentCreateTemplate : FlintPaymentCreateTemplate

@end


/**********************
 *  FlintCheckPayment
 **********************/
@interface FlintCheckPayment : FlintPayment

/**
 *  Preconfigured template to create the check payment
 *
 *  @return the template to create the check payment
 */
+ (FlintCheckPaymentCreateTemplate *)templateToCreate;

@end


/************************************
 *  FlintCheckPaymentCreateTemplate
 ************************************/
@interface FlintCheckPaymentCreateTemplate : FlintPaymentCreateTemplate

@end

/***************************
 *  FlintCreditCardPayment
 ***************************/
@interface FlintCreditCardPayment : FlintPayment

/**
 *  Provider Authorization Code if “succeeded"
 */
@property (copy, nonatomic) NSNumber *authCode;

/**
 *  The credit card that associate with the payment
 */
@property (strong, nonatomic) FlintCreditCard *card;

/**
 *  Debit or credit, used to determine the fee associating with each type
 */
@property (assign, nonatomic) FlintChargeType chargeType;

/**
 * Any authorization error occured during payment process,
 * nil if payment success
 */
@property (strong, nonatomic) NSError *paymentError;

/**
 *  Use as classification between manual entry and scan card
 *  Server side also use this to query different scan payments
 */
@property (copy, nonatomic) NSString *scanKey;

/**
 *  Preconfigured template to create the credit card payment
 *
 *  @return the template to create the credit card payment
 */
+ (FlintCreditCardPaymentCreateTemplate *)templateToCreate;

@end


/*****************************************
 *  FlintCreditCardPaymentCreateTemplate
 *****************************************/
@interface FlintCreditCardPaymentCreateTemplate : FlintPaymentCreateTemplate

/**
 *  Credit card object
 */
@property (strong, nonatomic) FlintCreditCard *card;

/**
 *  Signature Image
 */
@property (strong, nonatomic) NSData *signatureImage;

/**
 *  Use as classification between manual entry and scan card
 *  Server side also use this to query different scan payments
 */
@property (copy, nonatomic) NSString *scanKey;

@end
