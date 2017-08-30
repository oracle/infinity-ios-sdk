//
//  WTOptimizeImageView.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 7/15/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WTImageOptimizeFactor.h"
#import "WTOptimizeUIView.h"

/**
 *  An Optimizable UIImageView. Tests can be configured to adjust the source image to either a local file, or a remote URL
 */
@interface WTOptimizeImageView : UIImageView <WTOptimizeUIView>

/**
 *  The optimize identifier asscoiated with this imageview. Identifiers can identify one set of visual instructions per app, and can be thought of similarly to css classes.
 */
@property (strong, nonatomic) IBInspectable NSString *wtIdentifier;

/**
 *  The factor associated with the given identifer. Useful for reading custom factor parameters.
 */
@property (readonly, strong, nonatomic) WTImageOptimizeFactor *wtFactor;

- (void)applyTest;

@end
