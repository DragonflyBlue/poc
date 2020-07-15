//
//  FLIRFusion.h
//
//  Copyright © 2019 Flir Systems. All rights reserved.
//

#ifndef FLIRFusion_h
#define FLIRFusion_h
#endif 

#import "FLIRFusion.h"
#import "FLIRThermalValue.h"

/**
 *  Specifies the fusion modes of the thermal image.
 */
typedef enum FUSION_MODE
{
    /** IR only. */
    IR_MODE,
    
    /** Visual image only. */
    VISUAL_MODE,
    
    /** Picture in picture fusion. */
    FUSION_PIP_MODE,
    
    /** Thermal fusion. */
    FUSION_THERMAL_MODE,
    
    /** MSX fusion. */
    FUSION_MSX_MODE,
    
    /** Blending. */
    FUSION_BLENDING_MODE,
} /**  Specifies the fusion modes of the thermal image. */ FusionMode;

/**
 *  Enumeration of the different fusion color modes.
 */
typedef enum ColorMode
{
				/// <summary>
				/// Fusion image has visual image in color.
				/// </summary>
				Color = 0,

				/// <summary>
				/// Fusion image has visual image in b/w.
				/// </summary>
				BlackAndWhite = 1
} /** Enumeration of the different fusion color modes. */ VisualColorMode;

/**
 *  This class provides functionality for image fusion.
 *  @remarks Image fusion is a function that will merge the Thermal image with a photo depending on the selected fusion mode.
 */
@interface FLIRFusion : NSObject

/** 
 *  Set the fusion mode
 *
 *  @param mode	The fusion mode.
 */
-(void) setFusionMode: (FusionMode) mode;

/**
 *  Get the fusion mode.
 *
 *  @return The fusion mode.
 */
-(FusionMode) getFusionMode;

/**
 *  Defines multi-spectral fusion image mode.
 *  Thermal MSX (Multi Spectral DynamicImaging) mode displays an infrared image where the edges of the objects are enhanced with information from the visual image.
 *
 *  @note Does no longer change the fusion mode.
 *  @param alpha The intensity of the MSX, 0(zero) means no MSX, 6 should be used as a max level.
 */
-(void) setMSX: (double) alpha;

/**
 * Get thermal image MSX settings.
 */
-(double) getMSX;

/**
 *  Defines the fusion image mode, where Thermal image is displayed in defined area on top of the Visual image.
 *
 *  @note Does no longer change the fusion mode.
 *  @param rect The rectangle where the Thermal image will be placed inside the photo.
 */
-(void) setPictureInPicture: (CGRect) rect;

/**
 *  Get the picture in pipcture rectangle.
 *
 *  @return Rectangle that defines the PiP position and size.
 */
- (CGRect) getPictureInPictureRect;

/**
 *  Defines the fusion image mode, where only the visual image is displayed. Settings for FusionMode Visual.
 *  This mode hides the Thermal Image, only the digital photo is displayed.
 *
 *  @note Does no longer change the fusion mode.
 *  @param mode Currently used color scheme the visual image is displayed in.
 */
-(void) setVisualOnly:(VisualColorMode) mode;

 /**
  * Get thermal image visual only settings.
  */
-(VisualColorMode) getVisualOnly;

/**
 *  Defines the image fusion mode, where thermal and visual image is combined for an output image.
 *
 *  @note Does no longer change the fusion mode.
 *  @param min The minimum blending level between thermal and visual image.
 *  @param max The maximum blending level between thermal and visual image.
 */
-(void) setThermalFusionWithMin: (FLIRThermalValue*) min andMax: (FLIRThermalValue*) max;

/**
 *  Defines the image fusion mode, where thermal and visual image is combined for an output image.
 *
 *  @note Does no longer change the fusion mode.
 *  @param min The minimum blending level between thermal and visual image.
 */
-(void) setThermalFusionWithMin: (FLIRThermalValue*) min;

/**
 *  Defines the image fusion mode, where thermal and visual image is combined for an output image.
 *
 *  @note Does no longer change the fusion mode.
 *  @param max The maximum blending level between thermal and visual image.
 */
-(void) setThermalFusionWithMax: (FLIRThermalValue*) max;

/**
 * Get thermal image thermal fusion min level.
 */
-(FLIRThermalValue*) getThermalFusionMin;

/**
 * Get thermal image thermal fusion max level.
 */
-(FLIRThermalValue*) getThermalFusionMax;


/**
 *  Defines the fusion image mode, where Thermal image blends with the Visual image.
 *  Use Blending mode to display a blended image that uses a mix of infrared pixels and digital photo pixels.
 *  The blending level between both images can be adjusted based on the temperatures stored for the Thermal image.
 *
 *  @note Does no longer change the fusion mode.
 *  @param level The blending level between thermal and visual image.
 *  @param colorMode The color scheme the visual image is displayed in.
 */
-(void) setBlending:(double) level ColorMode:(VisualColorMode) colorMode;

/**
 * Get thermal image thermal blending level.
 */
-(double) getBlendingLevel;

/**
 * Get thermal image thermal blending colormode.
 */
-(VisualColorMode) getBlendingColorMode;

@end
