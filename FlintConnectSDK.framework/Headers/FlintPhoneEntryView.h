//
/*! @file FlintPhoneEntryView.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 8/14/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintTextEntryView.h"

@class FlintLineTextField;

IB_DESIGNABLE

@interface FlintPhoneEntryView : FlintTextEntryView

#pragma mark - IBInspectable

/**
 *  The masking value for phone number
 *  Default to be (###) ###-####
 */
@property (copy, nonatomic) IBInspectable NSString *phoneMask;

@end