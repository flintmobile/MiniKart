//
/*! @file FlintTipInputView.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 7/16/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol FlintTipInputViewDelegate;

IB_DESIGNABLE

/*!
 *  @class FlintTipInputView
 *
 *  @brief A prebuilt UI component to input custom tip.
 */
@interface FlintTipInputView : UIView

/*!
 *  @brief The view delegate.
 */
@property (weak, nonatomic) IBOutlet id<FlintTipInputViewDelegate>delegate;

#pragma mark - IBInspectable

/*!
 *  @brief The font name for texts on view.
 *
 *  @default SDK theme font name
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

/*!
 *  @brief The font size for texts on view.
 *
 *  @default 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/*!
 *  @brief The main color scheme.
 *
 *  @default SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/*!
 *  @brief Size of the 'Add Tip' button.
 *
 *  @default 220x44
 */
@property (assign, nonatomic) IBInspectable CGSize buttonSize;

/*!
 *  @brief The base amount before adding tip.
 *
 *  @default 0
 */
@property (assign, nonatomic) IBInspectable CGFloat baseAmount;

/*!
 *  @brief Whether the value is display as percentage.
 *
 *  @default YES
 */
@property (assign, nonatomic, getter=isPercentage) IBInspectable BOOL percentage;

/*!
 *  @brief The tip amount in percentage or value.
 */
@property (assign, nonatomic) IBInspectable CGFloat tipAmmount;

/*!
 *  @brief The dolar value of the tip
 *
 *  @return the dolar value for tip regardless of percentage mode or value mode
 */
- (CGFloat)tipValue;

@end



/**
 *  @protocol FlintTipInputViewDelegate
 *
 *  @brief Delegate methods for the view.
 */
@protocol FlintTipInputViewDelegate <NSObject>

@optional
/*!
 *  @brief Fire this on delegate when the add tip button is tapped
 *
 *  @param tipInputView the tip input view
 *  @param tipAmount    the tip amount added
 */
- (void)tipInputView:(FlintTipInputView *)tipInputView addedTipValue:(CGFloat)tipValue;

@end