//
/*! @file FlintCardScanner.h */
//  FlintConnect
//
//  Created by PC on 4/16/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintImageStabilizer.h"

@protocol FlintCardScannerDelegate;

@class FlintScannerSettings;

IB_DESIGNABLE

@interface FlintCardScanner : UIView

@property (weak, nonatomic) id<FlintCardScannerDelegate>delegate;

/**
 *  Whether or not we want torch enabled on the camera.
 *  Only work on device that has torch supported
 *  Default to NO
 */
@property (assign, nonatomic) BOOL enableTorch;

/**
 *  Adjusting the preset to low resolution on device with limited memory
 *  Default to NO;
 */
@property (assign, nonatomic) BOOL shouldCaptureLowResolution;

/**
 *  Determine if auto scan should be enable
 *  If this is set to NO, use captureScannedImage to manually retrieve the image
 *  Default to YES;
 */
@property (assign, nonatomic) BOOL enableAutoScan;

/**
 *  The delay before auto scan process
 *  Default to 3 seconds
 */
@property (assign, nonatomic) NSTimeInterval autoScanDelay;

/**
 *  The image stabilizer for auto scan detection
 */
@property (strong, nonatomic, readonly) FlintImageStabilizer *imageStabilizer;

/**
 *  Determine if a scan session is currently running
 *  will be set to YES after startScanningSession: called
 *  use KVO to detect when this status change
 */
@property (assign, nonatomic, readonly) BOOL scanSessionActive;

/**
 *  Determine if this scan session is a demo animation
 */
@property (assign, nonatomic, readonly) BOOL isAnimatingScan;

/**
 *  the scanned image capture automaticly using auto capture algorithm
 *  use KVO to detect when the image is captured
 */
@property (strong, nonatomic, readonly) UIImage *scannedImage;

/**
 *  The orientation of the scanner
 *
 *  Default is landscape right
 */
@property (assign, nonatomic) UIInterfaceOrientation scanOrientation;

/**
 *  Prepare all the session wiring necessary with the camera to prepare for capturing
 *  If any error occur during the session setup, capturing scan image will return nil;
 *
 *  @param error any error occur during the session setup
 *  @return YES if the scan session is started
 */
- (BOOL)startScanningSession:(NSError **)error;

/**
 *  Generate the scan image manually. This is done asynchronously
 *  The scannedImage will receive the value once processing completed
 *
 *  @param animated whether we should display the progress stripe before capture
 */
- (void)captureScannedImage:(BOOL)animated;

/**
 *  Clean up session information. This should be called when you are done with capturing image
 */
- (void)stopScanningSession;

/**
 *  Starting a demo animation with real camera session
 */
- (BOOL)startAnimateCardScanSession:(NSError **)error;

/**
 *  Stoping the demo animation
 */
- (void)stopAnimateCardScanSession;

/**
 *  Whether or not the scanner support torch
 *
 *  @return YES if the hardware support torch, NO otherwise
 */
- (BOOL)torchSupported;

/**
 *  A convenient way to apply a preset settings for the scanner
 *
 *  @param settings the scanner settings to be applied
 */
- (void)applyScannerSettings:(FlintScannerSettings *)settings;

/**
 *  Convenient way to retrieve the current settings of the scanner
 *
 *  @return the scanner settings
 */
- (FlintScannerSettings *)currentScannerSettings;

#pragma mark - IBInspectable

/**
 *  The border width of the scan box;
 *  Default to 3.0f
 */
@property (assign, nonatomic) IBInspectable CGFloat borderWidth;

/**
 *  The frame of the scanning box
 *  Default to CGRectZero for dynamic scaling
 */
@property (assign, nonatomic) IBInspectable CGRect scanFrame;

/**
 *  The frame color when card scanning is not active
 *  Default to be light gray color
 */
@property (strong, nonatomic) IBInspectable UIColor *frameColor;

/**
 *  The frame color when card scanning start acquiring focus
 *  Default to be blue
 */
@property (strong, nonatomic) IBInspectable UIColor *focusColor;

/**
 *  The frame color when finish scanning card image
 *  Default to be green
 */
@property (strong, nonatomic) IBInspectable UIColor *captureColor;

@end

@interface FlintCardScanner (UIAccessors)

@property (strong, nonatomic, readonly) UIView *scanLineView;

- (CGRect)scanningViewDefaultFrame;

@end

@interface FlintScannerSettings : NSObject

/**
 *  The orientation of the scanner, currently support portrait and landscape right
 *  Default is landscape right
 */
@property (assign, nonatomic) UIInterfaceOrientation scanOrientation;

/**
 *  when vibration go below the vibrationThreshold and stay within the vibrationTolerance
 *  for longer than the minStableInterval,
 *  stability status will be reported.
 *  Increase this value will make the stabilizer acquire focus lock (not stability) easier and vice versa
 *  Default to 2.5
 */
@property (assign, nonatomic) float vibrationThreshold;

/**
 *  when vibration go below the vibrationThreshold and stay within the vibrationTolerance
 *  for longer than the minStableInterval,
 *  stability status will be reported.
 *  Increaase this value will make the stabilizer stay in focus lock longer and vice versa
 *  Default to 0.15 (15 %)
 */
@property (assign, nonatomic) float vibrationTolerance;

/**
 *  when vibration go below the vibrationThreshold and stay within the vibrationTolerance
 *  for longer than the minStableInterval,
 *  stability status will be reported.
 *  Decrease this value will shorter the time it takes to report stability status.
 *  However, the shorter the time is, the less accuracy you might have.
 *  This should be set to be long enough for the camera to aquire focus
 *  Default to 1 second
 */
@property (assign, nonatomic) NSTimeInterval minStableInterval;

/**
 *  The delay before auto scan process
 *  Default to 3 seconds
 */
@property (assign, nonatomic) NSTimeInterval startupDelay;

/**
 *  Determine if auto scan should be enable
 *  If this is set to NO, use captureScannedImage to manually retrieve the image
 *  Default to YES;
 */
@property (assign, nonatomic) BOOL enableAutoScan;

@end

@protocol FlintCardScannerDelegate <NSObject>

@optional
- (void)cardScanner:(FlintCardScanner *)cardScanner willBeginStable:(BOOL)isStable;

@end