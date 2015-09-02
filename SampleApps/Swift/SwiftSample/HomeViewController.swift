//
//  HomeViewController.swift
//  SwiftSample
//
//  Created by Sam Ingle on 6/22/15.
//  Copyright © 2015 Webtrends. All rights reserved.
//

import UIKit

class HomeViewController: UIViewController {
    
    @IBAction func showTab(sender: AnyObject) {
        self.tabBarController?.selectedIndex = sender.tag
    }

    @IBAction func visitWebsite(sender: AnyObject) {
        
        // For hybrid apps, you can use the data collector's openURL method to pass
        // session state off to a web page in Safari
        let url = NSURL(string: "https://bank.wt-go.com/")
        WTDataCollector.sharedCollector().openURL(url)
    }
    
}
