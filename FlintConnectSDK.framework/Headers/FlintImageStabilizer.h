//
/*! @file FlintImageStabilizer.h */
//  FlintConnect
//
//  Created by PC on 4/20/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

/*!
 *  @enum FlintImageStabilizerMode
 *
 *  @brief Different way the image is considered stable
 */
typedef NS_ENUM(NSInteger, FlintImageStabilizerMode){
  ImageStabilizerModeUnknown,               /*!< Stability is unknown or not yet aquired */
  ImageStabilizerModeAutoFocus,             /*!< It is stable based on auto focus standard. */
  ImageStabilizerModeStableTimeReached,     /*!< It is stable based on time standard. */
};



@protocol FlintImageStabilizerDelegate;

/*!
 *  @class FlintImageStabilizer
 *
 *  @brief the stabilizer for image scanning
 */
@interface FlintImageStabilizer : NSObject

/*!
 *  @brief The threshold to determine temporary stability.
 *
 *  @discussion When vibration goes below the vibrationThreshold and stay within the vibrationTolerance for longer than the minStableInterval, stability status will be reported. Increase this value will make the stabilizer acquire temporary stable state easier and vice versa. 
 *  
 *  @default 2.5
 */
@property (assign, nonatomic) double vibrationThreshold;

/*!
 *  @brief The tolerance to keep being temporary stable.
 *
 *  @discussion When vibration goes below the vibrationThreshold and stay within the vibrationTolerance for longer than the minStableInterval, stability status will be reported. Increase this value will make the stabilizer stay in temporary stable longer and vice versa. 
 *  
 *  @default 0.2 (20 %).
 */
@property (assign, nonatomic) double vibrationTolerance;

/*!
 *  @brief The time from temporary stable to actual stable state.
 *
 *  @discussion When vibration goes below the vibrationThreshold and stay within the vibrationTolerance for longer than the minStableInterval, stability status will be reported. Decrease this value will shorter the time it takes to report stability status. However, the shorter the time is, the less accuracy you might have. This should be set to be long enough for the camera to aquire focus. 
 *
 *  @default 1 (second)
 */
@property (assign, nonatomic) NSTimeInterval minStableInterval;

/*!
 *  @brief Stability mode.
 *
 *  @default ImageStabilizerModeUnknown
 */
@property (assign, nonatomic) FlintImageStabilizerMode stableMode;

/*!
 *  Delegate for call back when stability aquired.
 */
@property (weak, nonatomic) id<FlintImageStabilizerDelegate>delegate;

/*!
 *  @brief Determine if stability update is running.
 *
 *  @return YES if it is running, NO otherwise
 */
- (BOOL)isUpdatingStability;

/*!
 *  @brief Start checking for stable state. 
 *  
 *  @discussion When the stable level aquired, the delegate will be fired. Duplicate call to this method resolve in no effect, just give warning.
 */
- (void)startStabilityUpdate;

/*!
 *  @brief Stop checking for stable state.
 *
 *  @discussion When stability status acquired, this is called automatically
 */
- (void)stopStabilityUpdate;

@end



/*!
 *  @protocol FlintImageStabilizerDelegate
 *
 *  @brief Delegate call back at different stage of the stabilizing process.
 *
 *  @discussion the image stabilizer use the core motion framework to detect current vibration displacement. When it detects a short moment of stability (constraint by the vibration threshold), it will first fire imageStabilizer:temporaryStable: method. If the stability continue long enough or focus has been locked in, it will fire imageStabilizerAquiredStability: method
 */
@protocol FlintImageStabilizerDelegate <NSObject>

@optional

/*!
 *  @brief Stability state is when temporary stable last more than min stable interval or auto focus acquired.
 *
 *  @param imageStabilizer The image stabilizer.
 */
- (void)imageStabilizerAquiredStability:(FlintImageStabilizer *)imageStabilizer;

- (void)imageStabilizerDidAquireThresholdLevel:(FlintImageStabilizer *)imageStabilizer;

- (void)imageStabilizer:(FlintImageStabilizer *)imageStabilizer isWithinTolerance:(BOOL)isInRange;

@end