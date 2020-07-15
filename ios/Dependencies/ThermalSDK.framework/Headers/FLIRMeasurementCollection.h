//
//  MeasurementCollection.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FLIRMeasurementSpot.h"
#import "FLIRMeasurementRectangle.h"
#import "FLIRMeasurementCircle.h"
#import "FLIRMeasurementLine.h"

/**
 *  Container for a different type of MeasurementShapes.
 *  It provides access to all measurements added to an image.
 *  It also allows to add a new measurements to an existing image.
 *  The collection is obtained FLIRThermalImage.Measurements.
 */
@interface FLIRMeasurementCollection : NSObject

/**
 *  Gets the collection of measurement deltas
 */
@property (nonatomic,readonly) NSMutableArray *measurementDeltas;

/**
 *  Gets the collection of measurement ellipsesAdds a new MeasurementSpot to the collection.
 */
@property (nonatomic,readonly) NSMutableArray *measurementCircles;

/**
 *  Gets the collection of measurement lines
 */
@property (nonatomic,readonly) NSMutableArray *measurementLines;

/**
 *  Gets the collection of measurement polygons
 */
@property (nonatomic,readonly) NSMutableArray *measurementPolygons;

/**
 *  Gets the collection of measurement rectangles
 */
@property (nonatomic,readonly) NSMutableArray *measurementRectangles;

/**
 *  Gets the collection of measurement spots
 */
@property (nonatomic,readonly) NSMutableArray *measurementSpots;

/**
 *  Adds a new MeasurementSpot to the collection.
 *
 *  @param point The location of the spot.
 *
 *  @return The MeasurementSpot object added to the collection.
 */
- (FLIRMeasurementSpot *) addSpot:(CGPoint) point;


/**
 *  Adds a new MeasurementRectangle to the collection.
 *
 *  @param rect The MeasurementRectangles position and size
 *  @return FLIRMeasurementRectangle
 */
- (FLIRMeasurementRectangle *) addRectangle:(CGRect) rect;


/**
 *  Adds a new MeasurementCircle to the collection.
 *
 *  @param posistion Center position of the Circle
 *  @param radius Radius of the circle
 *  @return FLIRMeasurementCircle
 */
- (FLIRMeasurementCircle *) addCircle:(CGPoint) posistion Radius:(int) radius;


/**
 *  Adds a new MeasurementLine to the collection.
 *
 *  @param y y position of the line
 *  @return FLIRMeasurementLine
 */
- (FLIRMeasurementLine *) addHorizontalLine:(int) y;

/**
 *  Adds a new MeasurementLine to the collection.
 *
 *  @param x x position of the line
 *  @return FLIRMeasurementLine
 */
- (FLIRMeasurementLine *) addVerticalLine:(int) x;

/**
 *  Removes the specified measurement shape from the collection.
 *
 *  @param measurement The Measurement object
 */
- (void) remove:(id) measurement;
@end
