//
//  FLIRMeasurementArea.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import "FLIRMeasurementMarker.h"

/**
 *  Represents a measurement area object.
 */
@interface FLIRMeasurementArea : FLIRMeasurementMarker

/**
 *  Gets or sets the width of this measurement object.
 */
@property (readonly) uint32_t width;

/**
 *  Gets or sets the height of this measurement object.
 */
@property (readonly) uint32_t height;


@end
