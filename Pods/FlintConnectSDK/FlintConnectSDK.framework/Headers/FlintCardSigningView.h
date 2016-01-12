//
/*! @file FlintCardSigningView.h */
//  FlintConnect
//
//  Created by PC on 5/4/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintTipSelectionView.h"
#import "FlintSignatureView.h"

@protocol FlintCardSigningViewDelegate;

IB_DESIGNABLE

/*!
 *  @class FlintCardSigningView
 *
 *  @brief A prebuilt UI component to capture signature.
 */
@interface FlintCardSigningView : UIView

/*!
 *  @brief The view delegate.
 */
@property (weak, nonatomic) IBOutlet id<FlintCardSigningViewDelegate>delegate;

/*!
 *  @brief The tip amount in currency.
 */
@property (assign, nonatomic) CGFloat tipAmount;

/*!
 *  @brief Base amount + tip in currency.
 */
@property (assign, nonatomic, readonly) CGFloat totalAmount;

#pragma mark - IBInspectable

/*!
 *  @brief Main color scheme.
 *
 *  @default SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/*!
 *  @brief The height for header section which include the amount value, tip, etc...
 *
 *  @default 75
 */
@property (assign, nonatomic) IBInspectable CGFloat headerHeight;

/*!
 *  @brief Font name for text elements on the view.
 *
 *  @dicussion If you are using custom font, please make sure to follow the steps in one of these blogs\n
 *  http://www.neevtech.com/blog/2013/11/22/how-to-add-custom-font-to-your-ios-based-app/.
 *
 *  @default SDK theme font name
 */
@property (strong, nonatomic) IBInspectable NSString *fontName;

/*!
 *  @brief The sub-total amount before tip.
 *
 *  @default 0
 */
@property (assign, nonatomic) IBInspectable CGFloat baseAmount;

/*!
 *  @brief The tip selection values.
 *
 *  @default [0.05,0.1,0.15]
 */
@property (assign, nonatomic) IBInspectable NSString *tipSelections;

@end



@interface FlintCardSigningView (UIAccessors)

@property (strong, nonatomic, readonly) UILabel *amountTitleLabel;
@property (strong, nonatomic, readonly) UILabel *amountValueLabel;
@property (strong, nonatomic, readonly) UILabel *tipTitleLabel;
@property (strong, nonatomic, readonly) FlintTipSelectionView *tipSelectionView;
@property (strong, nonatomic, readonly) FlintSignatureView *signatureView;

@end



/*!
 *  @protocol FlintCardSigningViewDelegate
 *
 *  @brief Delegate methods for card signature view.
 */
@protocol FlintCardSigningViewDelegate <NSObject>

@optional
/*!
 *  @brief Delegate firing this when other tip option is selected.
 *
 *  @discussion Use tipAmount property to configure the custom tip.
 *
 *  @param cardSigningView the card signing view
 */
- (void)cardSigningViewSelectOtherTipOption:(FlintCardSigningView *)cardSigningView;

/*!
 *  @brief Delegate firing this when user cancel the signing via cancel button.
 *
 *  @param cardSigningView the card signing view
 */
- (void)cardSigningViewCancelSigning:(FlintCardSigningView *)cardSigningView;

/*!
 *  @brief Delegate firing this when user complete the signing via done button.
 *
 *  @param cardSigningView the card signing view
 *  @param amount          the total amount (base amount + tip)
 *  @param signatureImage  the signature image, can be nil if user tap done without signing
 */
- (void)cardSigningView:(FlintCardSigningView *)cardSigningView signedForAmount:(CGFloat)amount signatureImage:(UIImage *)signatureImage;

@end