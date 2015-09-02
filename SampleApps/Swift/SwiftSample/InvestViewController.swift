//
//  InvestViewController.swift
//  SwiftSample
//
//  Created by Sam Ingle on 6/22/15.
//  Copyright © 2015 Webtrends. All rights reserved.
//

import UIKit

class InvestViewController: UIViewController, UIWebViewDelegate {

    @IBOutlet weak var webView: UIWebView!
    
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
    
    let wtDelegate = WTUIWebViewDelegate()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let url = NSURL(string: "https://bank.wt-go.com/invest")
        
        // If we want to share a session between the app and the website,
        // we'll append it to the URL before triggering the request
        // using the appendSessionParamsToUrl: method below
        let sessionedUrl = WTDataCollector.sharedCollector().appendSessionParamsToUrl(url)

        // There are two methods of alerting the Data Collector of JavaScript-triggered
        // events. The first is using the supplied WTUIWebViewDelegate, shown in "Method 1" below.
        // The second is implementing your own delegate as described in "Method 2" below
        
        // Method 1
        // Set our retained WTUIWebViewDelegate as the UIWebView's delegate
        webView.delegate = wtDelegate
        
        // Method 2
        // If we do need our own web view delegation methods, we'd mark ourself as the delegate.
        // If we do this, we must implement webView:ShouldStartLoadWithRequest:navigationType
        //webView.delegate = self
        
        webView.loadRequest(NSURLRequest(URL: sessionedUrl))
    }
    
    // This method must be present if we're not using a retained instance of WTUIWebViewDelegate 
    // as our delegate, otherwise the app won't be able to see JavaScript-triggered events
    func webView(webView: UIWebView, shouldStartLoadWithRequest request: NSURLRequest, navigationType: UIWebViewNavigationType) -> Bool {
        //Any custom logic here
        
        return true
    }

}
