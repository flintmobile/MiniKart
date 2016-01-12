//
/*! @file FlintScanResult.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 5/13/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintScannedDigit.h"
#import "FlintModelEnum.h"
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, FlintScanStatus) {
  ScanStatusCreated,
  ScanStatusProcessing,
  ScanStatusSuccess,
  ScanStatusError
};

@interface FlintScanResult : FlintDomainObject

/**
 *  The overall confidence score of the scan result. Max is 100, min is 0.
 *  For individual digit confidence score, use FlintScannedDigit instead
 */
@property (assign, nonatomic) NSUInteger confidenceLevel;

/**
 *  The card number that is converted from the scan image
 */
@property (copy, nonatomic) NSString *number;

/**
 *  the unique identifier for the scan
 */
@property (copy, nonatomic) NSString *scanKey;

/**
 *  the array of FlintScannedDigit to describe the accuracy of the scan
 */
@property (copy, nonatomic) NSArray *scannedDigits;

/**
 *  the scan status
 */
@property (assign, nonatomic) FlintScanStatus status;

/**
 *  The card type (e.g. amex, discover, ...)
 */
@property (assign, nonatomic) FlintCreditCardType type;

/**
 *  After uploading, periodically check the scan result will give the status of the scan processing
 *
 *  @param completion completion block return a FlintScanResult object and any error occur
 */
- (void)checkScanResultWithCompletion:(FlintRequestHandler)completion;

/**
 *  Upload the scan image to be converted to number
 *  On completion, the FlintScanResult object will have the scanKey but may not have the scannedDigits ready yet
 *
 *  @param image            the image of credit card number
 *  @param compressionRate  the jpeg compression rate for the image before uploading
 *  @param completion       completion block return a FlintScanResult object and any error occur
 */
+ (void)uploadScanImage:(UIImage *)image compression:(float)compressionRate completion:(FlintRequestHandler)completion;

@end
