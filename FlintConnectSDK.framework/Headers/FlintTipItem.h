//
/*! @file FlintTipItem.h */
//  FlintConnect
//
//  Created by PC on 4/10/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintRoundButton.h"

IB_DESIGNABLE

@interface FlintTipItem : FlintRoundButton

#pragma mark - IBInspectable

/**
 *  The Display unit of the currency
 *  Has no effect if percentage is set to YES
 *  Default to '$'
 */
@property (copy, nonatomic) IBInspectable NSString *unit;

/**
 *  Whether the unit should be display after value
 *  Has no effect if percentage is set to YES
 *  Default to NO for prefix unit
 */
@property (assign, nonatomic, getter=isUnitPostfix) IBInspectable BOOL unitPostfix;

/**
 *  The spacing between unit and the amount
 *  Default to 0
 */
@property (assign, nonatomic) IBInspectable NSInteger unitSpacing;

/**
 *  If the value is display as percentage
 *  Default to YES
 */
@property (assign, nonatomic, getter=isPercentage) IBInspectable BOOL percentage;

/**
 *  The tip amount in percentage or value
 */
@property (assign, nonatomic) IBInspectable CGFloat tipAmmount;

@end
