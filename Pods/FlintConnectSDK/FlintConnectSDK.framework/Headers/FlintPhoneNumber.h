//
/*! @file FlintPhoneNumber.h */
//  FlintConnect
//
//  Created by PC on 3/27/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"

@interface FlintPhoneNumber : FlintDomainObject

/**
 *  The non-formatted value for phone number
 */
@property (copy, nonatomic) NSString *value;

/**
 * Creates and returns a FlintPhoneNumber using value passed in
 *
 * @return  A new FlintPhoneNumber object or nil.
 */
+ (instancetype)phoneNumberWithValue:(NSString *)value;

- (instancetype)initWithValue:(NSString *)value;

@end
