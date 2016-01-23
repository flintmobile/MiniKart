//
//  FlintRiskDetector.h
//  FlintConnect
//
//  Created by PC on 9/16/15.
//  Copyright © 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const FlintRiskDetectorTDMOriginID;
extern NSString *const FlintRiskDetectorTMDApiKey;

@interface FlintRiskDetector : NSObject

@property (copy, nonatomic) NSString *sessionID;

+ (instancetype)sharedInstance;

/**
 *  Wrapper around Threat Metrix profiling
 *
 *  @param completion the completion block
 */
+ (void)startProfilingWithCompletion:(void (^)(NSString *sessionID))completion;

@end
