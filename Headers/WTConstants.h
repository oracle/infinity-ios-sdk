//
//  WTConstants.h
//  WebTrendsSDK
//
//  Created by Sam Ingle on 12/23/14.
//  Copyright (c) 2014 Web Trends. All rights reserved.
//

#ifndef WT_Constants_h
#define WT_Constants_h

// Config Setting Constants

extern NSString * const kWTConfigEnabled;
extern NSString * const kWTConfigDCSID;
extern NSString * const kWTConfigTimezone;
extern NSString * const kWTConfigMaxPersistedEvents;
extern NSString * const kWTConfigSendIntervalMilliseconds;
extern NSString * const kWTConfigAutoSendThresholdPercent;
extern NSString * const kWTConfigEventsPerSend;
extern NSString * const kWTConfigMaxEventsPerRequest;
extern NSString * const kWTConfigCollectionUrlBase;
extern NSString * const kWTConfigDebug;
extern NSString * const kWTConfigHTTPConnectionTimeoutMilliseconds;
extern NSString * const kWTConfigHTTPReadTimeoutMilliseconds;
extern NSString * const kWTConfigRCSPollIntervalMilliseconds;
extern NSString * const kWTConfigRCSEnabled;
extern NSString * const kWTConfigRCSUrlBase;
extern NSString * const kWTConfigMaxSessionMilliseconds;
extern NSString * const kWTConfigSessionTimeoutMilliseconds;
extern NSString * const kWTConfigAutomaticsEnabled;
extern NSString * const kWTConfigAppDelegateClassName;
extern NSString * const kWTConfigCollectionUrlExtraQueryParams;
extern NSString * const kWTConfigReportLocationEnabled;
// Remove AdSupport AdvertisingIdentifier
//extern NSString * const kWTConfigSendUniqueIdEnabled;
extern NSString * const kWTConfigSendScreenViewWithActivityViewEnabled;

// Webtrends WatchKit Support
extern NSString * const kWTExtensionRequestIdentifier;
extern NSString * const kWTExtensionRequestAutomaticIdentifier;

#endif
