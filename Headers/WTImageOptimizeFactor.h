//
//  WTImageOptimizeTest.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 7/14/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

@import UIKit;
#import "WTOptimizeFactor.h"

/**
 *  Used to optimize an image with a remote source. Normally accessed by way of WTOptimizeImageView, but if you need raw access to the image, you can use this class directly.
 */
@interface WTImageOptimizeFactor : WTOptimizeFactor

/**
 *  The location of the remote image, if you'd prefer to manage downloading yourself.
 */
@property (strong, nonatomic, readonly) NSURL *remoteURL;
/**
 *  The image, or nil if it hasn't been cached yet
 */
@property (strong, nonatomic, readonly) UIImage *image;

@end
