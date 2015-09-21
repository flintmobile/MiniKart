//
/*! @file FlintInvoice.h */
//  FlintConnect
//
//  Created by Nidhi Jain on 7/9/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"
#import "FLintPayment.h"
#import "FlintContact.h"

@class FlintInvoiceCreateTemplate;

/*! FlintInvoiceStatus enum defining invoice status */
typedef NS_ENUM(NSInteger, FlintInvoiceStatus)
{
  FlintInvoiceStatusSent,   /*! Invoice created and sent to a customer */
  FlintInvoiceStatusVoided, /*! Invoice has been voided */
  FlintInvoiceStatusPaid,   /*! Invoice was paid by the customer */
};

@interface FlintInvoice : FlintDomainObject

/**
 *  Unique identifier of the invoice
 */
@property(strong, nonatomic) NSString *uid;

/**
 *  Date/Time when the Invoice was created
 */
@property(strong, nonatomic) NSDate *createdDate;

/**
 *  The customer contact inforamtion, if different than order contact.
 *  Leave this empty if the invoice is to be sent to the same contact information
 *  that is on the order. Atleast one of the contact information should be there
 *  to send an Invoice.
 */
@property(strong, nonatomic) NSString *customerName;

/**
 *  Consumer email address
 */
@property(strong, nonatomic) FlintEmailAddress *emailAddress;

/**
 *  Consumer phone number
 *  @optional
 */
@property(strong, nonatomic) FlintPhoneNumber *phoneNumber;

/**
 *  Set it to true if the merchant should also be cc'd
 *  on the invoice email. Defaults to NO.
 */
@property(assign, nonatomic) BOOL copyMerchant;

/**
 *  Invoice human readable Id for displaying
 */
@property (copy, nonatomic) NSString *invoiceNumber;

/**
 *  Date by which payment is due
 */
@property (strong, nonatomic) NSDate *dueDate;

/**
 *  Date on which invoice was sent to the customer
 */
@property (strong, nonatomic) NSDate *sendDate;

/**
 *  Date on which the invoice was paid by the customer
 *  or marked as paid by the Flint merchant
 */
@property (strong, nonatomic) NSDate *paidDate;

/**
 *  List of email addresses to be cc'd on the Invoive Email
 */
@property (copy, nonatomic) NSArray *emailCcRecipients;

/**
 *  Additional description for invoice. 
 *  The customer will see this on the sent Invoice
 */
@property (copy, nonatomic) NSString *notes;

/**
 *  Order Id with for which this invoice is created
 */
@property (copy, nonatomic) NSString *orderUid;

// TODO: may be removed
/**
 *  Information about payment applied to the invoice
 */
@property (strong, nonatomic) FlintPayment *payment;

/**
 *  Status of the invoice
 */
@property (assign, nonatomic) FlintInvoiceStatus status;

/**
 *  Return a template to create a Flint invoice
 *  Configure the properties of this template to provide invoice information. When you are
 *  ready to send the invoice, call sendInvoice:compleion: on the order you want to send the invoice for
 *
 *  @return the invoice template.
 */
+ (FlintInvoiceCreateTemplate*)templateToCreate;


/**
 *  Mark the invoice as Paid. The payment method can be only cash or check
 *  If it was paid by credit card, the status will be paid in the system after
 *  the payment is processed by the backend
 *
 *  @param FlintPaymentMethod  Acceptable values are FlintPaymentCashMethod and FlintPaymentCheckMethod
 *  @param completionHandler   The block called after the async operation updating the status of the invocie 
 *                             completes (optional)
 */
- (void)payInvoice:(FlintPaymentMethod)paymentMethod completionHandler:(FlintRequestHandler)completionHandler;

/**
 *  Resend invoice to the customer
 *
 *  @param completionHandler   The block called after the async resend invoice operation completes (optional)
 */
- (void)resendWithCompletionHandler:(FlintRequestHandler)completionHandler;


/**
 *  Cancel the invoice. A payment cannot be applied once the invocie is voided
 *
 *  @param completionHandler   The block called after the async void invoice operation completes (optional)
 */
- (void)voidWithCompletionHandler:(FlintRequestHandler)completionHandler;

// TODO: to implement
/**
 *  Delete the invoice.
 *
 *  @param completionHandler   The block called after the async void invoice operation completes (optional)
 */
- (void)deleteWithCompletionHandler:(FlintRequestHandler)completionHandler;

@end


@interface FlintInvoiceCreateTemplate : NSObject

/**
 *  Date by which payment is due
 */
@property (strong, nonatomic) NSDate *dueDate;

/**
 *  The customer contact inforamtion, if different than order contact.
 *  Leave this empty if the invoice is to be sent to the same contact information
 *  that is on the order. Atleast one of the contact information should be there
 *  to send an Invoice.
 */
@property(strong, nonatomic) NSString *customerName;

/**
 *  Consumer email address
 */
@property(strong, nonatomic) FlintEmailAddress *emailAddress;

/**
 *  Consumer phone number
 *  @optional
 */
@property(strong, nonatomic) FlintPhoneNumber *phoneNumber;

/**
 *  Set it to true if the merchant should also be cc'd
 *  on the invoice email. Defaults to NO.
 *  @optional
 */
@property(assign, nonatomic) BOOL copyMerchant;

/**
 *  List of email addresses to be cc'd on the Invoive Email
 *  @optional
 */
@property (copy, nonatomic) NSArray *emailCcRecipients;

/**
 *  Additional description for invoice.
 *  The customer will see this on the sent Invoice email.
 *  @optional
 */
@property (copy, nonatomic) NSString *notes;

@end
