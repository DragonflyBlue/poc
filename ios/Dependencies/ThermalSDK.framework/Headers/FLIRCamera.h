//
//  FLIRCamera.h
//  FLIR Thermal SDK
//
//  Created on 2018-05-07.
//  Copyright © 2019 FLIR Systems. All rights reserved.
//
//  Manages any FLIR camera.
//

#import <Foundation/Foundation.h>

#import "FLIRIdentity.h"
#import "FLIRRemoteControl.h"
#import "FLIRThermalImage.h"

/**
 *  Block to accept a thermal image from a live stream.
 */
typedef void (^ FLIRThermalImageBlock)(FLIRThermalImage * _Nonnull);


/**
 *  The interface to a FLIR camera of any kind.
 */
@interface FLIRCamera : NSObject

/**
 *  A delegate to handle the events in FLIRDataReceivedDelegate.
 */
@property (weak, nullable) id delegate;

/**
 *  Initialize a camera instance with specified identity.
 *
 *  @param identity the identity of the camera instance to be initialized.
 */
//-(instancetype _Nullable)initWithIdentity:(nonnull FLIRIdentity *)identity;

/**
 *  Connect with the camera. This function is blocking.
 *
 *  @param identity the identity of the camera instance to connect to.
 */
-(BOOL)connect:(nonnull FLIRIdentity *)identity error:(out NSError * _Nullable * _Nonnull)error;

/**
 *  Disconnect from the camera.  This function is blocking.
 */
-(void)disconnect;

/**
 *  Get the connection status.
 */
-(BOOL)isConnected;

/**
 *  Get the connected camera identity.
 *
 *  @return The identity of the currently connected camera or null if no camera is connected.
 */
-(nullable FLIRIdentity *)getIdentity;

/**
 *  Get camera remote controller.
 *
 *  @return nullptr returned if the camera isn't in connected state
 */
-(nullable FLIRRemoteControl *)getRemoteControl;

/**
 *  Subscribe to frame grabbing events.
 *
 *  Starts the frame grabbing.
 *  @param error  The error if subscribeStream returns false
 *  @return returns false if not able to start stream
 */
- (BOOL) subscribeStream:(out NSError * _Nullable * _Nonnull) error;

/**
 *  Unsubscribe from frame grabbing events.
 *
 *  Stops the frame grabbing if there are no remaining subscribers.
 *
 */
-(void)unsubscribeStream;

/**
 * This method ensures a thread-safe access to the received FLIRThermalImage.
 */
-(void)withImage:(nonnull FLIRThermalImageBlock)imageBlock;

/**
 *  Check if we're in frame grabbing state.
 */
-(BOOL)isGrabbing;

@end


/**
 *  Delegate to return events from a connectad camera.
 */
@protocol FLIRDataReceivedDelegate <NSObject>

#pragma mark - Required event handlers
/**
 *  This event is raised when the camera is disconnected unexpectedly, if this method is
 *  implemented in the app, and if the delegate has been initialised.
 *
 *  @param  camera  The camera.
 *  @param  error   An error code.
 */
-(void)onDisconnected:(FLIRCamera *_Nonnull) camera withError:(nullable NSError *)error;

@optional
#pragma mark - Optional event handlers

/**
 *  This event is raised when an image is received from the camera.
 */
-(void)imageReceived;

@end



