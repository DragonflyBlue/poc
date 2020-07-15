//
//  FLIRImageParameters.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import <Foundation/Foundation.h>

/** FLIRImageParameters */
@interface FLIRImageParameters : NSObject

/** Gets or sets the default emissivity for the IR Image. */
@property (readwrite) float emissivity;
/** Gets or sets the distance from camera to focused object. */
@property (readwrite) float objectDistance;
/** Gets or sets the reflected temperature. */
@property (readwrite) float reflectedTemperature;
/** Gets or sets the atmospheric temperature. */
@property (readwrite) float atmosphericTemperature;
/** Gets or sets the external optics temperature. */
@property (readwrite) float externalOpticsTemperature;
/** Gets or sets the external optics transmission. */
@property (readwrite) float externalOpticsTransmission;
/** Gets or sets the atmospheric transmission. */
@property (readwrite) float transmission;
/** Gets or sets the relative humidity (0.0 - 1.0). */
@property (readwrite) float relativeHumidity;

@end
