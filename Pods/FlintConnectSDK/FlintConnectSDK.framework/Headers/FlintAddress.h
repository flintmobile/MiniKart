//
/*! @file FlintAddress.h */
//  FlintConnect
//
//  Created by PC on 3/30/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"

@interface FlintAddress : FlintDomainObject

/**
 *  city
 */
@property (copy, nonatomic) NSString *city;

/**
 *  country
 */
@property (copy, nonatomic) NSString *country;

/**
 *  postal code - should be 5 digits
 */
@property (copy, nonatomic) NSString *postalCode;

/**
 *  state
 */
@property (copy, nonatomic) NSString *state;

/**
 *  street line 1
 */
@property (copy, nonatomic) NSString *street1;

/**
 *  street line 2
 */
@property (copy, nonatomic) NSString *street2;

@end
