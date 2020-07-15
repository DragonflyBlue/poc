//
//  FLIRThermalImage.h
//
//  Copyright © 2019 Flir Systems. All rights reserved.
//

#ifndef FLIRThermalImage_h
#define FLIRThermalImage_h
#endif

#import "FLIRImageBase.h"
#import "FLIRMeasurementCollection.h"
#import "FLIRPaletteManager.h"
#import "FLIRImageParameters.h"
#import "FLIRImageStatistics.h"
#import "FLIRFusion.h"
#import "FLIRScale.h"
#import "FLIRThermalValue.h"



/**
 *  Specifies the color distribution of the thermal image.
 */
typedef enum ColorDistribution_type
{
    /**
     *  This is an image-displaying method that distributes the colors according to temperature.
     */
    TemperatureLinear,
    /**
     *  This is an image-displaying method that evenly distributes the color information over 
     *  the existing temperatures of the image. This method to distribute the information can be particularly
     *  successful when the image contains few peaks of very high temperature values.
     */
    HistogramEqualization

} /** Specifies the color distribution of the thermal image. */ ColorDistribution;

/**
 *  Holds information about the camera used to create the Thermal image.
 *  Provides an information about a camera device, like serial number, model, lens type/name.
 *  All information given is as written by the camera. For extra information, refer to the user manual of the camera.
 */
typedef struct CameraInfo
{
    /**  The camera filter information. */
    __unsafe_unretained NSString *filter;

    /**  The camera lens information. */
    __unsafe_unretained NSString *lens;

    /**  The camera model information. */
    __unsafe_unretained NSString *modelName;

    /**  The camera serial number information. */
    __unsafe_unretained NSString *serialNumber;

    /**  The lower limit of the camera's measurement range. */
    FLIRThermalValue *rangeMin;

    /**  The upper limit of the camera's measurement range. */
    FLIRThermalValue *rangeMax;
} /** Defines the CameraInfo */  CameraInformation_t;


/** Specifies the supported distance units. */
typedef NS_ENUM(NSUInteger, DistanceUnit)
{
    /** The metre or meter is the fundamental unit of length in the International System of Units. */
    METER,
    /** International foot (equal to 0.3048 meters). */
    FEET
};

/**
 *  Defines features of a Thermal image created from file or stream with temperature (radiometric) data.
 *  The object of this class can be obtained from Thermal cameras supporting such streaming mode.
 *  There is also a specialized subclass for handling Thermal data stored in files. The ThermalImageFile should be used for them.
 */
@interface FLIRThermalImage : FLIRImageBase

/** The measurements collection. */
@property (nonatomic,readonly) FLIRMeasurementCollection *Measurements;

/** The measurements collection. */
@property (nonatomic,readonly) FLIRPaletteManager *PaletteManager;

/** Gets a Palette object set for this image. */
@property (nonatomic,readwrite) FLIRPalette *Palette;

/**
 *  Gets an ImageParameters object for this instance.
 */
-(FLIRImageParameters *) getImageParameters;

/**
 *  A list of FLIRMeterLinkDevices, one for each externalsensor value
 *
 *  @return  FLIRMeterLinkDevices
 */
- (NSArray *) getExternalSensors;

/**
 *  Gets a UIImage object, which represents an image's colorized pixels data depending on selected FusionMode.
 *
 *  @return An UIImage representing the thermal image.
 */
-(UIImage*) getImage;

/**
 *  Gets an ImageStatistics object providing the statistics for Thermal data.
 *
 *  @return The image statistics in a FLIRImageStatistics object
 */
-(FLIRImageStatistics *) getImageStatistics;


/**
 *  Gets the scale object.
 *
 *  @return The image scale as FLIRScale object
 */
-(FLIRScale *) getScale;

/**
 *  Gets a Fusion object set for this image.
 *
 *  @return The image fusion as a FLIRFusion object
 */
-(FLIRFusion *) getFusion;

/**
 *  Gets the thermal image color distribution.
 *
 *  @return The color distribution.
 */
-(ColorDistribution) getColorDistribution;

/**
 *  Sets the thermal image color distribution.
 *
 *  @param value The color distribution.
 */
-(void) setColorDistribution: (ColorDistribution) value;

/**
 * Gets the CameraInformation describing the device the image was taken with.
 *
 * @return CameraInformation_t
 */
-(CameraInformation_t) getCameraInformation;


/**
 *  Gets a DistanceUnit used to define any distance parameter related with image.
 *
 *  @return DistanceUnit
 */
-(DistanceUnit) getDistanceUnit;


/**
 *  Gets a visual image (photo) as a UIImage extracted from the file.
 */
-(UIImage*) getPhoto;


/**
 *  Gets a TemperatureUnit the ThermalValues are in.
 */
-(TemperatureUnit) getTemperatureUnit;


/**
 *  Gets a text annotations associated with the file.

 @return NSDictionary with label and values
 */
-(NSDictionary<NSString *, NSString *> *) getTextAnnotations;

/**
 *  Sets a text annotations associated with the file.

 @param annotations NSDictionary with label and values
 */
-(void) setTextAnnotations:(NSDictionary<NSString *, NSString *> *) annotations;


/**
 *  Gets a temperature value from a point(x,y) in the Thermal Image.
 *
 *  @param point the pixel coordinate
 *  @return temperature value
 */
-(double) getValueAt:(CGPoint) point;


/**
 *  Gets temperature values from a list of points(x,y) in the Thermal Image.
 *
 *  @param points array with pixel coordinates
 *
 *  @return array with temperature values
 */
-(NSArray<NSNumber *>*)getValues:(NSArray<NSValue *> *) points;


/**
 *  Sets a DistanceUnit used to define any distance parameter related with image.
 *
 */
-(void) setDistanceUnit:(DistanceUnit) value;


/**
 *  Sets a TemperatureUnit the ThermalValues are in.
 */
-(void) setTemperatureUnit:(TemperatureUnit) value;

/**
 *  Saves a thermal image to file.
 *
 *  @param fileName  Path to file.
 *  @param overlay   The UIImageView with ovelay and the thermal image.
 */
-(void) saveAs: (NSString *) fileName imageViewWithOverlay:(UIImageView*) overlay;

/**
 *  Saves a thermal image to file.
 *
 *  @param fileName  Path to file.
 *  @param overlay   The UIImage with ovelay and the thermal image.
 */
-(void) saveAs: (NSString *) fileName imageWithOverlay:(UIImage*) imageWithOverlay;

/**
 *  Saves a thermal image to file.
 *
 *  @param fileName  Path to file.
 */
-(void) saveAs: (NSString *) fileName;

@end
