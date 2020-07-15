//
//  FLIRImageStatistics.h
//  Spartacus
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import "FLIRThermalValue.h"

/**
 *  Provides statistics for Thermal data for the ThermalImage.
 *  Defines such values as minimum, maximum and position, where they were measured, average and standard deviation.
 */
@interface FLIRImageStatistics : NSObject

/**
 *  Gets calculated Minimum temperature value.
 *
 *  @return The minimum value.
 */
-(FLIRThermalValue*)  getMin;

/** 
 *  Gets calculated Maximum temperature value.
 *
 *  @return The maximum value.
 */
-(FLIRThermalValue*)  getMax;

/**
 *  Gets calculated Average value of the temperature data associated with the ThermalImage.
 *
 *  @return The average value.
 */
-(FLIRThermalValue*)  getAverage;

/**
 *  Gets calculated Standard Deviation value of the temperature data associated with the ThermalImage.
 *
 *  @return The standard deviation value.
 */
-(FLIRThermalValue*)  getStandardDeviation;

/**
 *  Get the position (x,y-coordinate) to the pixel with the highest temperature.
 *
 *  @return A (x,y) point.
 */
-(CGPoint)  getHotSpot;

/**
 *  Get the position (x,y-coordinate) to the pixel with the lowest temperature.
 *
 *  @return A (x,y) point.
 */
-(CGPoint)  getColdSpot;

@end
