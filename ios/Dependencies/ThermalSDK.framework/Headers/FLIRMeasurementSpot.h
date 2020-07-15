//
//  MeasurementSpot.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import "FLIRMeasurementShape.h"
#import "FLIRThermalValue.h"


/**
 *  Represents a MeasurementSpot object.
 */
@interface FLIRMeasurementSpot : FLIRMeasurementShape

/**
 *  Gets the value of this MeasurementSpot.
 */
@property (nonatomic,readonly) FLIRThermalValue *value;

/**
 *  Gets or sets the x-coordinate of this MeasurementSpot.
 */
@property (readwrite) uint32_t x;

/**
 *  Gets or sets the y-coordinate of this MeasurementSpot.
 */
@property (readwrite) uint32_t y;
@end
