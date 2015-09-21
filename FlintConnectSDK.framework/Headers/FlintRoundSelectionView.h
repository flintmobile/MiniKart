//
/*! @file FlintRoundSelectionView.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 6/18/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintRoundButton.h"

@class FlintRoundSelectionView;

@protocol FlintRoundSelectionViewDelegate <NSObject>

@optional;
- (void)roundSelectionView:(FlintRoundSelectionView *)selectionView
              selectButton:(FlintRoundButton *)button
                   atIndex:(NSUInteger)index;

@end

IB_DESIGNABLE

@interface FlintRoundSelectionView : UIView

@property (weak, nonatomic) IBOutlet id<FlintRoundSelectionViewDelegate>delegate;

#pragma mark - IBInspectable

/**
 *  Titles of the button separated by comma.
 *  Use empty string for no title
 *  e.g. @"Button1,,Button2,Button3"
 *  Default to be empty string
 */
@property (copy, nonatomic) IBInspectable NSString *titles;

/**
 *  Images of button separated by comma.
 *  Use empty string for no image
 *  e.g. @"icon1,icon2,,icon3"
 *  Default to be empty string
 */
@property (copy, nonatomic) IBInspectable NSString *images;

/**
 *  The inset for the button images
 *  Default to be CGSizeZero
 */
@property (assign, nonatomic) IBInspectable CGSize imageInset;

/**
 *  The index(es) that is not visible separated by comma
 *  e.g. @"0,4"
 *  Default to be empty string
 */
@property (copy, nonatomic) IBInspectable NSString *hideIndex;

/**
 *  The index(es) that has invert color scheme
 *  e.g. @"2,3"
 *  Default to be empty string
 */
@property (copy, nonatomic) IBInspectable NSString *invertIndex;

/**
 *  The color for button item
 *  Default to be blue
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/**
 *  The font name for button item
 *  Default to be SDK font name
 */
@property (strong, nonatomic) IBInspectable NSString *fontName;

/**
 *  The font size for button item
 *  Default to be 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

/**
 *  The spacing between buttons
 *  Default to be 5
 */
@property (assign, nonatomic) IBInspectable CGFloat buttonSpacing;

@end

@interface FlintRoundSelectionView (UIAccessors)

/**
 *  Enumerate over members of this to modify style for individual buttons
 *
 *  @return the array of FlintRoundButton
 */
- (NSArray *)selectionButtons;

@end