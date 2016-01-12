//
//  FlintAmountEntryView.h
//  FlintCardScanner
//
//  Created by PC on 11/16/15.
//  Copyright © 2015 Flint Mobile. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol FlintAmmountInputViewDelegate;

@interface FlintAmountInputView : UIView

/**
 *  The view delegate
 */
@property (weak, nonatomic) IBOutlet id<FlintAmmountInputViewDelegate>delegate;

/**
 *  Determine if the amount entered in should be negate
 */
@property (assign, nonatomic) BOOL isNegativeAmount;

/**
 *  The max amount to be input
 */
@property (assign, nonatomic) CGFloat maxAmount;

#pragma mark - IBInspectable

/**
 *  The title for the done button
 *  Default to be "Done"
 */
@property (copy, nonatomic) IBInspectable NSString *doneTitle;

- (void)validateDoneButton;

@end



@interface FlintAmountInputView (UIAccessors)

@property (strong, nonatomic, readonly) UILabel *decorativeLabel;
@property (strong, nonatomic, readonly) UITextField *amountTextField;
@property (strong, nonatomic, readonly) UIButton *doneButton;

@end


@protocol FlintAmmountInputViewDelegate <NSObject>

@optional
- (void)amountInputView:(FlintAmountInputView *)inputView didEnterAmount:(CGFloat)amount;

@end

