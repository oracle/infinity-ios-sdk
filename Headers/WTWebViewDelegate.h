//
//  WTWebViewDelegate.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 6/16/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;
@import WebKit;

/**
 * # UIWebView
 *  Generating events through the Webtrends JavaScript tag UIWebViews embedded in a native app can generate Webtrends events by using JavaScript helper methods that interact with the native app to generate and send events, or by using the Webtrends JavaScript tag in the embedded web content to generate and send events. Follow these instructions to use the Webtrends JavaScript tag.
 *
 *  The native app must implement the Webtrends Mobile Library for iOS, the web content must be tagged with the Webtrends JavaScript tag, and you must be familiar with iOS UIWebViews.
 *
 *  If we don't need to do any web view delegation of our own, we'll simply create a retained instance of WTWebViewDelegate and let it do the work for us
 * There are two methods of alerting the Data Collector of JavaScript-triggered events. The first is using the supplied WTWebViewDelegate, shown here:
 * ## Method 1 – Webtrends supplied delegate
 *  	- (void)viewDidLoad {
 *  	    [super viewDidLoad];
 *  	    NSURL *url = [NSURL URLWithString:@"https://bank.wt-go.com/invest"];
 *
 *  	    // If we want to share a session between the app and the website,
 *  	    // we'll append it to the URL before triggering the request
 *  	    // using the appendSessionParamsToUrl: method below
 *  	    NSURL *sessionedUrl = [[WTDataCollector sharedCollector] appendSessionParamsToUrl:url];
 *
 *  	    // Set our retained WTWebViewDelegate as the UIWebView's delegate
 *  	    self.webView.delegate = self.wtDelegate;
 *
 *  	    [self.webView loadRequest:[NSURLRequest requestWithURL:sessionedUrl]];
 *  	}
 *
 * If we need our own web view delegation methods, we'd mark ourself as the delegate as follows.
 * ## Method 2 – Self-supplied delegate
 *  	- (void)viewDidLoad {
 *  	    [super viewDidLoad];
 *  	    NSURL *url = [NSURL URLWithString:@"https://bank.wt-go.com/invest"];
 *
 *  	    // If we want to share a session between the app and the website,
 *  	    // we'll append it to the URL before triggering the request
 *  	    // using the appendSessionParamsToUrl: method below
 *  	    NSURL *sessionedUrl = [[WTDataCollector sharedCollector] appendSessionParamsToUrl:url];
 *
 *  	    // If we do this, we must implement webView:ShouldStartLoadWithRequest:navigationType
 *  	    self.webView.delegate = self;
 *  	    [self.webView loadRequest:[NSURLRequest requestWithURL:sessionedUrl]];
 *  	}
 *
 *  	// This method must be present if we're not using a retained instance of WTWebViewDelegate
 *  	// as our delegate, otherwise the app won't be able to see JavaScript-triggered events
 *  	- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType
 *  	{
 *          if (![WTWebViewDelegate shouldStartLoadWithRequest:request])
 *          {
 *              return NO;
 *          }
 *  	    //Any custom logic here
 *  	    return YES;
 *  	}
 * # WKWebview
 * When using WKWebview, conform to WKNavigationDelegate, and implement -webView:decidePolicyForNavigationAction:decisionHandler:
 * Include the following inside your method:
 *      - (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler
 *      {
 *          BOOL shouldStart = [WTWebViewDelegate shouldStartLoadWithRequest:navigationAction.request];
 *          if (!shouldStart)
 *          {
 *              decisionHandler(WKNavigationActionPolicyCancel);
 *              return;
 *          }
 *          // Any custom decision policy code
 *      }

 */
@interface WTWebViewDelegate : NSObject <UIWebViewDelegate>

+ (BOOL)shouldStartLoadWithRequest:(NSURLRequest *)request;

@end
