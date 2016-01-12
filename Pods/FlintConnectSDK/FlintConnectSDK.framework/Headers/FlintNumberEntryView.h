//
/*! @file FlintNumberEntryView.h */
//  FlintConnect
//
//  Created by PC on 4/9/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintTextEntryView.h"

@class FlintLineTextField;

IB_DESIGNABLE

@interface FlintNumberEntryView : FlintTextEntryView

#pragma mark - IBInspectable

/**
 *  How many digit the entry should allow
 *  Default to 1
 */
@property (assign, nonatomic) IBInspectable NSInteger digitCount;

@end