The Webtrends SDK is a analytics library for iOS. This guide will walk you through the initial setup process, from integrating the SDK with your project, to sending events to Webtrends.

##Basic Installation
In its simplest incarnation, the Webtrends SDK can be installed with a single line in your existing `Podfile`:

	pod 'Webtrends-SDK/Core', '~>3.0'

If you're not familiar with CocoaPods, or you need a more advanced installation (such as integrating the Webtrends WatchKit SDK), you can read our [Getting Started Guide](docs/public_guides/Getting-Started-Guide.html).

##Common Actions
The documentation below has detailed explanations of the entire SDK, but for convenience, this guide provides sample code for a couple common actions you might take with the SDK, such as triggering events, setting configuration settings, and pausing/resuming event sending.

###Triggering Events

Many events are triggered automatically on your behalf. In most cases you won't need to do any additional work to receive events related to the application or view controller life cycles. You can read more about this in the [Automatic Events Guide](docs/public_guides/Automatic-Events-Guide).

If you want to manually log events, the process is pretty simple. Here's an example of how to send an event associated with a button press:

#####Swift
	// eventPath can be nil if you want to use the default eventPath
	let meta = WTEventMeta(eventPath: nil, description: "Sign-in button tapped!", type: "Tap Event", customParams: nil)
	
	// Once we've set up our basic information, pass it to the data collector
	WTDataCollector.sharedCollector().triggerEventForAction(meta)

#####Objective-C
	// eventPath can be nil if you want to use the default eventPath
	WTEventMeta *meta = [WTEventMeta eventMetaForPath:nil description:@"Sign-in button tapped!" type:@"Tap Event" customParams:nil];
	    
	[[WTDataCollector sharedCollector] triggerEventForAction:meta];

There are a wide variety of events you can trigger, all of which are documented in <WTDataCollector> and [Manual Events Guide](docs/public_guides/Manual-Events-Guide.html).

###Setting Configuration Settings
Here's an example of how to disable Webtrends debug logging:

#####Swift
	WTDataCollector.sharedCollector().setValue("false", forConfigKey:kWTConfigDebug, persists: true)

#####Objective-C
	[[WTDataCollector sharedCollector] setValue:@"false" forConfigKey:kWTConfigDebug persists:YES];

For a full list of configurable settings, see the [Advanced Configuration Guide](docs/public_guides/Advanced-Configuration-Guide.html)

###Pausing/Resuming Event Sending
Here's an example of how to pause then resume event sending:

#####Swift
	WTDataCollector.sharedCollector().pause()
	WTDataCollector.sharedCollector().resume()

#####Objective-C
	[[WTDataCollector sharedCollector] pause];
	[[WTDataCollector sharedCollector] resume];
	
###Hybrid Application Support
Webtrends provides a method of keeping continuing sessions between a web browser and a native app. The process is a little more involved than some of the examples above, but you can read about it in both the [Hybrid Events Guide](docs/public_guides/Hybrid-Events-Guide.html) and the [Embedded Browser Events Guide](docs/public_guides/Embedded-Browser-Events-Guide.html).