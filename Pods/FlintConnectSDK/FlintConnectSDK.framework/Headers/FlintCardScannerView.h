//
/*! @file FlintCardScannerView.h */
//  FlintConnect
//
//  Created by PC on 4/20/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintCardScanner.h"

@protocol FlintCardScannerViewDelegate;

IB_DESIGNABLE

/*!
 *  @class FlintCardScannerView
 *  
 *  @brief A prebuilt UI component to scan credit card.
 *
 *  @discussion This also include other configurations such as toggle torch, manual/auto scan, ...
 */
@interface FlintCardScannerView : UIView

/*!
 *  @brief The view delegate
 */
@property (weak, nonatomic) IBOutlet id<FlintCardScannerViewDelegate>delegate;

/*!
 *  @brief Whether or not we should have a manual scan option displayed
 *
 *  @default YES
 */
@property (assign, nonatomic) BOOL allowManualScan;

/*!
 *  @brief Applying the settings for the scanner.
 *
 *  @discussion Convenient pipe-through method to set the scanner settings. For individual setting modification, access the imageStablizer or the cardScanner directly.
 *
 *  @param scannerSettings The new scanner settings
 */
- (void)applyScannerSettings:(FlintScannerSettings *)scannerSettings;

/*!
 *  @brief Retrieve the current settings of the scanner.
 *
 *  @discussion Convenient pipe-through method to retrieve the scanner settings. To access each setting individually, use the imageStabilizer or the cardScanner accessor directly. Typically you would call this to retrieve the current settings, modify it and call applyScannerSettings: to apply changes.
 *
 *  @return The scanner settings
 */
- (FlintScannerSettings *)currentScannerSettings;

#pragma mark - IBInspectable

/*!
 *  @brief Color use for text, title, etc..
 *
 *  @default White
 */
@property (strong, nonatomic) IBInspectable UIColor *textColor;

/*!
 *  @brief Main color scheme.
 *
 *  @default SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/*!
 *  @brief Font name for text elements on the view.
 *
 *  @dicussion If you are using custom font, please make sure to follow the steps in one of these blogs\n
 *  http://www.neevtech.com/blog/2013/11/22/how-to-add-custom-font-to-your-ios-based-app/.
 *
 *  @default SDK theme font name
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

@end



@interface FlintCardScannerView (UIAccessors)

@property (strong, nonatomic, readonly) FlintCardScanner *cardScanner;

@property (strong, nonatomic, readonly) UILabel *confirmationLabel;
@property (strong, nonatomic, readonly) UIImageView *securityImageView;

@property (strong, nonatomic, readonly) UIBarButtonItem *backButton;
@property (strong, nonatomic, readonly) UIBarButtonItem *reScanButton;
@property (strong, nonatomic, readonly) UIBarButtonItem *doneButtonItem;
@property (strong, nonatomic, readonly) UIButton *doneButton;
@property (strong, nonatomic, readonly) UIButton *scanButton;
@property (strong, nonatomic, readonly) UIBarButtonItem *manualButton;
@property (strong, nonatomic, readonly) UIBarButtonItem *torchButton;

- (void)setDoneTitle:(NSString *)doneTitle;

@end



/*!
 *  @protocol FlintCardScannerViewDelegate
 *
 *  @brief Delegate methods for card scanner view.
 */
@protocol FlintCardScannerViewDelegate <NSObject>

@optional
/*!
 *  @brief Give the hook for when the back button is tapped.
 *
 *  @param cardScannerView the card scanner view
 */
- (void)cardScannerViewBackButtonTapped:(FlintCardScannerView *)cardScannerView;

/*!
 *  @brief Give the hook for when the manual button is tapped.
 *
 *  @param cardScannerView the card scanner view
 */
- (void)cardScannerViewManualButtonTapped:(FlintCardScannerView *)cardScannerView;

/*!
 *  @brief Give the hook for when the rescan action will initiated
 *
 *  @param cardScannerView the card scanner view
 */
- (void)cardScannerViewWillStartRescan:(FlintCardScannerView *)cardScannerView;

/*!
 *  @brief Give the hook for when the rescan action did initiated
 *
 *  @discussion The rescan behavior is handle internally, this give the opportunity to do additional tasks after the rescan initiated.
 *
 *  @param cardScannerView the card scanner view
 */
- (void)cardScannerViewDidStartReScan:(FlintCardScannerView *)cardScannerView;

/*!
 *  @brief Give the hook when the image finished scanning
 *
 *  @discussion This give the opportunity to take action even before the user tapped on the "Use" button
 *
 *  @param cardScannerView the card scanner view
 *  @param image           the scanned image
 */
- (void)cardScannerView:(FlintCardScannerView *)cardScannerView didScanImage:(UIImage *)image;

/*!
 *  @brief Give the hook for when the done button is tapped with or without the image scanned.
 *  
 *  @discussion Image will be nil if the user tap the done button without scanning.
 *
 *  @param cardScannerView the card scanner view
 *  @param image the image scanned
 */
- (void)cardScannerView:(FlintCardScannerView *)cardScannerView useImage:(UIImage *)image;

@end