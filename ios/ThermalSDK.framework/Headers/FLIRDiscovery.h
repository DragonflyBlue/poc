//
//  FLIRDiscovery.h
//
//  Copyright © 2019 Flir Systems. All rights reserved.
//
//  An interface for discovering cameras in vicinity.
//

#ifndef FLIRDiscovery_h
#define FLIRDiscovery_h

#import "FLIRIdentity.h"

/**
 *  Delegate to return events detected in the camera scanner
 */
@protocol FLIRDiscoveryEventDelegate <NSObject>

/**
 *  This event is raised when new camera device is found.
 *
 */
-(void)cameraFound:(nonnull FLIRIdentity *)cameraIdentity;

/**
 *  This event is raised when a camera device is returning an error.
 *
 *  @param error The error.
 *
 *  @param nsnetserviceserror The NSNetServicesError code
 *
 *  @param iface The interface where the discovery error was encountered.
 */
-(void)discoveryError:(nonnull NSString *)error netServiceError:(int)nsnetserviceserror on:(FLIRCommunicationInterface)iface;

@optional
#pragma mark - Optional event handlers

/**
 *  This event is raised when a camera device is removed from the collection.
 */
-(void)cameraLost:(nonnull FLIRIdentity *)cameraIdentity;

/**
 * This event is called when discovery is finished (i.e. OS limitation).
 * this event it NOT called after "FLIRDiscovery#stop()" is called
 *
 *  @param iface The interface where the discovery was finished .
 */
-(void) discoveryFinished:(FLIRCommunicationInterface)iface;

@end


/**
 Discover cameras on your connected network. Finds a FLIR ONE if connected to your device.
 
 @note Cameras can be reported as found even if they aren't connectable, depending on the implementation (entries could be cached in system services).
       Similarly camera lost events might be delayed, depending on the implementation (some implementations are only refreshed once per 5 minutes).
       One should use `FLIRCamera.connect(...)` if faster feedback is required.

 ### Example Usage
 ```swift
 import UIKit
 import ThermalSDK
 
 class ViewController: UIViewController, FLIRDiscoveryEventDelegate {
 
    // Create a discovery object.
    let discoverer = FLIRDiscovery()

    override func viewDidLoad() {
        super.viewDidLoad()
        // Set the discovere delegate to self.
        discoverer.delegate = self
        // Start discovery on all supported interfaces.
        discoverer.start(FLIRCommunicationInterface.FLIRCommunicationInterfaceLightning)
    }
 
    func cameraFound(_ cameraIdentity: FLIRIdentity) {
        // Handle discovered camera identity object...
    }
 
    // Etc ...
 }
 ```
 */
@interface FLIRDiscovery : NSObject

/**
 *  Start searching for devices on specified interfaces.
 *  The operation is asynchronous, scanning will continue in the background until FLIRDiscovery#stop() is called or OS cancels the operation
 *  @param iface specifying the interfaces to use eg "FLIRCommunicationInterface#FLIRCommunicationInterfaceLightning".
 */
-(void) start: (FLIRCommunicationInterface)iface;

/**
 *  Stop scanning for devices.
 *  Does nothing if no scan is active.
 *  The operation is asynchronous
 */
-(void) stop;

/**
 *  Get detailed camera information from a discovered identity.
 */
//-(nonnull FLIRCameraInformation *) getInformation:(nullable FLIRIdentity *)identity;

/**
 *  Checks if the scanner is active.
 *
 *  @return YES if still scanning for cameras, otherwise NO.
 */
-(BOOL) isDiscovering;

/**
 *  A delegate to handle the events in FLIRDiscoveryEventDelegate.
 */
@property (nonatomic, assign, nullable) id delegate;

@end

#endif
