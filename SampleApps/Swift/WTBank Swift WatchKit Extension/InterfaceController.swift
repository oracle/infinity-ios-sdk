//
//  InterfaceController.swift
//  WTBank Swift WatchKit Extension
//
//  Created by Sam Ingle on 6/26/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

import WatchKit
import Foundation

class InterfaceController: WKInterfaceController {
    @IBOutlet weak var balanceLabel: WKInterfaceLabel!
    
    var balance = 100

    @IBAction func refreshBalance() {
        balance++
        balanceLabel.setText("$\(balance)")
        let meta = WTEventMeta(eventPath: nil, description: "InterfaceController", type: "tap", customParams: nil)
        WTWatchDataCollector.sharedCollector().sendEventForAction(meta)
    }
    override func awakeWithContext(context: AnyObject?) {
        super.awakeWithContext(context)
        
        // Configure interface objects here.
    }

    override func willActivate() {
        // This method is called when watch view controller is about to be visible to user
        super.willActivate()
    }

    override func didDeactivate() {
        // This method is called when watch view controller is no longer visible
        super.didDeactivate()
    }

}
