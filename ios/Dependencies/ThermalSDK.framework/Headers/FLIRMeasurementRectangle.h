//
//  FLIRMeasurementRectangle.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import "FLIRMeasurementArea.h"

/**
 *  Represents a MeasurementRectangle object.
 */
@interface FLIRMeasurementRectangle : FLIRMeasurementArea

/**
 *  Gets/sets x,y positon
 */
@property (readwrite) CGPoint position;

/**
 *  Get/sets the measurement rectangle, position and size
 */
@property (readwrite) CGRect rectangle;


@end
