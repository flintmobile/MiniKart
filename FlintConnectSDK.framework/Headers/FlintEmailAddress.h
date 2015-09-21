//
/*! @file FlintEmailAddress.h */
//  FlintConnect
//
//  Created by PC on 3/27/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"

@interface FlintEmailAddress : FlintDomainObject

/**
 *  The email address value
 */
@property (copy, nonatomic) NSString *value;

/** 
 * Creates and returns a FlintEmailAddress using value passed in
 *
 * @return  A new FlintEmailAddress object or nil.
 */
+ (FlintEmailAddress *)emailAddressWithValue:(NSString *)value;

@end
