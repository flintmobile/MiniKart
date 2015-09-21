//
/*! @file FlintCardNumberEntryView.h */
//  FlintConnect
//
//  Created by PC on 4/8/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintTextEntryView.h"
#import "FlintCardValidator.h"

@class FlintLineTextField;

IB_DESIGNABLE

@interface FlintCardNumberEntryView : FlintTextEntryView

/**
 *  access to current card brand
 */
@property (assign, nonatomic, readonly) FlintCreditCardType cardBrand;

#pragma mark - IBInspectable

/**
 *  The spacing between the right edge and logo
 *  Default to be 0
 */
@property (assign, nonatomic) IBInspectable CGFloat rightSpacing;

@end