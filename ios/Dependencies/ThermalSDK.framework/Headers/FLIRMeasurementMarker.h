//
//  FLIRMeasurementMarker.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import "FLIRMeasurementShape.h"
#import "FLIRThermalValue.h"

/**
 *  Represents the marker objects of the measurement object
 */
@interface FLIRMeasurementMarker : FLIRMeasurementShape

/**
 *  Gets the average value of this measurement object.
 */
@property (nonatomic,readonly) FLIRThermalValue *average;

/**
 *  Gets the max value of this measurement object.
 */
@property (nonatomic,readonly) FLIRThermalValue *max;

/**
 *  Gets the min value of this measurement object.
 */
@property (nonatomic,readonly) FLIRThermalValue *min;

/**
 *  Gets the position of the hot spot on the image.
 */
@property (nonatomic,readonly) CGPoint hotSpot;

/**
 *  Gets the position of the cold spot on the image.
 */
@property (nonatomic,readonly) CGPoint coldSpot;

/**
 *  Average is enabled. The average value should be displayed in the result table as seen in the camera overlay.
 */
@property (nonatomic,readonly) BOOL isAverageEnabled;

/**
 *  Hot Spot is enabled. The hot spot value should be displayed in the result table as seen in the camera overlay.
 */
@property (nonatomic,readonly) BOOL isHotSpotEnabled;

/**
 *  Marker is visible. The marker glyph should be displayed as seen in the camera overlay.
 */
@property (nonatomic,readonly) BOOL isHotSpotVisible;

/**
 *  Cold spot is enabled. The cold spot value should be displayed in the result table as seen in the camera overlay.
 */
@property (nonatomic,readonly) BOOL isColdSpotEnabled;

/**
 *  Marker is visible. The marker glyph should be displayed as seen in the camera overlay.
 */
@property (nonatomic,readonly) BOOL isColdSpotVisible;

@end
