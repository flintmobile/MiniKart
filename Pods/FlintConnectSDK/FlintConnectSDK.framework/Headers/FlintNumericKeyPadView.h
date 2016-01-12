//
//  FlintNumericKeyPadView.h
//  FlintCardScanner
//
//  Created by PC on 11/19/15.
//  Copyright © 2015 Flint Mobile. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol FlintNumericKeyPadViewDelegate;

@interface FlintNumericKeyPadView : UIView

@property (weak, nonatomic) IBOutlet id<FlintNumericKeyPadViewDelegate> delegate;

#pragma mark - IBInspectable

/**
 *  The color for the key
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/**
 *  The font size of the key
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

@end

@protocol FlintNumericKeyPadViewDelegate <NSObject>

@optional
- (void)numericKeyPadView:(FlintNumericKeyPadView *)keyPadView didTapDigit:(NSInteger)digit;
- (void)numericKeyPadViewDidTapBackspace:(FlintNumericKeyPadView *)keyPadView;

@end
