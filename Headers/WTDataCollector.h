//
//  WTDataCollector.h
//  WebTrendsSDK
//
//  Created by Sam Ingle on 5/14/15.
//  Copyright (c) 2015 Web Trends. All rights reserved.
//

#import <Foundation/Foundation.h>

@import CoreData;

@class WTEventMeta;
@class WTEventMedia;

/**
 *  WTDataCollector is the central class provided by WebtrendsSDK. Its central purpose is to log and send events to the Webtrends collection servers. It's primarily accessed through its sharedCollector singleton. It should not be manually initialized.
 *
 */
@interface WTDataCollector : NSObject

/**
 * @name Singleton
 */

/**
 *  WTDataCollector should not be initialized manually, but should instead be messaged through this singleton instance.
 *
 *  @return The WTDataCollector singleton.
 */
+ (instancetype)sharedCollector;

/**
 * @name Triggering Events
 */

/**
 *  Creates and schedules an event for the application starting. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param appName      Specifies the name of your application
 *  @param customParams Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForApplication:(NSString *)appName startWithCustomParams:(NSDictionary *)customParams;

/**
 *  Creates and schedules an event for the application terminating. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param appName      Specifies the name of your application
 *  @param customParams Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForApplication:(NSString *)appName terminateWithCustomParams:(NSDictionary *)customParams;

/**
 *  Creates and schedules an event for the application entering the background. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param appName      Specifies the name of your application
 *  @param customParams Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForApplication:(NSString *)appName didEnterBackgroundWithCustomParams:(NSDictionary *)customParams;

/**
 *  Creates and schedules an event for the application entering the foreground. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param appName      Specifies the name of your application
 *  @param customParams Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForApplication:(NSString *)appName willEnterForegroundWithCustomParams:(NSDictionary *)customParams;

/**
 *  Creates and schedules an event for the application errors.
 *
 *  @param appName      Specifies the name of your application
 *  @param errorMessage Specifies the error message associated with the error.
 *  @param customParams Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForApplication:(NSString *)appName withErrorMessage:(NSString *)errorMessage customParams:(NSDictionary *)customParams;

/**
 *  Creates and schedules an event for a view controller appearing. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param controllerTitle  Specifies the title of the view controller
 *  @param customParams     Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForViewDidAppear:(NSString *)controllerTitle
                              withCustomParams:(NSDictionary *)customParams;

/**
 *  Creates and schedules an event for a view controller disappearing. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param controllerTitle  Specifies the title of the view controller
 *  @param customParams     Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForViewDidDisappear:(NSString *)controllerTitle
                                 withCustomParams:(NSDictionary *)customParams;

/**
 *  Creates and schedules an event for a notification firing. This can be used for both local and remote notifications. If automatic events are enabled, an event of this type will automatically be logged, if not, it can be manually logged with this method.
 *
 *  @param notificationMessage  Specifies the message presented in the notification
 *  @param customParams         Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForNotification:(NSString *)notificationMessage
                             withCustomParams:(NSDictionary *)customParams;

/**
 *  Creates and schedules an event for an advertisement being tapped.
 *
 *  @param adName Specifies the name of the advertisement.
 *  @param meta   Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 *  @see WTEventMeta
 */
- (NSDictionary *)triggerEventForAdClickName:(NSString *)adName
                                   eventMeta:(WTEventMeta *)meta;

/**
 *  Creates and schedules an event for an ad impression
 *
 *  @param adNames Specifies an array of string ad names that were shown.
 *  @param meta    Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 *
 *  @see WTEventMeta
 */
- (NSDictionary *)triggerEventForAdImpressionNames: (NSArray *) adNames
                                         eventMeta:(WTEventMeta *) meta;


/**
 *  Creates and schedules an event for a search event
 *
 *  @param searchPhrase Specifies the string the user searched for.
 *  @param searchResult Specifies the string of the search result.
 *  @param meta         Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 *
 *  @see WTEventMeta
 */
- (NSDictionary *)triggerEventForSearchPhrase:(NSString *) searchPhrase
                                 searchResult:(NSString *) searchResult
                                    eventMeta:(WTEventMeta *) meta;

/**
 *  Creates and schedules an event for a content view such as when an article or image is viewed.
 *
 *  @param meta         Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *  @param contentGroup Specifies a group of related application views.
 *
 *  @return A dictionary of the event that is created
 *
 *  @see WTEventMeta
 */
- (NSDictionary *)triggerEventForContentView:(WTEventMeta *)meta
                                contentGroup:(NSString *)contentGroup;


/**
 *  Creates and schedules an event for a screen view such as when a screen, article, or image is viewed.
 *
 *  @param meta         Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *  @param contentGroup Specifies a group of related application views.
 *
 *  @return A dictionary of the event that is created
 *
 *  @see WTEventMeta
 */
- (NSDictionary *)triggerEventForScreenView:(WTEventMeta *) meta
                               contentGroup:(NSString *) contentGroup;

/**
 *  Creates and schedules an event for a product view
 *
 *  @param productId    Specifies a product identifier.
 *  @param productSku   Specifies a unique product stock-keeping unit (SKU) number.
 *  @param contentGroup Specifies a group of related application views.
 *  @param meta         Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 *
 *  @see WTEventMeta
 */
- (NSDictionary *)triggerEventForProductId:(NSString *) productId
                                productSku:(NSString *) productSku
                              contentGroup:(NSString *) contentGroup
                                 eventMeta:(WTEventMeta *) meta;

