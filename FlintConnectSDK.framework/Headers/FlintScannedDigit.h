//
/*! @file FlintScannedDigit.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 5/13/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"

@interface FlintScannedDigit : FlintDomainObject

/**
 *  Estimate of how accurate the scanned digit is convert into number
 *  Max is 100. Min is 0
 */
@property (assign, nonatomic) NSUInteger confidenceLevel;

/**
 *  The digit that is intepreted from the image by the OCR
 */
@property (assign, nonatomic) NSUInteger digit;

@end
