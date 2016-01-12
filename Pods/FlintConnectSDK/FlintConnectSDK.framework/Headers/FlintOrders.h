//
//  FlintOrders.h
//  FlintConnect
//
//  Created by Nidhi Jain on 8/3/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import "FlintDomainObject.h"
#import "FlintOrder.h"

@interface FlintOrders : FlintDomainObject

@property (assign, nonatomic)NSInteger totalRecords;
@property (strong, nonatomic)NSArray *orders;

@end
