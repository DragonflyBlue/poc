//
//  FLIRMeasurementLine.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import "FLIRMeasurementMarker.h"
#import "FLIRThermalValue.h"

NS_ASSUME_NONNULL_BEGIN
/**
 *  Defines a line measurement tool shape.
 *  The SDK supports only horizontal or vertical lines.
 *  This tool allows to measure temperature in line area.
 *  It gives the possibility to find area's minimum, maximum and average temperature.
 *  There is functionality to find the exact location for minimum and maximum values.
 */
@interface FLIRMeasurementLine : FLIRMeasurementMarker

/**  Set the location of a vertical line.
 *
 *  @param x    The x-coordinate where the line is placed.
 *  @param markerMin    A flag that sets the marker for the minimun temperature in the rectangle.
 *  @param markerMax    A flag that sets the marker for the maximun temperature in the rectangle.
 *
 *   X-coordinates should be positive values.
 */
-(void) setVerticalLine:(int) x MarkerMin:(bool) markerMin MarkerMax:(bool) markerMax;

/**  Set the location of a horizontal line.
 *
 *  @param y    The y-coordinate where the line is placed.
 *  @param markerMin    A flag that sets the marker for the minimun temperature in the rectangle.
 *  @param markerMax    A flag that sets the marker for the maximun temperature in the rectangle.
 *
 *   Y-coordinates should be positive values.
 */
-(void) setHorizontalLine:(int) y MarkerMin:(bool) markerMin MarkerMax:(bool) markerMax;

/** The start position of the line.
 *  A Point with (x,y)-coordinates. Error if point is (-1,-1).
 */
@property (readonly) CGPoint startPosition;

/** The end position of the line.
 *  A Point with (x,y)-coordinates. Error if point is (-1,-1).
 */
@property (readonly) CGPoint endPosition;

/**
 *  Checks, if the line measurement tool is horizontal.
 */
-(BOOL) isHorizontal;
@end

NS_ASSUME_NONNULL_END
