//
//  TransactionsViewController.m
//  ObjCSample
//
//  Created by Sam Ingle on 6/23/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "TransactionsViewController.h"
#import "WebtrendsSDK.h"

@interface TransactionsViewController ()

@end

@implementation TransactionsViewController

- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar {
    
    // Create an event for our product view
    // Start by creating a meta object containing basic information about the event
    // eventPath can be nil if you want to use the default eventPath.
    // customParams are an optional dictionary containing string keys and string values.
    
    WTEventMeta *meta = [WTEventMeta eventMetaForPath:nil description:@"User triggered search" type:@"Tap Event" customParams:nil];
    [[WTDataCollector sharedCollector] triggerEventForSearchPhrase:searchBar.text searchResult: @"Search result" eventMeta:meta];
    
    [self.view endEditing:NO];
    UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"Search Event Triggered" message:@"Search event has been added to data collector" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
}

@end
