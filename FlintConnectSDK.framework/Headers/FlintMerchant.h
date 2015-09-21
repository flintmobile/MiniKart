//
/*! @file FlintMerchant.h */
//  FlintConnect
//
//  Created by PC on 3/30/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"
#import "FlintAddress.h"
#import "FlintPhoneNumber.h"
#import <UIKit/UIKit.h>

@class FlintMerchantUpdateTemplate;
@class FlintMerchantUpdateDDATemplate;

/***************************************
 *  The Merchant Brief
 ***************************************/
@interface FlintMerchant : FlintDomainObject


/**
 *  The address of the business
 */
@property (strong, nonatomic) FlintAddress *address;

/**
 *  Business description
 */
@property (copy, nonatomic) NSString *businessDescription;

/**
 *  Business type
 */
@property (copy, nonatomic) NSString *type;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *campaignId;

/**
 *  Bank Account Number
 */
@property (copy, nonatomic) NSString *accountNumber;

/**
 *  Bank Routing Number
 */
@property (copy, nonatomic) NSString *routingNumber;

/**
 *  Check if DDA information is set
 */
@property (assign, nonatomic, getter=isDdaSet) BOOL ddaSet;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *defaultMemo;

/**
 *  TODO: what is this?
 */
@property (strong, nonatomic) NSNumber *estimatedWeeklySales;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *externalId;

/**
 *  Whether or not the business has invoice module enable
 */
@property (assign, nonatomic) BOOL hasInvoice;

/**
 *  Whether or not the business has online order module enable
 */
@property (assign, nonatomic) BOOL hasOnlineOrder;

/**
 *  Whether or not the business has transaction module enable
 */
@property (assign, nonatomic) BOOL hasTransaction;

/**
 *  The business home page
 */
@property (strong, nonatomic) NSURL *homePageUrl;

/**
 *  Copy the merchant also on when the customer is emailed the receipt
 */
@property (assign, nonatomic, getter=isBccActivated) BOOL bccActivated;

/**
 *  Whether or not the merchant enable tax
 */
@property (assign, nonatomic, getter=isTaxActivated) BOOL taxActivated;

/**
 *  TODO: what is this?
 */
@property (assign, nonatomic, getter=isTaxInfoSubmitted) BOOL taxInfoSubmitted;

/**
 *  Whether or not the merchant enable tax
 */
@property (assign, nonatomic, getter=isTipActivated) BOOL tipActivated;

/**
 *  The business logo
 */
@property (strong, nonatomic) NSURL *logo;

/**
 *  The key to uniquely identify a merchant
 */
@property (copy, nonatomic) NSString *merchantKey;

/**
 *  The name of the business
 */
@property (copy, nonatomic) NSString *businessName;

/**
 *  The key to uniquely identify the owner of the business
 */
@property (copy, nonatomic) NSString *ownerAccountKey;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *partner;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *partnerReseller;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *partnerUserId;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *partnerUserReferrerId;

/**
 *  The phone number for the business, may or may not be the same as owner's phone number
 */
@property (strong, nonatomic) FlintPhoneNumber *phoneNumber;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *profileName;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *pymtSvcMerchantId;

/**
 *  TODO: what is this?
 */
@property (strong, nonatomic) NSNumber *qboStatus;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *sfdcAccountId;

/**
 *  The taxId
 */
@property (copy, nonatomic) NSString *taxId;

/**
 *  Last four of SSN
 */
@property (copy, nonatomic) NSString *ssnLast4;

/**
 *  Is Tax Id set for the merchant
 */
@property (assign, nonatomic, getter=isTaxInfoSet) BOOL taxInfoSet;

/**
 *  The percentage to tax on all transactions
 */
@property (strong, nonatomic) NSNumber *taxPercent;

/**
 *  TODO: why is this here?
 */
@property (copy, nonatomic) NSString *userAgent;

/**
 *  Get merchant information from server
 *
 *  @param completionHandler   The block called after the async fetch merchant operation completes (optional)
 */
