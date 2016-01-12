//
/*! @file FlintTransactionLimits.h */
//  FlintConnect
//
//  Created by Nidhi Jain on 5/8/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"
#import "FlintPayment.h"

typedef NS_ENUM(NSInteger, FlintTransactionLimitStatus) {
  TransactionStatusLimitUnknown,
  TransactionStatusUnderLimit,
  TransactionStatusOverLimit
};

@interface FlintTransactionLimits : FlintDomainObject

/**
 *  The amount validated against transaction limits
 */
@property (copy, nonatomic) NSNumber *amount;

/**
 *  The card payment method type.
 *  The transaction limits are different for manual or scanned card entry.
 */
@property (assign, nonatomic) FlintCreditCardEntryType inputType;

/**
 *  Status of validating the transaction amount for within the limits.
 */
@property (assign, nonatomic) FlintTransactionLimitStatus status;

/**
 *  Reason for overall status
 */
@property (copy, nonatomic) NSString *statusCode;

/**
 *  Status message for validating the transanction amount
 */
@property (copy, nonatomic) NSString *statusMessage;

/**
 *  The transaction amount must be within this value.
 */
@property (copy, nonatomic) NSNumber *transactionMax;

/**
 *  The maximum transaction amount that can be processed in a day.
 */
@property (copy, nonatomic) NSNumber *dailyMax;

/**
 *  The transaction amount already processed on the current day.
 */
@property (copy, nonatomic) NSNumber *dailyProcessed;

/**
 *  The maximum transaction amount that can be processed in a week.
 */
@property (copy, nonatomic) NSNumber *weeklyMax;

/**
 *  The transaction amount processed in the current week.
 */
@property (copy, nonatomic) NSNumber *weeklyProcessed;

@end
