//
/*! @file FlintRoundButton.h */
//  FlintConnect
//
//  Created by PC on 4/11/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, FlintRoundButtonMode) {
  ButtonModeHighLight,        // providing only visual feedback on tap
  ButtonModeToggle,           // tap to change visual state, tap again to clear visual state
  ButtonModeSelection,        // tap to change visual state, set selected to NO to clear visual state
};

IB_DESIGNABLE

@interface FlintRoundButton : UIControl

/**
 *  The mode for visual feedback
 *  Default to ButtonModeHighLight
 */
@property (assign, nonatomic) FlintRoundButtonMode buttonMode;

@property (strong, nonatomic) UIColor *disabledColor;

#pragma mark - IBInspectable

/**
 *  The color for the border of the circle
 *  Default to be SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *lineColor;

/**
 *  The thickness of the border around the circle
 *  Default to be 2
 */
@property (assign, nonatomic) IBInspectable CGFloat lineWidth;

/**
 *  The image to be displayed on the button
 *  Default to nil
 */
@property (strong, nonatomic) IBInspectable UIImage *image;

/**
 *  The fix image frame for the image
 *  Set this to CGRectZero to enable dynamic frame calculation
 *  Default to CGRectZero
 */
@property (assign, nonatomic) IBInspectable CGRect imageFrame;

/**
 *  Inset the image
 *  Default to CGSize 0
 */
@property (assign, nonatomic) IBInspectable CGSize imageInset;

/**
 *  Whether or not the button should have title
 *  Default to YES
 */
@property (assign, nonatomic) IBInspectable BOOL titleEnabled;

/**
 *  The title label for the button
 *  Has no effect if titleEnabled is set to NO
 */
@property (copy, nonatomic) IBInspectable NSString *title;

/**
 *  The label text color
 *  Has no effect if titleEnabled is set to NO
 *  Default to be SDK Theme Color
 */
@property (strong, nonatomic) IBInspectable UIColor *titleColor;

/**
 *  Setting the font for title label
 *  Has no effect if titleEnabled is set to NO
 *  Default to be System Font
 *  If you are using custom font, please make sure to follow the steps in one of these blogs
 *  http://www.neevtech.com/blog/2013/11/22/how-to-add-custom-font-to-your-ios-based-app/
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

/**
 *  Setting the font size for title lable
 *  Has no effect if titleEnabled is set to NO
 *  Default to 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

@end

@interface FlintRoundButton (UIAccessors)

@property (strong, nonatomic, readonly) UILabel *titleLabel;

@end