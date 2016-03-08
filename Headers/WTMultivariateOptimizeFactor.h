//
//  WTTextOptimizeTest.h
//  Webtrends-SDK
//
//  Created by Sam Ingle on 7/14/15.
//  Copyright (c) 2015 Webtrends. All rights reserved.
//

#import "WTOptimizeFactor.h"

@import UIKit;

extern NSString * const kWTFactorKeyText;
extern NSString * const kWTFactorKeyButtonText;
extern NSString * const kWTFactorKeyPlaceholder;
extern NSString * const kWTFactorKeyBackgroundColor;
extern NSString * const kWTFactorKeyTextColor;
extern NSString * const kWTFactorKeyButtonTextColor;
extern NSString * const kWTFactorKeyBackgroundColor;
extern NSString * const kWTFactorKeyTextAlignment;
extern NSString * const kWTFactorKeyFont;
extern NSString * const kWTFactorKeyFontName;
extern NSString * const kWTFactorKeyFontSize;
extern NSString * const kWTFactorKeyAttributes;
extern NSString * const kWTFactorKeyBaseAttributes;
extern NSString * const kWTFactorKeyButtonAttributes;
extern NSString * const kWTFactorKeyButtonBaseAttributes;
extern NSString * const kWTFactorKeyAttributeStartIndex;
extern NSString * const kWTFactorKeyAttributeEndIndex;
extern NSString * const kWTFactorKeyKeyPaths;
extern NSString * const kWTFactorKeyButtonNormal;
extern NSString * const kWTFactorKeyButtonDisabled;
extern NSString * const kWTFactorKeyButtonHighlighted;
extern NSString * const kWTFactorKeyButtonSelected;
extern NSString * const kWTFactorKeyImage;
extern NSString * const kWTFactorKeyBackgroundImage;
extern NSString * const kWTFactorKeyImageName;
extern NSString * const kWTFactorKeyImageInsetLeft;
extern NSString * const kWTFactorKeyImageInsetRight;
extern NSString * const kWTFactorKeyImageInsetTop;
extern NSString * const kWTFactorKeyImageInsetBottom;

/**
 *  Used to optimize various aesthetic options in multiple types of views. Generally accessed via one of the SDK-provided UIView subclasses, but can be directly accessed for creating testable custom UI.
 */
@interface WTMultivariateOptimizeFactor : WTOptimizeFactor

/**
 *  The parsed text value, generally used in labels, textViews, and textFields
 */
@property (strong, nonatomic, readonly) NSString *text;

/**
 *  The button text dictionary, stores information mapping to a button's UIControlState
 */
@property (strong, nonatomic, readonly) NSDictionary *buttonText;

/**
 *  The placeholder text, generally used in textFields
 */
@property (strong, nonatomic, readonly) NSString *placeholder;

/**
 *  The element's background color, used on any UI element.
 */
@property (strong, nonatomic, readonly) UIColor *backgroundColor;

/**
 
 *  The element's text color, generally used in labels, textViews, and textFields
 */
@property (strong, nonatomic, readonly) UIColor *textColor;

/**
 *  The button text color dictionary, stores information mapping to a button's UIControlState
 */
@property (strong, nonatomic, readonly) NSDictionary *buttonTextColor;

/**
 *  The element's text alignment, generally used in labels, textViews, textFields, and buttons
 */
@property (nonatomic, readonly) NSTextAlignment textAlignment;

/**
 *  The element's font, generally used in labels, textViews, textFields, and buttons
 */
@property (strong, nonatomic, readonly) UIFont *font;

/**
 *  The button image dictionary, stores information mapping to a button's UIControlState
 */
@property (strong, nonatomic, readonly) NSDictionary *imageDictionary;

/**
 *  The button background image, stores information mapping to a button's UIControlState. Can include information for creating resizable images.
 */
@property (strong, nonatomic, readonly) NSDictionary *backgroundImageDictionary;

/**
 *  The parsed attributed text value, generally used in labels, textViews, and textFields
 */
@property (strong, nonatomic, readonly) NSAttributedString *attributedText;

/**
 *  The button attributed text dictionary, stores information mapping to a button's UIControlState
 */
@property (strong, nonatomic, readonly) NSDictionary *buttonAttributedText;

- (BOOL)applyKeyPaths:(id)object;

@end
