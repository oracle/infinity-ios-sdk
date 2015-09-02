//
//  SettingsViewController.m
//  ObjCSample
//
//  Created by Sam Ingle on 6/23/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "SettingsViewController.h"
#import "WebtrendsSDK.h"

@interface SettingsViewController ()

@end

@implementation SettingsViewController

- (IBAction)toggleDataCollection:(id)sender
{
    // When set to "false", this setting will disable the entire WebtrendsSDK. No events
    // will be logged while this is disabled. This can also be set in webtrends.plist
    // under the key 'wt_dc_enabled'
    [self toggleSetting:kWTConfigEnabled];

}

- (IBAction)toggleDebugLogging:(id)sender
{
    // When set to "false", this setting will disable all logging from the Webtrends SDK. No events
    // will be logged while this is disabled. This can also be set in webtrends.plist
    // under the key 'wt_dc_debug'
    
    [self toggleSetting:kWTConfigDebug];
}

- (void)toggleSetting:(NSString *)settingName
{
    // Webtrends settings all take strings as arguments when setting, and return id when fetched.
    // The object they return will either be a NSString, or a NSNumber (which can be cast as BOOL, NSInteger, double, etc.)
    // depending on what type of setting you're looking at. See the documentation for more details        
    BOOL enabled = [[[WTDataCollector sharedCollector] valueForConfigKey:settingName] boolValue];
    NSString *toggle = @"true";
    if (enabled) {
        toggle = @"false";
    }
    NSLog(@"%@ set to %@", settingName, toggle);
    [[WTDataCollector sharedCollector] setValue:toggle forConfigKey:settingName persists:YES];
}

- (IBAction)pauseSending:(id)sender
{
    // This pauses the network activity associated with sending events on a scheduled interval,
    // but doesn't prevent the data collector from doing other tasks, such as logging new events
    [[WTDataCollector sharedCollector] pause];
}

- (IBAction)startSending:(id)sender
{
    // This pauses the network activity associated with sending events on a scheduled interval,
    // but doesn't prevent the data collector from doing other tasks, such as logging new events
    [[WTDataCollector sharedCollector] resume];
}
@end
