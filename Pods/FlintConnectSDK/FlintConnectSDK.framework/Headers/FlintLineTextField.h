//
/*! @file  FlintLineTextField.h */
//  FlintConnect
//
//  Created by PC on 4/8/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintTextField.h"

IB_DESIGNABLE

@interface FlintLineTextField : FlintTextField

#pragma mark - IBInspectable

/**
 *  The color for the underline
 */
@property (strong, nonatomic) IBInspectable UIColor *lineColor;

/**
 *  The width for the underline
 */
@property (assign, nonatomic) IBInspectable CGFloat lineWidth;

@end
