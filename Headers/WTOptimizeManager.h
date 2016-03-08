//
//  WTOptimizeManager.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 7/10/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WTOptimizeFactor;
@class WTOptimizeConversion;
@class WTOptimizeTest;

/**
 *  WTOptimizeManager is the central class provided by OptimizeSDK. Its central purpose is to orchestrate optimization tests and report conversions to the Optimize data collection servers. It's primarily accessed through its sharedCollector singleton. It should not be manually initialized.
 *
 */
@interface WTOptimizeManager : NSObject

/**
 *  The singleton Optimize manager object used to access all Optimize SDK functionality.
 *
 *  @return WTOptimizeManager singleton object
 *  @discussion You can use this method within your Webtrends-SDK-enabled application to get access to the WTOptimizeManager singleton object, its properties, and methods.
 */
+ (instancetype _Nonnull)sharedManager;


/**
 *  Retrieve an Optimize test factor from the local collection of tests.
 *
 *  @param identifier The identifier associated with this factor
 *
 *  @return The Optimize factor with the identifier
 */
- (WTOptimizeFactor * _Nullable)optimizeFactorForIdentifier:(NSString * _Nonnull)identifier;

/**
 *  The number of projects stored locally
 *
 *  @return the number of projects stored in the local database
 */
- (int64_t)projectCount;

/**
 *  The number of tests stored locally
 *
 *  @return the number of tests stored in the local database
 */
- (int64_t)testCount;

/**
 *  The number of factors stored locally
 *
 *  @return the number of factors stored in the local database
 */
- (int64_t)factorCount;

/**
 *  Create a page view that will be associated with an existing test alias and project
 *
 *  @param page            Usually self, but may be any object.
 *  @param testAlias       The test alias associated with this page view
 *  @param projectLocation The project location associated with this page view
 *
 *  @discussion Both testAlias and projectLocation must exist in the local optimize store (previously set up in the Optimize product and downloaded by the SDK to this application).
 *  @return a Page View event. It is not necessary to use the return value. The event will automatically be sent to the collection servers during the next event send.
 */
- (NSDictionary * _Nullable)triggerPageView:(id _Nonnull)page withTestAlias:(NSString * _Nonnull)testAlias projectLocation:(NSString * _Nonnull)projectLocation;

/**
 *  Triggers a conversion event to be created
 *
 *  @param testAlias       The test alias associated with this conversion
 *  @param projectLocation The project location associated with this conversion
 *  @param conversionPoint The conversion point associated with this conversion
 *
 *  @discussion Conversion events must be defined in the Optimize application and preceded by a page view event.
 *  @return a conversion event (as an NSDictionary). It is not necessary to use the return value. The event will automatically be sent to the collection servers during the next event send.
 */
- (NSDictionary * _Nullable)triggerEventForConversionWithTestAlias:(NSString * _Nonnull)testAlias
                                         projectLocation:(NSString * _Nonnull)projectLocation
                                         conversionPoint:(NSString * _Nonnull)conversionPoint;
/**
 *  Mark the current page view as completed, so that subsequent calls to triggerPageView:withTestAlias:projectLocation will cause an additional page view to be tracked rather than ignored. This method is optional.
 */
- (void) triggerPageViewEnd;

/**
 *  Fetch the test at a given location. Useful for tests that aren't permenantly cacheable, because they require in-the-moment data. Generally implemented with some sort of UI-blocking to prevent a content flash after the download has finished.
 *
 *  @param location   The project location to search for
 *  @param completion Once fetched, returns an array of tests that match the given location
 */
- (void)fetchTestLocation:(NSString * _Nonnull)location
               customData:(NSDictionary * _Nullable)data
               completion:(void ( ^ _Nullable )(NSArray<WTOptimizeTest *> * _Nullable tests , NSError * _Nullable error)) completion;

/**
 *  Get cookie data from the SDK and send it to the webView's cookie storage
 *
 *  @param webView a UIWebView or WKWebView (or subclass) object
 */
- (void) synchronizeSessionWithWebView:(id _Nonnull)webView;

/**
 *  If the SDK is in staging mode, flush all tests ands cookies currently cached in the system. Useful for active test development and debugging.
 */
- (void)flushTestCache;

@end
