//
//  FLIRRemoteControl.h
//  FLIR Thermal SDK
//
//  Created on 2018-09-05.
//  Copyright © 2019 FLIR Systems. All rights reserved.
//
//  Camera remote control. Can read, manipulate and listen for events from a Camera.
//

#import <Foundation/Foundation.h>
#import "FLIRIdentity.h"

/**
 ChargingState
 */
typedef NS_ENUM(NSUInteger, FLIRChargingState)
{
    /** Indicates that the battery is not charging because the camera is in "developer mode". */
    DEVELOPER,
    /**  Indicates that the battery is not charging because the camera is not connected to an external power supply. */
    NOCHARGING,
    /**  Indicates that the battery is charging from external power. */
    MANAGEDCHARGING,

    /** Indicates that the battery is charging the iPhone.

      This field indicates that IF there is an iPhone plugged in, it will
      be receiving power from the RBPDevice battery. However, it is still possible
      for the RBPDevice to be in this "mode" EVEN IF THERE IS NO IPHONE ATTACHED.
     */
    CHARGINGSMARTPHONE,

    /**  Indicates that a charging fault occurred (overheat, etc.) */
    FAULT,
    /**  Indicates that a charging heat fault occured */
    FAULTHEAT,
    /**  Indicates that a charging fault occured due to low current from the charging source */
    FAULTBADCHARGER,
    /**  Indicates that a charging fault exists but the iPhone is being charged */
    CHARGINGSMARTPHONEFAULTHEAT,
    /**  Indicates that the device is in charge-only mode */
    MANAGEDCHARGINGONLY,
    /**  Indicates that the device is in phone-charging-only mode */
    CHARGINGSMARTPHONEONLY,
    /**  Indicates that a valid battery charging state was not available. */
    BAD
};

/**
* Inforation of the last stored image on the camera
*/
typedef struct LastStoredImage {
    /** URL of the thermalimage */
    __unsafe_unretained NSURL * _Nonnull thermalImageUrl;
    /** URL of the visualimage */
    __unsafe_unretained NSURL * _Nullable visualImageUrl;
} /** Inforation of the last stored image on the camera */ LastStoredImage_t;

/**
 *  Delegate to return events from a connectad camera.
 */
@protocol FLIRRemoteDelegate <NSObject>

@optional

#pragma mark - Battery
/** Called when battery charging state changes. */
-(void)ChargingStateChanged:(FLIRChargingState) state;
/** Called when remaining battery power changes. */
-(void)PercentageChanged:(int) percent;

#pragma mark - Calibration
/** Called when a NUC state changes. */
-(void)CalibrationStateChanged:(BOOL) state;

#pragma mark - Storage
/** Called when new image was taken on the camera. */
-(void)LastStoredImageChanged:(LastStoredImage_t) laststore;

@end

/**
* Camera battery status monitoring interface
*/
@interface FLIRBattery : NSObject
/** Gets a battery charging state. */
-(FLIRChargingState) getChargingState;
/** Gets remaining battery power in percentage (0-100). */
-(int) getPercentage;
/** Subscribes for battery charging state notifications. */
-(void) subscribeChargingState;
/** Subscribes for remaining battery power notifications. */
-(void) subscribePercentage;
/** Revokes subscription for battery charging state. */
-(void) unsubscribeChargingState;
/** Revokes subscription for remaining battery power. */
-(void) unsubscribePercentage;
@end

/**
* Camera calibration control interface.
*/
@interface FLIRCalibration : NSObject
/** Get calibration state. */
-(BOOL) isActive;
/** Process a one point NUC (Non-uniformity correction) with a black body method. */
-(void) performNUC;
/** Subscribes for camera NUC state notifications. */
-(void) subscribeCalibrationState;
/** Revokes subscription for camera NUC state notifications. */
-(void) unsubscribeCalibrationState;
@end

/**
 *  Camera image storage control interface.
 */
@interface FLIRStorage : NSObject

/**
 * The URL to the directory where the Camera stores images.
 * Note: this call is blocking.
 *
 * @return Returns the URL to the directory where the Camera stores images.
 */
-(nullable NSURL *)  getImagesStorage;

/**
* Get the latest image that was stored in the camera.
* This property will be updated when the file is completely written to storage,
* so there may be some delay from when the picture is taken till the property is updated.
* Note: this call is blocking.
*/
-(LastStoredImage_t)  getLastStoredImage;

/** Subscribes for camera last stored image notifications. */
-(void) subscribeLastStoredImage;
/** Revokes subscription for last stored image. */
-(void) unsubscribeLastStoredImag;
@end

/**
 *  Describes a state of a FLIR camera.
 */
typedef NS_ENUM(NSUInteger, FLIRCameraState)
{
    /** Camera is not ready */
    NOT_READY,
    /** Camera is cooling down */
    COOLING,
    /** Camera is ready */
    READY
};




/**
 *  Camera remote control. Can read, manipulate and listen on events from a Camera.
 */
@interface FLIRRemoteControl : NSObject

/**
 *  A delegate to handle the events.
 */
@property (nonatomic, assign, nullable) id delegate;


/**
 *  Fetch information about that device.
 *
 *  @note This is a synchronous call to the camera, which blocks until the result is retrieved or an error occurs.
 *  @param error Out parameter filled with an error object on failure, or nil on success.
 *  @return The result object on success, or nil on failure.
 */
-(nullable FLIRCameraInformation*)getCameraInformation:(out NSError * _Nullable * _Nullable)error;

/**
 * Get the Battery interface to monitor camera battery status.
 *
 * @return Battery object if it's available, or nil if the Camera model has no battery support.
 */
-(nullable FLIRBattery *) getBattery;

/**
 * Get the camera calibration control interface.
 *
 * @return Calibration object if it's available, or nil if the Camera model has no calibration support.
 */
-(nullable FLIRCalibration *) getCalibration;

/**
 * Get the Storage interface to interact with camera storage (i.e. internal storage or SD card).
 *
 * @return Storage object if it's available, or nil if the Camera model has no storage support.
 */
-(nullable FLIRStorage *) getStorage;

/**
 * Check if the camera is ready for connecting a stream.
 */
-(FLIRCameraState) isCameraReady;

@end
