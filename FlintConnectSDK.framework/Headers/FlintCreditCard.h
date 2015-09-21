//
/*! @file FlintCreditCard.h */
//  FlintConnect
//
//  Created by Nidhi Jain on 5/4/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"
#import "FlintModelEnum.h"

@interface FlintCreditCard : FlintDomainObject

/**
 *  Card Type - “MasterCard”, “Visa”, “Amex”, or “Discover"
 */
@property (assign, nonatomic) FlintCreditCardType type;

/**
 *  Credit card number
 *  @warning Must not be `nil`
 */
@property (copy, nonatomic) NSString *number;

/**
 *  Credit card expiry month
 *  @warning Must not be `nil`
 */
@property (copy, nonatomic) NSString *expiryMonth;

/**
 *  Credit card expiry year
 *  @warning Must not be `nil`
 */
@property (copy, nonatomic) NSString *expiryYear;

/**
 *  Credit card verification code
 *  @warning Must not be `nil`
 */
@property (copy, nonatomic) NSString *cvv;

/**
 *  Billing address zip code
 */
@property (copy, nonatomic) NSString *zipCode;

@end
