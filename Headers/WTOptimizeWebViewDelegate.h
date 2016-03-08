//
//  WTOptimizeWebViewDelegate.h
//  Webtrends-SDK
//
//  Created by Blake Clough on 1/6/16.
//  Copyright © 2016 Webtrends. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  A delegate that can be used on internal webViews that accepts cookies from Optimize-enabled web pages, allowing the transfer of data to keep the session synchronized between web and native app.
 */
@interface WTOptimizeWebViewDelegate : NSObject

/**
 *  Reads cookies from Optimize-enabled web pages
 *
 *  @param request the NSURLRequest of the page to be loaded
 *
 *  @return true for all web pages
 */
+ (BOOL)shouldStartLoadWithRequest:(NSURLRequest *)request;

@end
