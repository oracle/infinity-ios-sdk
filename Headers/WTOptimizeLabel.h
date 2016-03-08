//
//  WTOptimizeLabel.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 7/16/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WTMultivariateOptimizeFactor.h"

/**
 *  An Optimizable UILabel. Tests can be configured to adjust this button's text, font, and colors.
 */
@interface WTOptimizeLabel : UILabel

/**
 *  The optimize identifier asscoiated with this label. Identifiers can identify one set of visual instructions per app, and can be thought of similarly to css classes.
 */
@property (strong, nonatomic) IBInspectable NSString *wtIdentifier;

/**
 *  The factor associated with the given identifer. Useful for reading custom factor parameters.
 */
@property (readonly, strong, nonatomic) WTMultivariateOptimizeFactor *wtFactor;

@end
