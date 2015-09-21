//
/*! @file FlintActionTextField.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 6/24/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintLineTextField.h"

@class FlintActionTextField;

@protocol FlintActionTextFieldDelegate <NSObject>

@optional
- (void)actionTextFieldActionButtonTapped:(FlintActionTextField *)textField;

@end

IB_DESIGNABLE

@interface FlintActionTextField : FlintLineTextField

@property (weak, nonatomic) IBOutlet id<FlintActionTextFieldDelegate>actionDelegate;

#pragma mark - IBInspectable

/**
 *  The text for the action button
 */
@property (copy, nonatomic) IBInspectable NSString *actionText;

/**
 *  The size for the action button
 *  set this to CGSizeZero to enable dynamic scaling
 *  Default to CGSizeZero
 */
@property (assign, nonatomic) IBInspectable CGSize buttonSize;

/**
*  The background color of action button for normal state
*  Default to light gray
*/
@property (strong, nonatomic) IBInspectable UIColor *buttonColor;

/**
 *  The background color of action button for active state
 *  Default to SDK color
 */
@property (strong, nonatomic) IBInspectable UIColor *activeColor;

/**
 *  The color of the title of action button for normal state
 *  Default is dark gray
 */
@property (strong, nonatomic) IBInspectable UIColor *buttonTextColor;

@end

@interface FlintActionTextField (UIAccessors)

@property (strong, nonatomic, readonly) UIButton *actionButton;

@end