//
/*! @file FlintTipSelectionView.h */
//  FlintConnect
//
//  Created by PC on 4/10/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlintTipItem.h"

@class FlintTipSelectionView;

@protocol FlintTipSelectionViewDelegate <NSObject>

@optional
/**
 *  Delegate firing this when user tap on the tip item
 *
 *  @param tipSelectionView the tip selection view
 *  @param tipItem          the selected tip item
 */
- (void)tipSelectionView:(FlintTipSelectionView *)tipSelectionView didSelectTipItem:(FlintTipItem *)tipItem;

/**
 *  Delegate firing this when user tap on 'other' button
 *
 *  @param tipSelectionView the tip selection view
 */
- (void)tipSelectionViewSelectOtherOption:(FlintTipSelectionView *)tipSelectionView;

/**
 *  Delegate firing this on clearing selection
 *
 *  @param tipSelectionView the tip selection view
 */
- (void)tipSelectionViewClearAllSelections:(FlintTipSelectionView *)tipSelectionView;

@end

IB_DESIGNABLE

@interface FlintTipSelectionView : UIView

@property (weak, nonatomic) IBOutlet id<FlintTipSelectionViewDelegate>delegate;

/**
 *  If this is set to YES, when the other option is selected, 
 *  all selections (including 'other' option if enable) will be cleared
 *  If this is set to NO, the visual feedback on 'other' option will persist
 *  Has no effect if otherOptionEnabled is NO
 *  Default to NO
 */
@property (assign, nonatomic) BOOL clearOnSelectingOther;

/**
 *  Clear the current tip selection
 */
- (void)clearSelection;

#pragma mark - IBInspectable

/**
 *  A string value in comma separated to indicate the tip values to be created
 *  Default to be [0.05,0.1,0.15]
 */
@property (copy, nonatomic) IBInspectable NSString *tipAmmounts;

/**
 *  Determine if the tip ammounts are percentage or dollar value
 *  Default to be YES
 */
@property (assign, nonatomic, getter=isPercentage) IBInspectable BOOL percentage;

/**
 *  If this is enable, an extra button for other tip amount is displayed
 *  Default to be YES
 */
@property (assign, nonatomic, getter=otherOptionEnabled) IBInspectable BOOL otherOption;

/**
 *  The text to be displayed on the other option button label
 *  Has no effect if otherOption is set to NO
 *  Default to be 'Other'
 */
@property (copy, nonatomic) IBInspectable NSString *otherLabel;

/**
 *  The color for tip item
 *  Default to be SDK theme color
 */
@property (strong, nonatomic) IBInspectable UIColor *color;

/**
 *  The font name for tip item
 *  Default to be SDK font name
 */
@property (strong, nonatomic) IBInspectable NSString *fontName;

/**
 *  The font size for tip item
 *  Default to be 16
 */
@property (assign, nonatomic) IBInspectable CGFloat fontSize;

@end

@interface FlintTipSelectionView (UIAccessors)

/**
 *  the accessor to the tip items views
 *
 *  @return array of FlintRoundButton objects
 */
- (NSArray *)tipItemViews;

@end