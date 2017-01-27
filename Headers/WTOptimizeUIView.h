//
//  WTOptimizeUIView.h
//  Webtrends-SDK
//
//  Created by Taron Qalashyan on 10/11/16.
//  Copyright © 2016 Webtrends. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WTOptimizeFactor.h"

@protocol WTOptimizeUIView 

/**
 *  The optimize identifier asscoiated with this imageview. Identifiers can identify one set of visual instructions per app, and can be thought of similarly to css classes.
 */
@property (strong, nonatomic) IBInspectable NSString *wtIdentifier;

@optional
- (void)applyTest;

@end
