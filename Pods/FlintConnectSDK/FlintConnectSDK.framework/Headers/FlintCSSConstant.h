//
/*! @file FlintCSSConstant.h */
//  FlintConnect
//
//  Created by PC on 3/6/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Element Name

/**
 *  button
 */
extern NSString *const FMCSSElementButton;

/**
 *  view
 */
extern NSString *const FMCSSElementView;

/**
 *  label
 */
extern NSString *const FMCSSElementLabel;

/**
 *  textfield
 */
extern NSString *const FMCSSElementTextField;

/**
 *  image
 */
extern NSString *const FMCSSElementImageView;

#pragma mark - Pseudo Class

/**
 *  normal
 */
extern NSString *const FMCSSPseudoNormal;

/**
 *  highlight
 */
extern NSString *const FMCSSPseudoHighLighted;

/**
 *  select
 */
extern NSString *const FMCSSPseudoSelected;

/**
 *  disable
 */
extern NSString *const FMCSSPseudoDisabled;

#pragma mark - Attribute

/**
 *  background-color
 */
extern NSString *const FMCSSAttributeBackgroundColor;

/**
 *  background-image
 */
extern NSString *const FMCSSAttributeBackgroundImage;

/**
 *  text-color
 */
extern NSString *const FMCSSAttributeColor;

/**
 *  font-name
 */
extern NSString *const FMCSSAttributeFontName;

/**
 *  font-size
 */
extern NSString *const FMCSSAttributeFontSize;

/**
 *  border-radius
 */
extern NSString *const FMCSSAttributeBorderRadius;

/**
 *  border-width
 */
extern NSString *const FMCSSAttributeBorderWidth;

/**
 *  border-style
 */
extern NSString *const FMCSSAttributeBorderStyle;

/**
 *  border-color
 */
extern NSString *const FMCSSAttributeBorderColor;

/**
 *  image
 */
extern NSString *const FMCSSAttributeImage;

#pragma mark - Attribute Group

/**
 *  font
 *  font(<font-name>, <font-size>)
 */
extern NSString *const FMCSSGroupAttributeFont;

/**
 *  border
 *  border(<border-width>, <border-style>, <border-color>)
 */
extern NSString *const FMCSSGroupAttributeBorder;

@interface FlintCSSConstant : NSObject

/**
 *  return the default group attributes
 *  WARNING: make a copy of element before use. Do not mutate default value
 *
 *  @return array of FlintCSSAttributeGroup objects
 */
+ (NSArray *)groupAttributes;

@end
