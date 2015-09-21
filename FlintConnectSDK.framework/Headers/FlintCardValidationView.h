//
/*! @file FlintCardValidationView.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 5/7/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintCardValidator.h"
#import "FlintCardNumbersEditorView.h"

IB_DESIGNABLE

/*!
 *  @class FlintCardValidationView
 *
 *  @brief A prebuilt UI component for card number validation and editing.
 */
@interface FlintCardValidationView : UIView

/*!
 *  @brief Validation status.
 */
@property (assign, nonatomic, readonly) FlintCardValidationStatus validationStatus;

/*!
 *  @brief Toggle the visibility of the validation status bar.
 *
 *  @discussion This is useful when keyboard appear and the focus is editing
 *
 *  @param visible is visible
 *  @param animate should come with animation or not
 */
- (void)toggleStatusBar:(BOOL)visible animate:(BOOL)animate;

#pragma mark - IBInspectable

/*!
 *  @brief The card number to be validate.
 */
@property (strong, nonatomic) IBInspectable NSString *cardNumber;

/*!
 *  @brief The validation image of the card number.
 */
@property (strong, nonatomic) IBInspectable UIImage *cardNumberImage;

/*!
 *  @brief The status icon when the card is valid.
 */
@property (strong, nonatomic) IBInspectable UIImage *validIcon;

/*!
 *  @brief The status icon when the card is invalid.
 */
@property (strong, nonatomic) IBInspectable UIImage *invalidIcon;

/*!
 *  @brief The font name for the number editor.
 *
 *  @default SDK theme font name
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

/*!
 *  @brief The font size for the number editor
 *
 *  @default SDK button font size
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/*!
 *  @brief Main color scheme
 *
 *  @default SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

@end



@interface FlintCardValidationView (UIAccessors)

@property (strong, nonatomic, readonly) UIImageView *validationImageView;
@property (strong, nonatomic, readonly) UIImageView *cardBrandImageView;

- (UIImageView *)cardNumberImageView;
- (FlintCardNumbersEditorView *)cardNumberEditor;

@end