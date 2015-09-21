//
/*! @file FlintCardDetailView.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 5/8/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FlintTextField;
@class FlintNumberEntryView;
@class FlintDateEntryView;
@class FlintCardDetailView;

@protocol FlintCardDetailViewDelegate <NSObject>

@optional
/**
 *  call this when a textfield entry is completed, validation not neccessary passed, 
 *  use the validation status on FlintTextField to check if needed
 *
 *  @param cardDetailView the card detail view
 *  @param textField      the text field that has completed entry
 */
- (void)cardDetailView:(FlintCardDetailView *)cardDetailView completeEntryForTextField:(FlintTextField *)textField;

@end

IB_DESIGNABLE

@interface FlintCardDetailView : UIView

@property (weak, nonatomic) IBOutlet id<FlintCardDetailViewDelegate>delegate;

#pragma mark - IBInspectable

/**
 *  The font for both the text and place holder of the textfield entries
 *  This font also apply for the validation label
 *  Default to be SDK font name
 *  If you are using custom font, please make sure to follow the steps in one of these blogs
 *  http://www.neevtech.com/blog/2013/11/22/how-to-add-custom-font-to-your-ios-based-app/
 */
@property (strong, nonatomic) IBInspectable NSString *fontName;

/**
 *  The font size for both the text and place holder of the texfield entries
 *  Default to be 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/**
 *  Foreground color apply for all text field text
 *  Default to be black color
 */
@property (strong, nonatomic) IBInspectable UIColor *foregroundColor;

/**
 *  Miscellaneous color apply for place holder, underline color,...
 *  To customize different color, access each component via accessors
 *  Default to be light gray color
 */
@property (strong, nonatomic) IBInspectable UIColor *miscColor;

/**
 *  Error color apply for textfield validation color & validation label
 *  Default to be red color
 */
@property (strong, nonatomic) IBInspectable UIColor *errorColor;

@end

@interface FlintCardDetailView (UIAccessors)

@property (strong, nonatomic, readonly) FlintDateEntryView *expirationDateView;
@property (strong, nonatomic, readonly) FlintNumberEntryView *cvvView;

@end
