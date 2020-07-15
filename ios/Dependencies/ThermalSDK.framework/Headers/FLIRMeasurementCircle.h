//
//  FLIRMeasurementCircle.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import "FLIRMeasurementArea.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Defines the circle measurement tool shape.
 *  Circle is described by a surrounding rectangle.
 *  This tool allows to measure temperature in circle area.
 *  It gives the possibility to find area's minimum, maximum and average temperature.
 *  There is functionality to find the exact location for minimum and maximum values.
 */
@interface FLIRMeasurementCircle : FLIRMeasurementArea

/**
 *  Gets/sets x,y positon
 */
@property (readwrite) CGPoint position;

/**
 *  Gets/sets radius
 */
@property (readwrite) int radius;

@end

NS_ASSUME_NONNULL_END
