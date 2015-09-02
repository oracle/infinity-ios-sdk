//
//  SettingsViewController.swift
//  SwiftSample
//
//  Created by Sam Ingle on 6/22/15.
//  Copyright © 2015 Webtrends. All rights reserved.
//

import UIKit

class SettingsViewController: UIViewController {
    
    @IBAction func toggleDataCollection(sender: AnyObject) {
        // When set to "false", this setting will disable the entire WebtrendsSDK. No events
        // will be logged while this is disabled. This can also be set in webtrends.plist
        // under the key 'wt_dc_enabled'
        toggleSetting(kWTConfigEnabled)
    }
    
    @IBAction func toggleDebugLogging(sender: AnyObject) {
        // When set to "false", this setting will disable all logging from the Webtrends SDK. No events
        // will be logged while this is disabled. This can also be set in webtrends.plist
        // under the key 'wt_dc_debug'

        toggleSetting(kWTConfigDebug)
    }
    
    func toggleSetting(settingName: String){
        
        // Webtrends settings all take strings as arguments when setting, and return AnyObject! when fetched.
        // The object they return will either be a String, or a number (which can be cast as Bool, Int, Double, etc.)
        // depending on what type of setting you're looking at. See the documentation for more details
        let enabled = WTDataCollector.sharedCollector().valueForConfigKey(settingName) as! Bool
        var toggle = "true"
        if enabled {
            toggle = "false"
        }
        
        WTDataCollector.sharedCollector().setValue(toggle, forConfigKey: settingName, persists: true)
    }

    @IBAction func pauseSending(sender: AnyObject) {
        // This pauses the network activity associated with sending events on a scheduled interval,
        // but doesn't prevent the data collector from doing other tasks, such as logging new events
        WTDataCollector.sharedCollector().pause()
    }
    @IBAction func startSending(sender: AnyObject) {
        // This pauses the network activity associated with sending events on a scheduled interval,
        // but doesn't prevent the data collector from doing other tasks, such as logging new events
        WTDataCollector.sharedCollector().resume()
    }
    
}
