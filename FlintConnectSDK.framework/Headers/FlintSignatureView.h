//
/*! @file FlintSignatureView.h */
//  FlintConnect
//
//  Created by PC on 5/1/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FlintSignatureView;

@protocol FlintSignatureViewDelegate <NSObject>

@optional
/**
 *  Delegate call when cancel button is tapped
 *
 *  @param signatureView the signature view
 */
- (void)signatureViewDidCancel:(FlintSignatureView *)signatureView;

/**
 *  Delegate call when done button is tapped
 *
 *  @param signatureView  the signature view
 *  @param signatureImage the signature image, nil if user tap done without signing
 */
- (void)signatureView:(FlintSignatureView *)signatureView didSign:(UIImage *)signatureImage;

@end

IB_DESIGNABLE

@interface FlintSignatureView : UIView

@property (weak, nonatomic) IBOutlet id<FlintSignatureViewDelegate>delegate;

#pragma mark - IBInspectable

/**
 *  Specify the height for the bottom bar below the divider;
 *  Default to be 60.0
 */
@property (assign, nonatomic) IBInspectable CGFloat dividerHeight;

/**
 *  Color for title text & divider color
 *  Default to be dark gray
 */
@property (strong, nonatomic) IBInspectable UIColor *titleColor;

/**
 *  Color for agreemnt text
 *  Default to be gray
 */
@property (strong, nonatomic) IBInspectable UIColor *agreementColor;

/**
 *  Color for the buttons
 *  Default to be SDK Theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *buttonColor;

/**
 *  The font name for title, text, and button
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

@end

@interface FlintSignatureView (UIAccessors)

@property (strong, nonatomic, readonly) UILabel *endorsementLabel;
@property (strong, nonatomic, readonly) UIButton *cancelButton;
@property (strong, nonatomic, readonly) UIButton *clearButton;
@property (strong, nonatomic, readonly) UILabel *titleLabel;
@property (strong, nonatomic, readonly) UILabel *agreementLabel;
@property (strong, nonatomic, readonly) UIButton *doneButton;

@end