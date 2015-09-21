//
/*! @file FlintUI.h */
//  FlintConnect
//
//  Created by Phuoc Nguyen on 7/10/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "FlintTransaction.h"

@interface FlintUI : NSObject

#pragma mark - Convenient Payment

/**
 *  Minimal configuration to initiate the payment flow
 *
 *  @param orderItems     the array of FlintOrderItem
 *  @param viewController the view controller where the payment flow would be presented modally, conforming to FlintTransactionDelegate to receive callback for payment statu
 */
+ (void)takePaymentForOrderItems:(NSArray *)orderItems
              fromViewController:(UIViewController<FlintTransactionDelegate> *)viewController;

/**
 *  Initiate the payment with a collection of order item
 *
 *  @param orderItems     the array of FlintOrderItem
 *  @param viewController the view controller where the payment flow would be presented modally, conforming to FlintTransactionDelegate to receive callback for payment status
 *  @param animated       whether the reprentation should be animated
 *  @param completion     the animation completion block
 */
+ (void)takePaymentForOrderItems:(NSArray *)orderItems
              fromViewController:(UIViewController<FlintTransactionDelegate> *)viewController
                        animated:(BOOL)animated
                      completion:(void (^)())completion;

#pragma mark - Direct Access to Payment View Controller

+ (UIViewController *)paymentViewControllerWithOrderItems:(NSArray *)orderItems
                                                 delegate:(id<FlintTransactionDelegate>)delegate;

#pragma mark - Restart Payment

/**
 *  Begin another payment if already start
 *
 *  @param orderItems     the array of FlintOrderItem
 *  @param delegate       the delegate for transaction
 */
+ (void)restartPaymentFlowWithOrderItems:(NSArray *)orderItems
                                delegate:(id<FlintTransactionDelegate>)delegate;

@end
