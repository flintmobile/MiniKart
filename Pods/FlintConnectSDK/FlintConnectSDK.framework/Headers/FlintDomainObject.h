//
/*! @file FlintDomainObject.h */
//  FlintConnect
//
//  Created by PC on 3/27/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^FlintRequestHandler)(id result, NSError *error);

@interface FlintDomainObject : NSObject

/**
 *  Determine whether or not the data contains in the model
 *  Is in valid format
 */
@property (assign, nonatomic, readonly, getter=isValid) BOOL valid;

@end
