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
extern NSString * const kWTConfigExtraParams;
extern NSString * const kWTConfigMaskIpEnabled;
extern NSString * const kWTConfigReportLocationEnabled;
// Remove AdSupport AdvertisingIdentifier
//extern NSString * const kWTConfigSendUniqueIdEnabled;
extern NSString * const kWTConfigSendScreenViewWithActivityViewEnabled;

// Webtrends WatchKit Support
extern NSString * const kWTExtensionRequestIdentifier;
extern NSString * const kWTExtensionRequestAutomaticIdentifier;

//Client info keys
extern NSString * const WT_CO;
extern NSString * const WT_DM;
extern NSString * const WT_OS;
extern NSString * const WT_AV;
extern NSString * const WT_A_NM;
extern NSString * const WT_A_DC;
extern NSString * const WT_UL;
extern NSString * const WT_UC;
extern NSString * const WT_SR;
extern NSString * const WT_SDK_V;
extern NSString * const WT_G_LONG;
extern NSString * const WT_G_LAT;
extern NSString * const WT_GC;
extern NSString * const WT_CT;

//Constants for event
extern NSString * const WT_DCSURI;
extern NSString * const WT_TI;
extern NSString * const WT_PI;
extern NSString * const WT_DL;
extern NSString * const WT_SYS;
extern NSString * const WT_ER;
extern NSString * const WT_EV;
extern NSString * const WT_A_AN;
extern NSString * const WT_A_AC;
extern NSString * const WT_OSS;
extern NSString * const WT_OSS_R;
extern NSString * const WT_CG_N;
extern NSString * const WT_PN_ID;
extern NSString * const WT_PN_SKU;
extern NSString * const WT_CLIP_N;
extern NSString * const WT_CLIP_T;
extern NSString * const WT_CLIP_EV;
extern NSString * const WT_CONV;
extern NSString * const WT_SI_CS;
extern NSString * const WT_DCSIPA;
extern NSString * const WT_ETS;
extern NSString * const WT_I_ORNT;
extern NSString * const WT_A_AI;
extern NSString * const WT_ES;

#endif