+ (void)fetchWithCompletionHandler:(FlintRequestHandler)handler;

/**
 *  Get an instance of merchant update template to use for updating any merchant information
 *
 */
- (FlintMerchantUpdateTemplate *)getUpdateTemplate;

/**
 *  Get an instance of merchant update DDA template to update the DDA information
 *
 */
- (FlintMerchantUpdateDDATemplate *)getUpdateDDATemplate;

/**
 *  Update merchant information
 *
 *  @param updateTemplate  Update template with the information to be updated (required)
 *  @param completionHandler   The block called after the async update merchant operation completes (optional)
 */
- (void)updateWithTemplate:(FlintMerchantUpdateTemplate *)updateTemplate completionHandler:(FlintRequestHandler)handler;

/**
 *  Upload merchant logo
 *
 *  @param logo  The image to upload (required)
 *  @param completionHandler   The block called after the async upload logo operation completes (optional)
 */
+ (void)uploadLogo:(UIImage *)logo completionHandler:(FlintRequestHandler)handler;

/**
 *  Get merchant logo from the server
 *
 *  @param completionHandler   The block called after the async download logo operation completes (optional). The opResult is of type UIImage.
 */
+ (void)downloadLogoWithCompletionHandler:(FlintRequestHandler)handler;

/**
 *  Update the DDA information
 *
 *  @param completionHandler   The block called after the async update DDA operation completes (optional). The opResult is of type FlintMerchant.
 */
- (void)updateDDA:(FlintMerchantUpdateDDATemplate *)updateDDATemplate completionHandler:(FlintRequestHandler)handler;

@end


/*****************************************
 *  The Merchant Update Template
 ****************************************/


@interface FlintMerchantUpdateTemplate : NSObject

/**
 *  The address of the business
 */
@property (strong, nonatomic) FlintAddress *address;

/**
 *  Business description
 */
@property (copy, nonatomic) NSString *businessDescription;

/**
 *  The name of the business
 */
@property (copy, nonatomic) NSString *businessName;
/**
 *  Bank Account Number
 */
@property (copy, nonatomic) NSString *accountNumber;

/**
 *  Bank Routing Number
 */
@property (copy, nonatomic) NSString *routingNumber;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *defaultMemo;

/**
 *  TODO: what is this?
 */
@property (strong, nonatomic) NSNumber *estimatedWeeklySales;

/**
 *  The business home page
 */
@property (strong, nonatomic) NSURL *homePageUrl;

/**
 *  Copy the merchant also on when the customer is emailed the receipt
 */
@property (assign, nonatomic, getter=isBccActivated) BOOL bccActivated;

/**
 *  Whether or not the merchant enable tax
 */
@property (assign, nonatomic, getter=isTaxActivated) BOOL taxActivated;

/**
 *  TODO: what is this?
 */
@property (copy, nonatomic) NSString *partner;

/**
 *  The phone number for the business, may or may not be the same as owner's phone number
 */
@property (strong, nonatomic) FlintPhoneNumber *phoneNumber;

/**
 *  The taxId
 */
@property (copy, nonatomic) NSString *taxId;

/**
 *  TODO: what is this?
 */
@property (strong, nonatomic) NSNumber *taxInfoStatus;

/**
 *  The percentage to tax on all transactions
 */
@property (strong, nonatomic) NSNumber *taxPercent;

/**
 *  SSN of merchant owner
 */
@property (copy, nonatomic) NSString *ssn;

@end


/*****************************************
 *  The Merchant Update DDA Template
 ****************************************/

@interface FlintMerchantUpdateDDATemplate : NSObject

/**
 *  Bank Account Number (required)
 */
@property (copy, nonatomic) NSString *accountNumber;

/**
 *  Routing Number (required)
 */
@property (copy, nonatomic) NSString *routingNumber;

/**
 *  Buisiness tax identifier. Optional if SSN is passsed in
 */
@property (copy, nonatomic) NSString *taxId;

/**
 *  Social security number. Optional if taxId is passsed in
 */
@property (copy, nonatomic) NSString *ssn;

@end
