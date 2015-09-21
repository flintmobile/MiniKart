//
/*! @file FlintCardValidator.h */
//  FlintConnect
//
//  Created by PC on 4/8/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FlintModelEnum.h"

/*!
 *  @enum FlintCardValidationStatus
 *
 *  @brief Card validation status.
 */
typedef NS_ENUM(NSInteger, FlintCardValidationStatus){
  CardValidationStatusUnknown,        /*!< Validation has not yet happened or unknown state. */
  CardValidationStatusSuccess,        /*!< Validation success. */
  CardValidationStatusFailed,         /*!< Validation failed. */
};



/*!
 *  @class FlintCardValidator
 *  
 *  @brief A convenient utility to locally validate the card number.
 */
@interface FlintCardValidator : NSObject

/*!
 *  @brief Validate card type using Regex.
 *
 *  @discussion http://www.regular-expressions.info/creditcard.html
 *
 *  @param cardNumberText The card number in string format.
 *
 *  @return The card type.
 */
+ (FlintCreditCardType)cardTypeFromCardNumberText:(NSString *)cardNumberText;

/*!
 *  @brief Use mod 10 check sum algorithm.
 *  
 *  @discussion http://web.eecs.umich.edu/~bartlett/credit_card_number.html
 *
 *  @param cardNumberText The card number in string format.
 *
 *  @return YES if validation passed, NO otherwise.
 */
+ (BOOL)checkSumForCardNumberText:(NSString *)cardNumberText;

@end



/*!
 *  @class FlintCardConfig
 *
 *  @brief Wrapping general configuration related to how the card number UI should be formatted.
 */
@interface FlintCardConfig : NSObject

/*!
 *  @brief Create a set of configuration for a specific card type.
 *
 *  @param cardType the card type
 *
 *  @return the card configuration
 */
+ (instancetype)cardConfigWithType:(FlintCreditCardType)cardType;

/*!
 *  @brief The logo image name
 */
@property (copy, nonatomic, readonly) NSString *logoName;

/*!
 *  @brief the mask for grouping digits
 *
 *  @discussion digit grouping has two different patterns between AMEX and the rest
 */
@property (copy, nonatomic, readonly) NSString *digitGroupMask;

/*!
 *  @brief the number of digits that should be protected using dot mask
 *
 *  @discussion the secured length will vary so that the last four of the card numbers will be visible
 */
@property (assign, nonatomic, readonly) NSInteger secureLength;

@end
