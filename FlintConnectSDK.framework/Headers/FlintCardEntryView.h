//
/*! @file FlintCardEntryView.h */
//  FlintConnect
//
//  Created by PC on 4/10/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "FlintCardNumberEntryView.h"
#import "FlintDateEntryView.h"
#import "FlintNumberEntryView.h"

@protocol FlintCardEntryViewDelegate;

IB_DESIGNABLE

/*!
 *  @class FlintCardEntryView
 *  
 *  @brief A prebuilt UI component to enter credit card information. Renderable on Interface Builder.
 */
@interface FlintCardEntryView : UIView

/*!
 *  @brief The view delegate.
 */
@property (weak, nonatomic) IBOutlet id<FlintCardEntryViewDelegate>delegate;

#pragma mark - IBInspectable

/*!
 *  @brief Font name for text elements on the view
 *
 *  @dicussion If you are using custom font, please make sure to follow the steps in one of these blogs\n
 *  http://www.neevtech.com/blog/2013/11/22/how-to-add-custom-font-to-your-ios-based-app/.
 *
 *  @default SDK theme font name
 */
@property (strong, nonatomic) IBInspectable NSString *fontName;

/*!
 *  @brief The font size for both the text and place holder of the texfield entries.
 *
 *  @default 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/*!
 *  @brief The font size for the validation error label.
 *
 *  @default 12
 */
@property (assign, nonatomic) IBInspectable CGFloat errorFontSize;

/*!
 *  @brief The text to be displayed when validation failed.
 *
 *  @default "Invalid Card Number"
 */
@property (copy, nonatomic) IBInspectable NSString *errorText;

/*!
 *  @brief Text fields color.
 *
 *  @default Black
 */
@property (strong, nonatomic) IBInspectable UIColor *textColor;

/*!
 *  @brief Place holder color, underline color,...
 *  
 *  @discussion To customize different color, access each component via UIAccessors category
 *
 *  @default Light Gray
 */
@property (strong, nonatomic) IBInspectable UIColor *subColor;

/*!
 *  @brief Validation error color.
 *
 *  @default Red
 */
@property (strong, nonatomic) IBInspectable UIColor *errorColor;

/*!
 *  @brief The fix height apply for all text field.
 *
 *  @discussion Setting this with value higher than 0 disable dynamic vertical scaling
 *  
 *  @default 0
 */
@property (assign, nonatomic) IBInspectable CGFloat textFieldHeight;

@end



@interface FlintCardEntryView (UIAccessors)

@property (strong, nonatomic, readonly) FlintCardNumberEntryView *cardNumberView;
@property (strong, nonatomic, readonly) FlintDateEntryView *expirationDateView;
@property (strong, nonatomic, readonly) FlintNumberEntryView *cvvView;
@property (strong, nonatomic, readonly) FlintNumberEntryView *zipCodeView;

@end



/*!
 *  @protocol FlintCardEntryViewDelegate
 *
 *  @brief Delegate methods for card entry view.
 */
@protocol FlintCardEntryViewDelegate <NSObject>

@optional
/*!
 *  @brief Delegate fire this method when a text field on this view completing getting entry input.
 *
 *  @param cardEntryView The card entry view
 *  @param textField     The text field that has completed entry
 */
- (void)cardEntryView:(FlintCardEntryView *)cardEntryView completeEntryForTextField:(FlintTextField *)textField;

@end