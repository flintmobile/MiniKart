//
/*! @file FlintDateEntryView.h */
//  FlintConnect
//
//  Created by PC on 4/9/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintTextEntryView.h"

@class FlintLineTextField;

IB_DESIGNABLE

@interface FlintDateEntryView : FlintTextEntryView

#pragma mark - IBInspectable

/**
 *  Setting the format for validating the date entry
 *  This should conform to apple format for NSDateFormatter
 *  Currently only support number format (e.g. Jan 05 is not available)
 *  Setting this also conveniently change the place holder of the text field to promt user for correct input
 */
@property (copy, nonatomic) IBInspectable NSString *dateFormat;

@end