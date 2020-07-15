//
//  FLIRPaletteManager.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FLIRPalette.h"

/**
 *  Manages Palettes, which could be applied to ThermalImage. It allows getting a particular Palette object or a list of available Palettes.
 *  Every Palette returned can be applied to the ThermalImage and change it's look.
 *  Each Palette defines different colors for different temperature.
 *  The set of these colors allows to display the registered temperatures as an image.
 *  User have to get possibility to change the Palette applied to the image, because some of them are better for his use case.
 *  Some Palettes provide better contrast, while other expose the important details.
 */
@interface FLIRPaletteManager : NSObject

/**
 *  Gets the Arctic Palette.
 */
@property (readonly) FLIRPalette *arctic;

/**
 *  Gets the blackhot Palette.
 */
@property (readonly) FLIRPalette *blackhot;

/**
 *  Gets the gray / "black and white" Palette
 */
@property (readonly) FLIRPalette *gray;

/**
 *  Gets the iron Palette.
 */
@property (readonly) FLIRPalette *iron;

/**
 *  Gets the lava Palette.
 */
@property (readonly) FLIRPalette *lava;

/**
 *  Gets the rainbow Palette.
 */
@property (readonly) FLIRPalette *rainbow;

/**
 *  Gets the rainbow HighContrast Palette.
 */
@property (readonly) FLIRPalette *rainHC;

/**
 *  Gets the coldest Palette.
 */
@property (readonly) FLIRPalette *coldest;

/**
 *  Gets the hottest Palette.
 */
@property (readonly) FLIRPalette *hottest;

/**
 *  Gets the colorWheel6 Palette.
 */
@property (readonly) FLIRPalette *colorWheel6;

/**
 *  Gets the doubleRainbow Palette.
 */
@property (readonly) FLIRPalette *doubleRainbow;

/**
 *  Gets the whitehot Palette.
 */
@property (readonly) FLIRPalette *whitehot;

/**
 *  Built-in palette from image.
 */
@property (readonly) FLIRPalette *fromImage;

/**
 *  Open a palette file from disk. Palette files have .pal as file extension.
 *
 *  @param paletteFile Full path to a valid palette file.
 *
 *  @return Palette containing colors from the palette file.
 */
- (FLIRPalette *) open:(NSURL *) paletteFile;

/**
 *  Gets a list of default Palettes.
 *
 *  @return an array with the default palettes
 */
-(NSArray<FLIRPalette*>*) getDefaultPalettes;
@end
