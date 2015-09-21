//
/*! @file FlintReceiptOptionView.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 6/24/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintActionTextField.h"

IB_DESIGNABLE

/*!
 *  @class FlintReceiptOptionView
 *
 *  @brief A prebuilt UI component to send sms and email receipt.
 */
@interface FlintReceiptOptionView : UIView <FlintActionTextFieldDelegate, UITextFieldDelegate>

#pragma mark - IBInspectable

/*!
 *  @brief The height for the text fields.
 *
 *  @default 50
 */
@property (assign, nonatomic) IBInspectable CGFloat textFieldHeight;

@end

@interface FlintReceiptOptionView (UIAccessors)

@property (strong, nonatomic, readonly) UIImageView *emailIconView;
@property (strong, nonatomic, readonly) FlintActionTextField *emailTextField;
@property (strong, nonatomic, readonly) UIImageView *smsIconView;
@property (strong, nonatomic, readonly) FlintActionTextField *smsTextField;

@end