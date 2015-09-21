//
/*! @file FlintCSSEngine.h */
//  FlintConnect
//
//  Created by PC on 3/12/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>
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
 *  @param red   red component (0-255)
 *  @param green green component (0-255)
 *  @param blue  blue component (0-255)
 *  @param alpha alpha component (0-1)
 */
+ (void)setThemeColorWithRed:(float)red green:(float)green blue:(float)blue alpha:(float)alpha;

@end