/**
 *  Creates and schedules an event for a media view
 *
 *  @param media        Specifies a <WTEventMedia> object that stores parameter types associated with media events.
 *  @param contentGroup Specifies a group of related application views.
 *  @param meta         Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 *
 *  @see WTEventMeta
 *  @see WTEventMedia
 */
- (NSDictionary *)triggerEventForEventMedia:(WTEventMedia *) media
                               contentGroup:(NSString *) contentGroup
                                  eventMeta:(WTEventMeta *) meta;

/**
 *  Creates and schedules an event for a conversion, such as when a purchase or registration, occurs.
 *
 *  @param conversionName   Specifies the name used to identify a customer conversion.
 *  @param contentGroup     Specifies a group of related application views.
 *  @param meta             Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 *
 *  @see WTEventMeta
 */
- (NSDictionary *)triggerEventForConversion:(NSString *)conversionName
                               contentGroup:(NSString *)contentGroup
                                  eventMeta:(WTEventMeta *)meta;


/**
 *  Creates and schedules an event for an arbitrary action, such as a button tap
 *
 *  @param meta Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForAction:(WTEventMeta *) meta;


/**
 *  Creates and schedules a custom event, used to encapsulate any event not covered by the convenience event types.
 *
 *  @param meta Specifies a <WTEventMeta> object that stores common parameter types attached to this event.
 *
 *  @return A dictionary of the event that is created
 */
- (NSDictionary *)triggerEventForCustomEvent:(WTEventMeta *) meta;


/**
 *  Read a watchkit sdk event in, and synchronously write it to the store
 *
 *  @param dictionary The dictionary potentially containing a watchkit event
 *
 *  @return YES if the dictionary is a Webtrends Event, NO if not
 */
- (BOOL)saveWatchEvent:(NSDictionary *)dictionary;


/**
 * @name General Methods
 */


/**
 *  This method is used for maintaining a session within an embedded UIWebView. Before loading a new webview, use this method to append the current session information onto the URL you wish to load.
 *
 *  @param url The url you wish to append
 *
 *  @return The final URL to load in your webview, with the current session information appended as a query string.
 */
- (NSURL *)appendSessionParamsToUrl:(NSURL *)url;


/**
 *  Opens the given URL in Safari after appending the current session information.
 *
 *  @param url The url to open.
 */
- (void)openURL:(NSURL *)url;


/**
 *  Adds a single send operation onto the Data Collector's internal queue. Each send operation sends a batch of events to the collector's servers. Operations are executed in the order they are received.
 */
- (void)scheduleSend;


/**
 *  Adds a send all operation onto the Data Collector's internal queue. This operation sends all events currently in the event store to the collector's servers. Operations are executed in the order they are received.
 */
- (void)scheduleSendAll;


/**
 *  By default, the Data Collector will periodically send events to its data collection servers based on your configuration settings. This method temporarily disables that periodic sending. You can still manually send events using -scheduleSend and -scheduleSendAll while periodic sending is paused.
 */
- (void)pause;


/**
 *  By default, the Data Collector will periodically send events to its data collection servers based on your configuration settings. This method resumes that periodic sending, and also immediately schedules a send event.
 */
- (void)resume;


/**
 *  Returns the value for a given Webtrends config key (or a user-defined key). See the [Advanced Configuration Guide](../docs/public_guides/Advanced-Configuration-Guide.html) for a list of first party keys.
 *
 *  @param key The key for the value you want returned
 *
 *  @return The value, as an id. Depending on the key supplied, this may be a NSNumber*, an NSString*, or an NSURL*
 */
- (id)valueForConfigKey:(NSString *)key;


/**
 *  Sets a new value for a given Webtrends config key (or a user-defined key). See the [Advanced Configuration Guide](../docs/public_guides/Advanced-Configuration-Guide.html) for a list of first party keys. This value will only be set in memory, use <-setValue:forConfigKey:persists:> to store values permanently. Both the key and value must be NSString*
 *
 *  @param value The value to store, as an NSString*
 *  @param key   The key for the value to be associated with
 */
- (void)setValue:(NSString *)value forConfigKey:(NSString *)key;


/**
 *  Sets a new value for a given Webtrends config key (or a user-defined key). See the [Advanced Configuration Guide](../docs/public_guides/Advanced-Configuration-Guide.html) for a list of first party keys. Both the key and value must be NSString*
 *
 *  @param value    The value to store, as an NSString*
 *  @param key      The key for the value to be associated with
 *  @param persists Whether or not the value will be persisted to disk
 */
- (void)setValue:(NSString *)value forConfigKey:(NSString *)key persists:(BOOL)persists;


/**
 *  This method returns whether or not data collection is currently enabled. If disabled, no events will be logged, and no events currently in the event store will be sent to the data collector's servers.
 *
 *  @return Whether or not data collection is currently enabled.
 */
- (BOOL)isEnabled;


/**
 *  The count of events currently stored locally.
 *
 *  @return The count of events currently stored locally.
 */
- (NSInteger)eventStoreCount;


/**
 *  Sets a new value for the given Remote Configuration Server meta key. Use this if you want to set Remote Configuration rules against arbitrary user-defined keys.
 *
 *  @param value The value to store, as an NSString*
 *  @param key   The key for the value to be associated with
 */
- (void)setValue:(NSString *)value forRCSMetaKey:(NSString *)key;

@end
