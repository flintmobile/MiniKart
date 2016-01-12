//
/*! @file FlintTextEntryView.h */
//  FlintConnect
//
//  Created by PC on 4/9/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "FlintLineTextField.h"

@class FlintTextEntryView;

@protocol FlintTextEntryViewDelegate <NSObject>

@optional
/**
 *  When the text entry is fully entered
 *
 *  @param textEntryView the text-entry view
 *  @param textField     the textfield on the text-entry view
 */
- (void)textEntryView:(FlintTextEntryView *)textEntryView completeEntryForTextField:(FlintTextField *)textField;

/**
 *  When the text entry change
 *
 *  @param textEntryView the text-entry view
 *  @param textField     the textfield on the text-entry view
 */
- (void)textEntryViewValidationChanged:(FlintTextEntryView *)textEntryView;

@end

IB_DESIGNABLE

@interface FlintTextEntryView : UIView

/**
 *  Delegate for validation
 */
@property (weak, nonatomic) IBOutlet id<FlintTextEntryViewDelegate>delegate;

#pragma mark - IBInspectable

/**
 *  The text color for the text field
 *  Default to be black
 */
@property (strong, nonatomic) IBInspectable UIColor *textColor;

/**
 *  The font for both the text, place holder, and foot note
 *  Default to be SDK Font name
 *  If you are using custom font, please make sure to follow the steps in one of these blogs
 *  http://www.neevtech.com/blog/2013/11/22/how-to-add-custom-font-to-your-ios-based-app/
 */
@property (strong, nonatomic) IBInspectable NSString *fontFamily;

/**
 *  The font size for both the text and place holder
 *  Default to be 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/**
 *  The color when validation of the text field faild
 *  Default to be red
 */
@property (strong, nonatomic) IBInspectable UIColor *errorColor;

/**
 *  The place holder for the text field
 *  Setting this set both the placeholder and attributedPlaceHoler with holderColor on text field
 *  Default to empty string
 */
@property (copy, nonatomic) IBInspectable NSString *placeHolder;

/**
 *  Color for place holder
 *  Default to be light gray color
 */
@property (strong, nonatomic) IBInspectable UIColor *holderColor;

/**
 *  Determine if the text field has line under or border
 *  if value is YES, it is underline mode, NO to be border mode
 *  Default to YES
 */
@property (assign, nonatomic) IBInspectable BOOL underline;

/**
 *  The thickness of the underline or border depend on which one is enable
 *  Default to be 0.5
 */
@property (assign, nonatomic) IBInspectable CGFloat lineWidth;

/**
 *  The line color of the underline or border depend on which one is enable
 *  Default to be light gray color
 */
@property (assign, nonatomic) IBInspectable UIColor *lineColor;

/**
 *  The corner radius, only effective if underline set to NO
 *  Default to be 0
 */
@property (assign, nonatomic) IBInspectable CGFloat cornerRadius;

/**
 *  If the view should have footnote
 *  This affect the layout of the text field
 *  Default to NO
 */
@property (assign, nonatomic) IBInspectable BOOL enableFootnote;

/**
 *  The text displayed in the footnote, won't be displayed if enableFootnote set to NO
 *  Default to be empty string
 */
@property (copy, nonatomic) IBInspectable NSString *footnote;

/**
 *  The font size for footnote
 *  Default to 12
 */
@property (assign, nonatomic) IBInspectable CGFloat noteFontSize;

/**
 *  The color for footnote
 *  Default to be light gray color
 */
@property (strong, nonatomic) IBInspectable UIColor *noteColor;

- (BOOL)passValidation;

@end

@interface FlintTextEntryView (UIAccessors)

@property (strong, nonatomic, readonly) UILabel *footnoteLabel;

- (FlintLineTextField *)componentTextField;

@end