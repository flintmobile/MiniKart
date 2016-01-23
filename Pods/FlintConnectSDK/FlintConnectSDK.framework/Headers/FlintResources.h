//
//  FlintResources.h
//  FlintConnect
//
//  Created by PC on 3/11/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FlintResources : NSObject

/**
 *  Use the main bundle that package the resources. This is typically for internal cocoapod integration
 *  Default to NO
 */
@property (assign, nonatomic) BOOL usePackageBundle;

/**
 *  Assign a custom resource Bundle to fetch images
 */
@property (strong, nonatomic) NSBundle *resourceBundle;

+ (instancetype)sharedInstance;

@end
