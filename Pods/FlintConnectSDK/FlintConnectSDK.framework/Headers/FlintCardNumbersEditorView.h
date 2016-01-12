//
/*! @file FlintCardNumbersEditorView.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 5/6/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FlintDigitEditorView;

IB_DESIGNABLE

@interface FlintCardNumbersEditorView : UIControl

#pragma mark - IBInspectable

/**
 *  The strings to be edit separated by space
 *  e.g. @"3542 1234 4441 4555"
 */
@property (copy, nonatomic) IBInspectable NSString *editingNumbers;

/**
 *  The color for buttons
 *  Default to be SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/**
 *  The font name for buttons and the digit editor
 *  Default to be SDK font
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

/**
 *  The font size for buttons
 *  Default to be SDK button font size
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/**
 *  The spacing between the buttons
 *  Default to be 5
 */
@property (assign, nonatomic) IBInspectable CGFloat spacing;

@end

@interface FlintCardNumbersEditorView (UIAccessors)

@property (strong, nonatomic, readonly) FlintDigitEditorView *digitEditorView;

/**
 *  Array of UIButton to use as place holder for editing;
 */
- (NSArray *)placeHolderButtons;

/**
 *  Use this to modify the behavior of keyboard input
 *
 *  @return the textfield to adjust keyboard input
 */
- (UITextField *)keyboardInput;

@end