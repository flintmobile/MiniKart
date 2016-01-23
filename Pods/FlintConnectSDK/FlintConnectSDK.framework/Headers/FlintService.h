//
/*! @file FlintService.h */
//  FlintConnect
//
//  Created by Nidhi on 3/4/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FlintAPIConfig.h"

typedef NS_ENUM(NSInteger, FlintServiceStatus) {
  ServiceStatusStarted,
  ServiceStatusConnected,
  ServiceStatusAuthenticated,
  ServiceStatusStopped,
};

extern NSString *const FlintServiceAccountKey;
extern NSString *const FlintServiceMerchantKey;
extern NSString *const FlintServiceErrorKey;

typedef void (^FlintServiceCompletion)(FlintServiceStatus status, NSDictionary *userInfo);

@interface FlintService : NSObject

/**
 *  Accessing the shared instance of the service
 *
 *  @return the flint service
 */
+ (FlintService *)sharedInstance;

/**
 *  The service status
 */
@property (assign, nonatomic, readonly) FlintServiceStatus status;

/**
 *  Start the Flint Service after all configuration have been done in [FlintAPIConfig sharedInstance]
 *  If username and password or ssoToken is provided in the configuration, this will also authenticated the user
 *  It is recommended to call this from didFinishLaunchingWithOptions.
 *  All FLint SDK calls should be made after the Flint Service has been successfully started.
 *
 *  @param completion the block to call when the Flint Service has started and/or authenticated
 *  @discussion the userInfo will contains Account, Merchant, or NSError object 
 *              for FlintServiceAccountKey, FlintServiceMerchantKey, FlintServiceErrorKey
 */
- (void)startServiceWithCompletion:(FlintServiceCompletion)completion;

/**
 *  Start the Flint Service with minimum configuration. This provide the opportunity to login the user later on
 *  It is recommended to call this from didFinishLaunchingWithOptions.
 *  All FLint SDK calls should be made after the Flint Service has been successfully started.
 *
 *  @param APIKey   The Api key provided on sign up
 *  @param environment  The environment for which flint service should be started - prod or staging
 *  @param completionHandler    The block to call when the Flint Service has started
 */
- (void)startWithAPIKey:(NSString *)apiKey environment:(FlintConfigurationEnvironment)environment completion:(FlintServiceCompletion)completion;

/**
 *  Authenticate a flint account.
 *
 *  @param username   The flint account username
 *  @param password   The flint account password
 */
- (void)loginWithUsername:(NSString *)username password:(NSString *)password completion:(FlintServiceCompletion)completion;

/**
 *  Destroy user session, and thus invalidate all api calls that required authentication
 *  This need to be called before stopping the service.
 *  Typically you won't call this if an ssoToken is provided
 */
- (void)logout;

/**
 *  Convenient check if FlintService is running
 *
 *  @return YES if status is not FlintServiceStatusStopped
 */
- (BOOL)isRunning;

/**
 *  Typically you probably won't need this. 
 *  However, if you need to modify the service configuration, call this first
 *  Stopping and restarting the service also log the user out.
 */
- (void)stopService;

/**
 *  Accessing information of the running service
 *
 *  @return the dictionary contains different account objects if the service is currently authenticated
 */
- (NSDictionary *)userInfo;

@end
