//
//  TransactionsViewController.swift
//  SwiftSample
//
//  Created by Sam Ingle on 6/22/15.
//  Copyright © 2015 Webtrends. All rights reserved.
//

import UIKit

class TransactionsViewController: UITableViewController, UISearchBarDelegate {
    
    func searchBarSearchButtonClicked(searchBar: UISearchBar) {
        
        // Create an event for our product view
        // Start by creating a meta object containing basic information about the event
        // eventPath can be nil if you want to use the default eventPath.
        // customParams are an optional dictionary containing string keys and string values.
        let meta = WTEventMeta(eventPath: nil, description: "user triggered search", type: "tap", customParams: nil)
        WTDataCollector.sharedCollector().triggerEventForSearchPhrase(searchBar.text, searchResult: "Search result", eventMeta: meta)
        
        self.view.endEditing(false)
        let alert = UIAlertView(title: "Search Event Triggered", message: "Search event has been added to data collector", delegate: nil, cancelButtonTitle: "OK")
        alert.show()
    }

}
