//
/*! @file FlintTransaction.h */
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

/*!
 * @enum FlintTransactionCancelableStep
 *
 * @brief Determine the cancel action happen at which step during the transaction flow.
 */
typedef NS_ENUM(NSInteger, FlintTransactionCancelableStep){
  TransactionCancelOnUnknownStep,           /*!< Cancel happen due to auto time out and not user initiating. */
  TransactionCancelOnPaymentSelection,      /*!< User tap on cancel button on payment selection screen.  */
  TransactionCancelOnScanCardDetails,       /*!< User tap on cancel button when they required to enter the card scan detail. */
  TransactionCancelOnScanCardVerification,  /*!< User tap on cancel button when they verifying the card number. */
  TransactionCancelOnCardSignature          /*!< User tap on cancel button on the signature screen. */
};



/*!
 *  The key containing the FlintOrder object in the userInfo dictionary upon transaction completed.
 */
extern NSString *const FlintTransactionOrderKey;

/*!
 *  The key containing the FlintPayment object in the userInfo dictionary upon transaction completed.
 */
extern NSString *const FlintTransactionPaymentKey;

/*!
 *  The key containing the FlintInvoice object in the userInfo dictionary upon transaction completed.
 */
extern NSString *const FlintTransactionInvoiceKey;

/*!
 *  The key containing the NSError object if any error happens during transaction process.
 */
extern NSString *const FlintTransactionErrorKey;



/*!
 * @class FlintTransaction
 *
 * @brief A wrapper model to capture information for the drop in payment workflow.
 */
@interface FlintTransaction : NSObject

@end



/*!
 * @protocol FlintTransactionDelegate
 *
 * @brief Delegate to handle actions upon different transaction status.
 */
@protocol FlintTransactionDelegate <NSObject>

@optional
/*!
 *  @brief Delegate call back if transaction is cancelled before submitting.
 *
 *  @param canceledStep The screen on which the cancellation happen.
 *  @param autoTimeOut  Whether the cancellation is caused by automatic timeout instead of user initiate.
 */
- (void)transactionDidCancel:(FlintTransactionCancelableStep)canceledStep autoTimeout:(BOOL)autoTimeOut;

/*!
 *  @brief Delegate call back if transaction is submitted for processing.
 *
 *  @discussion If an error occurs, the userInfo dictionary will contain FlintTransactionErrorKey.\n
 *  If a payment success processing, it will contain FlintTransactionOrderKey and FlintTransactionPaymentKey.\n
 *  If an invoice success sending, it will contain FlintTransactionOrderKey and FlintTransactionInvoiceKey.\n
 *
 *  @param userInfo the userInfo that contains the result objects
 */
- (void)transactionDidComplete:(NSDictionary *)userInfo;

@end