//
//  WTOptimizeTextField.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 7/16/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WTMultivariateOptimizeFactor.h"

/**
 *  An Optimizable UITextField. Tests can be configured to adjust this field's text, placeholder, font, and colors.
 */
@interface WTOptimizeTextField : UITextField

/**
 *  The optimize identifier asscoiated with this text field. Identifiers can identify one set of visual instructions per app, and can be thought of similarly to css classes.
 */
@property (strong, nonatomic) IBInspectable NSString *wtIdentifier;

/**
 *  The factor associated with the given identifer. Useful for reading custom factor parameters.
 */
@property (readonly, strong, nonatomic) WTMultivariateOptimizeFactor *wtFactor;

@end
