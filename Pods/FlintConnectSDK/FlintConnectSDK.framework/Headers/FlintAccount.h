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
#import "FlintOrders.h"

@class FlintOrderFilters;
@class FlintOrderSearchTemplate;


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

+ (void)ordersWithSearchTemplate:(FlintOrderSearchTemplate *)searchTemplate onCompletion:(FlintRequestHandler)handler;

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


@interface FlintOrderFilters: NSObject

@property (assign, nonatomic) NSArray *hasOrderStatus;
@property (assign, nonatomic) NSArray *hasOrderPaymentStatus;
@property (assign, nonatomic) BOOL hasOrderFulfillmentStatus;
@property (copy, nonatomic) NSDate *createdBefore;
@property (copy, nonatomic) NSDate *createdBeforeOrOn;
@property (copy, nonatomic) NSDate *createdAfter;
@property (copy, nonatomic) NSDate *createdAfterOrOn;
@end

/******************************************
 *  Orders Search Template
 *****************************************/
@interface FlintOrderSearchTemplate : NSObject

/**
 * limit - Count of orders to be returned in the response. Defaults to 25. Max allowed 50 
 */
@property (assign, nonatomic) NSInteger limit;

/**
 * startIndex - Index of the starting order Number
 */
@property (assign, nonatomic) NSInteger startIndex;

/** 
 * expandPayments - By default the result will include a trimmed down payments object with only the payment ID.
 * To return a complete payment object set it to YES.
 */
@property (assign, nonatomic) BOOL expandPayments;

/**
 * expandItems - By default the result will include a trimmed down list of order items object with only the order item ID.
 * To return order item details set it to YES.
 */
@property (assign, nonatomic) BOOL expandItems;

/**
 * sortInDescendingOrder - Sorts based on order createion timstamp in descending order be default.
 * Set it to NO to sort in ascending order 
 */
@property (assign, nonatomic) BOOL sortInDescendingOrder;

/**
 * sortInDescendingOrder - Sorts based on order createion timstamp in descending order be default.
 * Set it to NO to sort in ascending order
 */
@property (strong, nonatomic) FlintOrderFilters *orderFilters;

@end
