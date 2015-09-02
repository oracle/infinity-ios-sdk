//
//  AppDelegate.m
//  ObjCSample
//
//  Created by Sam Ingle on 6/23/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

// These method must be present in order to track automatic events through the Webtrends
// SDK. If you have automatics enabled, and want to see events for application launch, resign,
// foreground, background, or terminate, make sure the accompanying UIApplicationDelegate
// method is present on your AppDelegate (even if its implementation is empty)

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {

}

- (void)applicationDidEnterBackground:(UIApplication *)application {

}

- (void)applicationWillEnterForeground:(UIApplication *)application {

}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    
}

- (void)applicationWillTerminate:(UIApplication *)application {

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
- (void)application:(UIApplication *)application handleWatchKitExtensionRequest:(NSDictionary *)userInfo reply:(void (^)(NSDictionary *))reply
{
    [[[UIAlertView alloc] initWithTitle:@"Watch Event Received" message:@"An event from the Apple watch was received. See debug log for more details. See -application:handleWatchKitExtensionRequest:userInfo:reply in AppDelegate for instructions on attaching to the debugger or view debug logs while a WatchKit app is running" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
    NSLog(@"%@", userInfo);
}

@end
