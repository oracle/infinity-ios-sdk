//
//  AppDelegate.swift
//  SwiftSample
//
//  Created by Sam Ingle on 6/19/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    // These method must be present in order to track automatic events through the Webtrends
    // SDK. If you have automatics enabled, and want to see events for application launch, resign, 
    // foreground, background, or terminate, make sure the accompanying UIApplicationDelegate
    // method is present on your AppDelegate (even if its implementation is empty)
    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        
        return true
    }

    func applicationWillResignActive(application: UIApplication) {

    }

    func applicationDidEnterBackground(application: UIApplication) {

    }

    func applicationWillEnterForeground(application: UIApplication) {

    }

    func applicationDidBecomeActive(application: UIApplication) {

    }

    func applicationWillTerminate(application: UIApplication) {

    }

    // These next three methods are only needed if your app receives notifications
    func application(application: UIApplication, didReceiveLocalNotification notification: UILocalNotification) {
        //Your extra code here.
    }
    
    func application(application: UIApplication, didReceiveRemoteNotification userInfo: [NSObject : AnyObject]) {
        //Your extra code here.
    }
    
    func application(application: UIApplication, didReceiveRemoteNotification userInfo: [NSObject : AnyObject], fetchCompletionHandler completionHandler: (UIBackgroundFetchResult) -> Void) {
        //Your extra code here.
    }
    
    func application(application: UIApplication, openURL url: NSURL, sourceApplication: String?, annotation: AnyObject) -> Bool {
        //Your extra code here.
        return true;
    }
    
    /**
    *  To attach a debugger to the main app while running a watch kit app, complete the following steps:
    *  1. Build and run the main app
    *  2. Build and run the watch kit app. This will terminate the main app.
    *  3. Launch the main app from the device/simulator
    *  4a. For Simulators: In Xcode, select Debug -> Attach to Process -> Your App name
    *  4b. For Devices: In Xcode, select Debug -> Attach to Process -> By Proccess Identifier or Name -> Type the name of your application
    *
    *  To view the debug logs for a device or simulator, follow these steps:
    *  Simulator:
    *  1. Build and run the main app
    *  2. Build and run the watch kit app. This will terminate the main app.
    *  3. Launch the main app from the simulator
    *  4. From the simulator, choose Debug -> Open System Log
    *
    *  Device
    *  1. Build and run the main app
    *  2. Build and run the watch kit app. This will terminate the main app.
    *  3. Launch the main app from the device
    *  4. In Xcode, choose Window-> Devices -> <Your Device> -> View Device Logs
    */
    func application(application: UIApplication, handleWatchKitExtensionRequest userInfo: [NSObject : AnyObject]?, reply: (([NSObject : AnyObject]?) -> Void)) {
        let alert = UIAlertView(title: "Watch Event Received", message: "An event from the Apple watch was received. See debug log for more details. See -application:handleWatchKitExtensionRequest:userInfo:reply in AppDelegate for instructions on attaching to the debugger or view debug logs while a WatchKit app is running", delegate: nil, cancelButtonTitle: "OK")
        alert.show()
        print(userInfo)
    }
}

