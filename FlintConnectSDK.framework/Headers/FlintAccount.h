//
/*! @file FlintAccount.h */
//  FlintConnect
//
//  Created by PC on 3/27/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"

#import "FlintContact.h"
#import "FlintPermissions.h"
#import "FlintPayment.h"

typedef NS_ENUM(NSInteger, FlintAccountType) {
  FlintAccountUnknown = 0,
  FlintAccountOwner,
  FlintAccountStaff,
};

/**
 *  An abstract class for different account types
 */
@interface FlintAccount : FlintDomainObject

/**
 *  The key that uniquely identify this account
 */
@property (copy, nonatomic) NSString *key;

/**
 *  Whether or not the account is active or suspended
 */
@property (assign, nonatomic, getter=isActive) BOOL active;

/**
 *  Type of account. Possible values - owner or staff
 */
@property (assign, nonatomic) FlintAccountType type;

/**
 *  The contact information for the account
 */
@property (strong, nonatomic) FlintContact *contact;

/**
 *  The device token that associate with the account
 *  TODO: is this APNS token ?
 */
@property (copy, nonatomic) NSString *deviceToken;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *externalId;

/**
 *  TODO: what is this?
 */
@property (assign, nonatomic) BOOL hasMyScansEnabled;

/**
 *  Specify the permission that the account has access to
 */
@property (strong, nonatomic) FlintPermissions *permissions;

/**
 *  Username
 */
@property (copy, nonatomic) NSString *userName;

/**
 *  Get account information from server
 *
 *  @param completion   The block called after the async fetch account operation completes (optional)
 */
+ (void)fetchWithCompletion:(FlintRequestHandler)completion;

/**
 *  validate the amount against allowable amount for current account
 *
 *  @param amount     the amount to validate
 *  @param type       the payment type
 *  @param level      the flint profile level
 *  @param completion completion block
 */
+ (void)validateTransactionAmount:(NSNumber *)amount
                   forPaymentType:(FlintPaymentMethod)type
                  validationLevel:(NSInteger)level
                       completion:(FlintRequestHandler)completion;

@end



/******************************************
 *  Owner Account
 *****************************************/
@interface FlintOwnerAccount : FlintAccount

@end



/******************************************
 *  Staff Account
 *****************************************/
@interface FlintStaffAccount : FlintAccount

/**
 *  The key that uniquely identify the owner account for this staff
 */
@property (copy, nonatomic) NSString *ownerKey;

@end
