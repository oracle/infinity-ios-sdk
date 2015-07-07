//
//  WTEventSupport.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 6/25/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  WTEventMeta is a wrapper class to store common parameter types attached to each event. For all but the most basic events, start by creating a new instance of WTEventMeta, which will subsequently be attached to the event.
 */
@interface WTEventMeta : NSObject

/**
 *   Specifies the hierarchical representation of an application view at the time of the event. For example, this parameter can specify an application path. You can leave this nil to use the default event path.
 */
@property (nonatomic, copy) NSString *eventPath;

/**
 *  Specifies the representation of an application view at the time of the event. For example, this parameter can specify the name of a screen. Should not be nil.
 */
@property (nonatomic, copy) NSString *eventDescription;

/**
 *  Specifies the type of event that occurred, such as a view or tap. Should not be nil.
 */
@property (nonatomic, copy) NSString *eventType;

/**
 *  Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 */
@property (nonatomic, copy) NSDictionary *customParams;

/**
 *  Creates a meta object that stores information about an event
 *
 *  @param eventPath        Specifies the hierarchical representation of an application view at the time of the event. For example, this parameter can specify an application path. Leave this nil to use the default event path.
 *  @param eventDescription Specifies the representation of an application view at the time of the event. For example, this parameter can specify the name of a screen. Should not be nil.
 *  @param eventType        Specifies the type of event that occurred, such as a view or tap. Should not be nil.
 *  @param customParams     Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return The WTEventMeta object describing your event
 */
+ (instancetype) eventMetaForPath:(NSString *)eventPath
                      description:(NSString *)eventDescription
                             type:(NSString *)eventType
                     customParams:(NSDictionary *)customParams;

/**
 *  Creates a meta object that stores information about an event
 *
 *  @param eventPath        Specifies the hierarchical representation of an application view at the time of the event. For example, this parameter can specify an application path. Leave this nil to use the default event path.
 *  @param eventDescription Specifies the representation of an application view at the time of the event. For example, this parameter can specify the name of a screen. Should not be nil.
 *  @param eventType        Specifies the type of event that occurred, such as a view or tap. Should not be nil.
 *  @param customParams     Specifies any user-defined data to be included with the event. Must be a dictionary with strings as both the key and the value. For example, a user id string to tie events to a given user.
 *
 *  @return The WTEventMeta object describing your event
 */
- (instancetype)initWithEventPath:(NSString *)eventPath
                      description:(NSString *)eventDescription
                             type:(NSString *)eventType
                     customParams:(NSDictionary *)customParams;

@end

/**
 *  WTEventMedia is a wrapper class to parameter types associated with media events.
 */
@interface WTEventMedia : NSObject

/**
 *  Specifies the name of the media content accessed during an event, for example the name of a video clip.
 */
@property (nonatomic, copy) NSString *mediaName;

/**
 *  Specifies a type of media accessed during the event, such as QuickTime or mp3.
 */
@property (nonatomic, copy) NSString *mediaType;

/**
 *  Specifies the type of media event that occurred, such as a view of media content.
 */
@property (nonatomic, copy) NSString *mediaEventType;

/**
 *  Creates a WTEventMedia object that stores information about a given piece of media
 *
 *  @param mediaName      Specifies the name of the media content accessed during an event, for example the name of a video clip.
 *  @param mediaType      Specifies a type of media accessed during the event, such as QuickTime or mp3.
 *  @param mediaEventType Specifies the type of media event that occurred, such as a view of media content.
 *
 *  @return The WTEventMedia object describing your media
 */
+ (instancetype) eventMediaForName:(NSString *)mediaName
                         mediaType:(NSString *)mediaType
                    mediaEventType:(NSString *)mediaEventType;

/**
 *  Creates a WTEventMedia object that stores information about a given piece of media
 *
 *  @param mediaName      Specifies the name of the media content accessed during an event, for example the name of a video clip.
 *  @param mediaType      Specifies a type of media accessed during the event, such as QuickTime or mp3.
 *  @param mediaEventType Specifies the type of media event that occurred, such as a view of media content.
 *
 *  @return The WTEventMedia object describing your media
 */
- (instancetype) initWithMediaName:(NSString *)mediaName
                         mediaType:(NSString *)mediaType
                    mediaEventType:(NSString *)mediaEventType;


@end
