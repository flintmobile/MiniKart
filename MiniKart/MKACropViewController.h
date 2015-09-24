//
//  MKACropViewController.h
//  MiniKart
//
//  Created by PC on 9/24/15.
//  Copyright © 2015 Flint. All rights reserved.
//

#import <TOCropViewController/TOCropViewController.h>
#import <TOCropViewController/TOCropView.h>
#import <TOCropViewController/TOCropToolbar.h>

@interface MKACropViewController : TOCropViewController

@end

@interface MKACropViewController (UIAccessors)

@property (strong, nonatomic, readonly) TOCropView *cropView;
@property (strong, nonatomic, readonly) TOCropToolbar *toolbar;

@end

@interface TOCropToolbar (UIAccessors)

@property (nonatomic, strong, readonly) UIButton *resetButton;
@property (nonatomic, strong, readonly) UIButton *clampButton;

@end