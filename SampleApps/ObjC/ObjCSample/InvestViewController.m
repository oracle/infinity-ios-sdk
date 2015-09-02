//
//  InvestViewController.m
//  ObjCSample
//
//  Created by Sam Ingle on 6/23/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "InvestViewController.h"
#import "WebtrendsSDK.h"

@interface InvestViewController ()

@property (weak, nonatomic) IBOutlet UIWebView *webView;

// Generating events through the Webtrends JavaScript tag
// UIWebViews embedded in a native app can generate Webtrends events by using JavaScript helper
// methods that interact with the native app to generate and send events, or by using the
// Webtrends JavaScript tag in the embedded web content to generate and send events. Follow
// these instructions to use the Webtrends JavaScript tag.
//
// The native app must implement the Webtrends Mobile Library for iOS, the web content must be
// tagged with the Webtrends JavaScript tag, and you must be familiar with iOS UIWebViews.

// If we don't need to do any web view delegation of our own, we'll simply create a
// retained instance of WTUIWebViewDelegate and let it do the work for us
@property (strong, nonatomic) WTUIWebViewDelegate *wtDelegate;

@end

@implementation InvestViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSURL *url = [NSURL URLWithString:@"https://bank.wt-go.com/invest"];
    
    // If we want to share a session between the app and the website,
    // we'll append it to the URL before triggering the request
    // using the appendSessionParamsToUrl: method below
    NSURL *sessionedUrl = [[WTDataCollector sharedCollector] appendSessionParamsToUrl:url];
    
    // There are two methods of alerting the Data Collector of JavaScript-triggered
    // events. The first is using the supplied WTUIWebViewDelegate, shown in "Method 1" below.
    // The second is implementing your own delegate as described in "Method 2" below
    
    // Method 1
    // Set our retained WTUIWebViewDelegate as the UIWebView's delegate
    self.webView.delegate = self.wtDelegate;
    
    // Method 2
    // If we do need our own web view delegation methods, we'd mark ourself as the delegate.
    // If we do this, we must implement webView:ShouldStartLoadWithRequest:navigationType
    //self.webView.delegate = self
    [self.webView loadRequest:[NSURLRequest requestWithURL:sessionedUrl]];

}

// This method must be present if we're not using a retained instance of WTUIWebViewDelegate
// as our delegate, otherwise the app won't be able to see JavaScript-triggered events
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType
{
    //Any custom logic here

    return YES;
}

@end
