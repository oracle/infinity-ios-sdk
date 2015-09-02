//
//  InterfaceController.m
//  WTBank ObjC WatchKit Extension
//
//  Created by Sam Ingle on 6/25/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "InterfaceController.h"
#import "WebtrendsWatchKitSDK.h"

@interface InterfaceController()

@property (weak, nonatomic) IBOutlet WKInterfaceLabel *balanceLabel;
@property (nonatomic) NSInteger balance;
@end


@implementation InterfaceController

- (void)awakeWithContext:(id)context {
    [super awakeWithContext:context];
    self.balance = 100;
}
- (IBAction)refreshBalance
{
    self.balance++;
    [self.balanceLabel setText:[NSString stringWithFormat:@"$%@", @(self.balance)]];
    
    WTEventMeta *meta = [WTEventMeta eventMetaForPath:nil description:@"InterfaceController" type:@"Tap" customParams:nil];
    [[WTWatchDataCollector sharedCollector] sendEventForAction:meta];
}

- (void)willActivate {
    // This method is called when watch view controller is about to be visible to user
    [super willActivate];
}

- (void)didDeactivate {
    // This method is called when watch view controller is no longer visible
    [super didDeactivate];
}

@end



