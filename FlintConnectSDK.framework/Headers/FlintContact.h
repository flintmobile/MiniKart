//
/*! @file FlintContact.h */
//  FlintConnect
//
//  Created by PC on 3/27/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"

#import "FlintPhoneNumber.h"
#import "FlintEmailAddress.h"

@interface FlintContact : FlintDomainObject

/**
 *  First Name
 */
@property (copy, nonatomic) NSString *firstName;

/**
 *  Last Name
 */
@property (copy, nonatomic) NSString *lastName;

/**
 *  Birthday
 */
@property (strong, nonatomic) NSDate *birthday;

/**
 *  Email Address
 */
@property (strong, nonatomic) FlintEmailAddress *emailAddress;

/**
 *  Phone Number
 */
@property (strong, nonatomic) FlintPhoneNumber *phoneNumber;

@end
