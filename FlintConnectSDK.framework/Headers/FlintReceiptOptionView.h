//
/*! @file FlintReceiptOptionView.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 6/24/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintActionTextField.h"

@protocol FlintReceiptOptionViewDelegate;

/**
 *  @enum FlintReceiptOption
 *
 *  @brief To classified which receipt option user choose.
 */
typedef NS_ENUM(NSInteger, FlintReceiptOption){
  ReceiptOptionEmail = 0,       /*!< User choose to send receipt via email. */
  ReceiptOptionSMS,             /*!< User choose to send receipt via sms. */
};


IB_DESIGNABLE

/*!
 *  @class FlintReceiptOptionView
 *
 *  @brief A prebuilt UI component to send sms and email receipt.
 */
@interface FlintReceiptOptionView : UIView 

/*!
 *  @brief The view delegate
 */
@property (weak, nonatomic) IBOutlet id<FlintReceiptOptionViewDelegate>delegate;

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



/*!
 *  @protocol FlintReceiptOptionViewDelegate
 *
 *  @brief The view delegate.
 */
@protocol FlintReceiptOptionViewDelegate <NSObject>

@optional
/*!
 *  @brief The delegate call back when user tap send on one of the receipt option.
 *
 *  @param receiptOptionView The receipt option view
 *  @param option            The option to send receipt
 *  @param value             The value of that option
 */
- (void)receiptOptionView:(FlintReceiptOptionView *)receiptOptionView receiptSentWithOption:(FlintReceiptOption)option value:(NSString *)value;

@end
