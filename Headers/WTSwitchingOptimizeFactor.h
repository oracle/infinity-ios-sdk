//
//  WTSwitchingOptimizeFactor.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 7/14/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "WTOptimizeFactor.h"

/**
 *  Used to perform basic A/B optimization. Use the selectedOption property to switch on
 */
@interface WTSwitchingOptimizeFactor : WTOptimizeFactor

/**
 *  The option selected by the Optimize test. Generally used in a switch statement to execute alternate code paths.
 */
@property (nonatomic, readonly) NSInteger selectedOption;

@end
