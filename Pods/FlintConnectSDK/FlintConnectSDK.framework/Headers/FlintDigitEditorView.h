//
/*! @file FlintDigitEditorView.h */
//  FlintConnect
//
//  Created by PC on 5/5/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FlintDigitEditorView;

@protocol FlintDigitEditorViewDelegate <NSObject>

@optional
- (void)digitEditorViewCursorReachFirst:(FlintDigitEditorView *)digitEditorView;
- (void)digitEditorViewCursorReachLast:(FlintDigitEditorView *)digitEditorView;
- (void)digitEditorViewCancelButtonTapped:(FlintDigitEditorView *)digitEditorView;

@end

IB_DESIGNABLE

@interface FlintDigitEditorView : UIView

@property (weak, nonatomic) IBOutlet id<FlintDigitEditorViewDelegate>delegate;

/**
 *  Replace the current editing digit
 *
 *  @param digit the character string to be replaced
 */
- (void)replaceCurrentIndexWithDigit:(NSString *)digit;

/**
 *  Reset the cursor to the start index
 */
- (void)reset;

/**
 *  Move the cursor forward if within range
 *
 *  @return the character text at the cursor
 */
- (NSString *)next;

/**
 *  Move the cursor backward if within range
 *
 *  @return the character text at the cursor
 */
- (NSString *)previous;

/**
 *  The digits text that has been edited
 *
 *  @return the edited digits
 */
- (NSString *)editedDigits;

#pragma mark - IBInspectable

/**
 *  The digits text to be edit
 */
@property (copy, nonatomic) IBInspectable NSString *editingDigits;

/**
 *  The index to start edit
 *  Default to 0
 */
@property (assign, nonatomic) IBInspectable NSUInteger startIndex;

/**
 *  The spacing between the characters
 *  Default to be 10
 */
@property (assign, nonatomic) IBInspectable CGFloat spacing;

/**
 *  The color for non-editing characters
 *  Default to be dark gray
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/**
 *  The color for the editing character
 *  Default to be SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *activeColor;

/**
 *  The font name for the characters
 *  Default to be SDK font name
 */
@property (copy, nonatomic) IBInspectable NSString *fontName;

/**
 *  The max font size for the characters.
 *  Default to be 60.0f
 *  They will automatically resize smaller as needed
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/**
 *  The image for the cancel button
 *  setting this to nil will hide the cancel button
 */
@property (strong, nonatomic) IBInspectable UIImage *cancelImage;

/**
 *  The size for cancel button
 *  Default to be 40x40
 */
@property (assign, nonatomic) IBInspectable CGSize buttonSize;

@end

@interface FlintDigitEditorView (UIAccessors)

@property (strong, nonatomic, readonly) UIButton *cancelButton;

/**
 *  Array of UILabel to use as place holder for editing;
 */
- (NSArray *)placeHolderLabels;

@end