//
/*! @file FlintModelEnum.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 5/14/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#ifndef FlintConnect_FlintModelEnum_h
#define FlintConnect_FlintModelEnum_h

/*!
 *  @enum FlintCreditCardType
 *
 *  @brief Credit card type (brand) classification.
 */
typedef NS_ENUM(NSInteger, FlintCreditCardType){
  CreditCardTypeUnknown,            /*!< Unknown Type. */
  CreditCardTypeVisa,               /*!< Visa. */
  CreditCardTypeMasterCard,         /*!< Master Card. */
  CreditCardTypeAmex,               /*!< American Express. */
  CreditCardTypeDiscover            /*!< Discover. */
};

#endif
