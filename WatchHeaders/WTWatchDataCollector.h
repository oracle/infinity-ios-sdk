//
//  WTWatchDataCollector.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 6/25/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import <Foundation/Foundation.h>
@import WatchKit;
@import WatchConnectivity;

@class WTWatchEventMeta;

/**
 *  WTWatchDataCollector is the central class provided by WebtrendsWatchKitSDK. Its central purpose is to pass events from a WatchKit extension along to the main SDK, which must be running on the companion app for events to be logged. It's primarily accessed through its sharedCollector singleton. It should not be manually initialized.
 *
 */
@interface WTWatchDataCollector : NSObject <WCSessionDelegate>

/**
 *  The WCSession for your watchOS app
 */
@property (strong, nonatomic) WCSession *session;

/**
 *  WTWatchDataCollector should not be initialized manually, but should instead be messaged through this singleton instance.
 *
 *  @return The WTWatchDataCollector singleton.
 */
+ (instancetype)sharedCollector;


/**
 *  Creates and sends an event for WKInterface activation. If the phone app is unreachable, the event isn't logged. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param meta Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)sendEventForActivation:(WTWatchEventMeta *)meta;


/**
 *  Creates and sends an event for WKInterface deactivation. If the phone app is unreachable, the event isn't logged. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param meta Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)sendEventForDeactivation:(WTWatchEventMeta *)meta;


/**
 *  Creates and sends an event for an arbitrary action, such as a button tap. If the phone app is unreachable, the event isn't logged. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param meta Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)sendEventForAction:(WTWatchEventMeta *)meta;


/**
 *  Creates and sends a custom event, used to encapsulate any event not covered by the convenience event types. If the phone app is unreachable, the event isn't logged. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param meta Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)sendEventForCustomEvent:(WTWatchEventMeta *)meta;
@end
