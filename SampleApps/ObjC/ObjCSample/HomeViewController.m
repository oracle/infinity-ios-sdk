//
//  HomeViewController.m
//  ObjCSample
//
//  Created by Sam Ingle on 6/23/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "HomeViewController.h"
#import "WebtrendsSDK.h"

@interface HomeViewController ()

@end

@implementation HomeViewController

- (IBAction)showTab:(id)sender
{
    self.tabBarController.selectedIndex = [sender tag];
}

- (IBAction)visitWebsite:(id)sender
{
    // For hybrid apps, you can use the data collector's openURL method to pass
    // session state off to a web page in Safari
    NSURL *url = [NSURL URLWithString:@"https://bank.wt-go.com/"];
    [[WTDataCollector sharedCollector] openURL:url];
}
@end
