//
//  FLIRScale.h
//
//  Copyright © 2019 Flir Systems. All rights reserved.
//

#ifndef FLIRScale_h
#define FLIRScale_h
#endif


/**
 *  Defines an image's linear scale object and basic scale's parameters.
 *  The scale defines the way the Palette is applied to the ThermalImage.
 *  Scale is an interval of the temperature, where colors from a selected Palette is applied.
 *  The available temperature's range is defined by the ThermalImage.
 *  Scale cannot be created directly, it should always be obtained from ThermalImage.
 *  To do so, the ThermalImage.getScale() method should be called.
 */
@interface FLIRScale : NSObject

/**  
 *   Sets the minimum and maximum scale values.
 *
 *   @param min  The minimum scale value.
 *   @param max  The maximum scale value.
 */
-(void) setRangeWithMin: (double) min andMax: (double) max;

/** 
 *   Sets the scale automatically based on the min and max scale values.
 */
-(void) enableAutoAdjust;

/** 
 *  Gets the current minimum scale value.
 *  @return The min scale value.
 */
-(double) getRangeMin;

/** 
 *  Gets the current maximum scale value.
 *  @return The max scale value
 */
-(double) getRangeMax;

/** 
 *  Gets the thermal scale image.
 *
 *  @return An UIImage representing the thermal scale.
 */
-(UIImage*) getImage;

/**
 *  Gets auto adjust setting.
 */
-(BOOL) isAutoAdjustEnabled;

/**
 *  Sets the maximum range, where colors defined by the Palette are applied to the ThermalImage.
 */
-(void) setRangeMax:(double)max;

/**
 *  Sets the minimum range, where colors defined by the Palette are applied to the ThermalImage.
 */
-(void) setRangeMin:(double)min;

@end
