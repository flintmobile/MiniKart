//
/*! @file FlintAPIConfig.h */
//  FlintConnect
//
//  Created by Nidhi on 3/11/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 *  @enum FlintConfigurationEnvironment
 *
 *  @brief Tthe environment to run Flint transaction on
 *
 *  @discussion Typically for development and testing, this should be on staging. This ensure the transaction does not go through the financial processing. Only use Production when you release the app.
 */
typedef NS_ENUM(NSInteger, FlintConfigurationEnvironment){
  EnvironmentStaging,
  EnvironmentProduction,
};

/*!
 *  @enum FlintAPILogLevel
 *
 *  @brief Log levels.
 *
 *  @discussion Note that setting the log at a higher level will print out all logging below that level. For example setting log level at APILogLevelError will also print out warning and info message. To only log a single level, set the logSingleLevel to YES.
 */
typedef NS_ENUM(NSInteger, FlintAPILogLevel){
  APILogLevelInfo = 0,        /*!< General Messages */
  APILogLevelWarning,         /*!< Recoverable Errors */
  APILogLevelError,           /*!< Unrecoverable Errors */
  APILogLevelDebug            /*!< Value tracing */
};



/*!
 *  @class FlintAPIConfig
 *
 *  @brief The configuration to run Flint Service.
 *  
 *  @discussion Setting this up before starting service and/or modified it later to suit your need. Note that some of the property required stopping the service before mutating.
 */
@interface FlintAPIConfig : NSObject

#pragma mark - Service Option

/*!
 *  @brief The API Key to start the flint service
 */
@property (copy, nonatomic) NSString *APIKey;

/*!
 *  @brief The environment on which flint service run against
 *
 *  @discussion Typically for development and testing, this should be on staging. This ensure the transaction does not go through the financial processing. Only use Production when you release the app.
 *
 *  @default EnvironmentStaging
 */
@property (assign, nonatomic) FlintConfigurationEnvironment environment;

/*!
 *  @brief Username to authenticate.
 *
 *  @discussion If username and password is specified, on startup, flint service will attempt to authenticate the user.
 */
@property (copy, nonatomic) NSString *username;

/*!
 *  @brief Password to authenticate.
 *
 *  @discussion If username and password is specified, on startup, flint service will attempt to authenticate the user.
 */
@property (copy, nonatomic) NSString *password;

/*!
 *  @brief SSO Token to authenticate
 *
 *  @discussion If an sso token is specified, on startup, flint service will attempt to authenticate the user. This feature will be supported in the future.
 */
@property (copy, nonatomic) NSString *ssoToken;

#pragma mark - Logging

/*!
 *  @brief The api logging level
 *
 *  @discussion Note that setting the log at a higher level will print out all logging below that level. For example setting log level at APILogLevelError will also print out warning and info message. To only log a single level, set the logSingleLevel to YES.
 *
 *  @default APILogLevelInfo
 */
@property (assign, nonatomic) FlintAPILogLevel logLevel;

/*!
 *  @brief print out log statement at one particular level
 *
 *  @discussion Setting this to YES will override the default logging behavior and only print out the log at the current logging level.
 *
 *  @default NO
 */
@property (assign, nonatomic) BOOL singleLogLevel;

#pragma mark - Convenient Accessor

/*!
 *  @brief The unique identifier for the authenticated account.
 */
@property (copy, nonatomic, readonly) NSString *accountUid;

/*!
 *  @brief The authentication token.
 */
@property (copy, nonatomic, readonly) NSString *authToken;

/*!
 *  @brief The shared config instance used by the flint service.
 *
 *  @return the shared instance
 */
+ (instancetype)sharedInstance;

@end
