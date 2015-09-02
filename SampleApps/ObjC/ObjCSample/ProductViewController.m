//
//  ProductViewController.m
//  ObjCSample
//
//  Created by Sam Ingle on 6/23/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "ProductViewController.h"
#import "WebtrendsSDK.h"

@interface ProductViewController ()

@end

@implementation ProductViewController

-(IBAction)cardTapped:(id)sender{
    
    NSString *cardString = @"";
    NSString *cardSku = @"";
    
    switch ([sender tag]) {
        case 1:
            cardString = @"Blue";
            cardSku = @"111";
            break;
            
        case 2:
            cardString = @"Gold";
            cardSku = @"222";
            break;
            
        case 3:
            cardString = @"Platinum";
            cardSku = @"333";
            break;

        default:
            break;
    }
    
    // Create an event for our product view
    // Start by creating a meta object containing basic information about the event
    // eventPath can be nil if you want to use the default eventPath. In this case, we're
    // overriding the default path with our custom /bank/products path
    // customParams are an optional dictionary containing string keys and string values.
    // In this case, we're passing a simple custom parameters dictionary with one key value pair
    WTEventMeta *meta = [WTEventMeta eventMetaForPath:@"/bank/products" description:@"user tapped product" type:@"tap" customParams:@{@"myCustomParam":@"myCustomValue"}];
    
    // Once we've set up our basic information, pass it to the data collector

    [[WTDataCollector sharedCollector] triggerEventForProductId:cardString productSku:cardSku contentGroup:@"Logged in" eventMeta:meta];
    
    NSString *alertTitle = [cardString stringByAppendingString:@" Event Triggered"];
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:alertTitle message: @"Product event has been added to data collector" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    
    [alert show];
}

@end
