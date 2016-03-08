//
//  WTOptimizeFactor.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 7/10/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import <Foundation/Foundation.h>
@class WTOptimizeTest;

/**
 *  An Optimize Factor containing the specific changes to be implemented for a given Optimize Test. Generally this class is only referenced by way of its subclasses.
 *
 *  Optimize Factors shouldn't be initialized directly, but instead through [WTOptimizeManager optimizeFactorForIdentifier]
 */
@interface WTOptimizeFactor : NSObject
{
    @protected
    id _rawValue;
    NSString *_identifier;
}

/**
 *  The raw value obtained via NSJSONSerialization. This value contains an NSDictionary in the majority of cases, but not exclusively.
 */
@property (strong, nonatomic, readonly) id rawValue;
/**
 *  The optimize identifier asscoiated with this factor. Identifiers can identify one set of visual instructions per app, and can be thought of similarly to css classes.
 */
@property (strong, nonatomic, readonly) NSString *identifier;
/**
 *  Whether or not all data associated with this factor is ready. In most cases, this references remote images.
 */
@property (nonatomic, readonly, getter=isReady) BOOL ready;

@end
