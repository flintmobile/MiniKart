//
/*! @file FlintPermissions.h */
//  FlintConnect
//
//  Created by PC on 3/27/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"

@interface FlintPermissions : FlintDomainObject

/**
 *  Is the merchant allowed to process refunds
 */
@property (assign, nonatomic) BOOL allowRefunds;

/**
 *  Is the merchant allowed to send Invoices
 */
@property (assign, nonatomic) BOOL allowInvoices;

/**
 *  Should the staff's contact be shown on transaction receipt
 */
@property (assign, nonatomic) BOOL allowStaffContact;

/**
 *  Should the merchant be copied on the any receipt sent to the customer
 */
@property (assign, nonatomic) BOOL allowReceiptCopy;

@end
