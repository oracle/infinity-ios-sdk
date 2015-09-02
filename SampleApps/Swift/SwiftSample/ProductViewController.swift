//
//  ProductViewController.swift
//  SwiftSample
//
//  Created by Sam Ingle on 6/22/15.
//  Copyright © 2015 Webtrends. All rights reserved.
//

import UIKit

class ProductViewController: UIViewController {

    @IBAction func cardTapped(sender: AnyObject) {
        var cardString = ""
        var cardSku = ""
        
        switch (sender.tag){
            
        case 1:
            cardString = "Blue"
            cardSku = "111"
            break
            
        case 2:
            cardString = "Gold"
            cardSku = "222"
            break
            
        case 3:
            cardString = "Platinum"
            cardSku = "333"
            break
            
        default:
            break
        }
        
        // Create an event for our product view
        // Start by creating a meta object containing basic information about the event
        // eventPath can be nil if you want to use the default eventPath. In this case, we're
        // overriding the default path with our custom /bank/products path
        // customParams are an optional dictionary containing string keys and string values.
        // In this case, we're passing a simple custom parameters dictionary with one key value pair
        let meta = WTEventMeta(eventPath: "/bank/products", description: "user tapped card product", type: "tap", customParams: ["myCustomParam":"myCustomValue"])
        
        // Once we've set up our basic information, pass it to the data collector
        WTDataCollector.sharedCollector().triggerEventForProductId(cardString, productSku: cardSku, contentGroup: "Logged In", eventMeta: meta)
        
        let alert = UIAlertView(title: "\(cardString) Event Triggered", message: "Product event has been added to data collector", delegate: nil, cancelButtonTitle: "OK")
        alert.show()
        
    }
}
