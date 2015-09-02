//
//  ViewController.m
//  ObjCSample
//
//  Created by Sam Ingle on 6/23/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "LoginViewController.h"
#import "WebtrendsSDK.h"
@interface LoginViewController ()

@end

@implementation LoginViewController

- (IBAction)signIn:(id)sender
{
    // Create an event for our button action
    // Start by creating a meta object containing basic information about the event
    // eventPath can be nil if you want to use the default eventPath
    // customParams are an optional dictionary containing string keys and string values
    WTEventMeta *meta = [WTEventMeta eventMetaForPath:nil description:@"Sign-in button tapped!" type:@"Tap Event" customParams:nil];
    
    // Once we've set up our basic information, pass it to the data collector
    [[WTDataCollector sharedCollector] triggerEventForAction:meta];
}

@end
