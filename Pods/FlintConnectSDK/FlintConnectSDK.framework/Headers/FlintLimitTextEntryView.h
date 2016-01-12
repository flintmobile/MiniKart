//
//  FlintLimitTextEntryView.h
//  FlintCardScanner
//
//  Created by PC on 12/7/15.
//  Copyright © 2015 Flint Mobile. All rights reserved.
//

#import "FlintTextEntryView.h"

@interface FlintLimitTextEntryView : FlintTextEntryView 

#pragma mark - IBInspectable

@property (assign, nonatomic) IBInspectable NSInteger maxLength;

@end
