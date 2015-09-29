//
/*! @file FlintCSSEngine.h */
//  FlintConnect
//
//  Created by PC on 3/12/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FlintCSSConstant.h"

/**
 *  Observe this notification and call flint_refreshStyles:
 *  for any view that want to apply dynamic style change
 */
extern NSString *const FMCSSEngineStyleChangeNotification;

@interface FlintCSSEngine : NSObject

/**
 *  Setting the resource button where Default.css
 *  and other artifacts (e.g. images) reside
 *
 *  @param bundle the resource bundle
 */
+ (void)configureWithResourceBundle:(NSBundle *)bundle;

/**
 *  If we want to use other style than Default.css
 *
 *  @param styleName the replacement stylename (e.g. BlueTheme.css)
 */
+ (void)configureAlternateStyle:(NSString *)styleName;

/**
 *  Set the overall theme for ui component
 *
 *  @param themeColor The main theme color
 */
+ (void)setThemeColor:(UIColor *)themeColor;

/**
 *  Set the overall theme and font for ui component
 *
 *  @param themeColor The main theme color
 *  @param fontName   The main theme font name
 */
+ (void)setThemeColor:(UIColor *)themeColor fontName:(NSString *)fontName;

@end
