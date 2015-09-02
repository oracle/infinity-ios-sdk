//
//  LoginViewController.swift
//  SwiftSample
//
//  Created by Sam Ingle on 6/19/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

import UIKit

class LoginViewController: UIViewController {

    @IBAction func signIn(sender: AnyObject) {
        
        // Create an event for our button action
        // Start by creating a meta object containing basic information about the event
        // eventPath can be nil if you want to use the default eventPath
        // customParams are an optional dictionary containing string keys and string values
        
        let meta = WTEventMeta(eventPath: nil, description: "Sign-in button tapped!", type: "Tap Event", customParams: nil)
        
        // Once we've set up our basic information, pass it to the data collector
        WTDataCollector.sharedCollector().triggerEventForAction(meta)
        
    }
}

