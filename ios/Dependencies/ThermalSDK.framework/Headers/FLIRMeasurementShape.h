//
//  MeasurementShape.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FLIRMeasurementParameters.h"

/**
 *  The class is a base class for other measurement shapes. The class has the basic properties
 *  and methods for a measurement shape.
 */
@interface FLIRMeasurementShape : NSObject

/**
 *  Gets the identity on the measurement shape.
 */
@property (readonly) uint32_t identity;

/**
 *  Gets or sets the name of the measurement shape.
 */
@property (nonatomic,readwrite) NSString *name;

/**
 *  Gets the object parameters for this measurement shape.
 */
@property (nonatomic,readonly) FLIRMeasurementParameters *thermalParameters;

/**
 *  Adjusts the location of this measurement shape by the specified amount.
 *
 *  @param offset Amount to offset the location.
 */
-(void) offset:(CGPoint) offset;

/**
 *  Move the location of this measurement shape to the specified position.
 *
 *  @param point Position
 */
-(void) moveTo:(CGPoint) point;
@end
