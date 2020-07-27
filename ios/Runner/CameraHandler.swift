import CoreImage

public protocol StreamDataListener {
    func temperature(temperature: Double)
    func bytes(msxBitmap: CGBitmapInfo)
    func onStreamStopped()
}

protocol DiscoveryStatus {
    func started();
    func stopped();
}

@objc public class CameraHandler: NSObject {
    var streamDataListener: StreamDataListener!
    
    //Discovered FLIR cameras
    var foundCameraIdentities = [FLIRIdentity]();

    //A FLIR Camera
    let camera: FLIRCamera!
    
    let discoverer = FLIRDiscovery()
    
    override init() {
        camera = FLIRCamera()
    }

    func startDiscovery(cameraDiscoveryListener: FLIRDiscoveryEventDelegate, discoveryStatus: DiscoveryStatus) {
        discoverer.start(FLIRCommunicationInterface.lightning)
        discoverer.delegate = cameraDiscoveryListener
        discoveryStatus.started()
    }

    func stopDiscovery(discoveryStatus: DiscoveryStatus) {
        discoverer.stop()
        discoveryStatus.stopped()
    }

    func connect(identity: FLIRIdentity, connectionStatusListener: FLIRRemoteDelegate) throws {
        try camera.connect(identity);
        camera.delegate = connectionStatusListener
    }

    func disconnect() {
        if camera == nil {
            return
        }
        if camera.isGrabbing() {
            stopStream();
        }
        camera.disconnect();
    }

    /**
    * Start a stream of {@link ThermalImage}s images from a FLIR ONE or emulator
    */
    func startStream(listener: StreamDataListener) {
        streamDataListener = listener
        try! camera.subscribeStream()
    }

    /**
    * Stop a stream of {@link ThermalImage}s images from a FLIR ONE or emulator
    */
    func stopStream() {
        camera.unsubscribeStream()
        streamDataListener.onStreamStopped();
    }

    /**
    * Add a found camera to the list of known cameras
    */
    func add(identity: FLIRIdentity) {
        foundCameraIdentities.append(identity)
    }

    func get(i: Int) -> FLIRIdentity {
        return foundCameraIdentities.remove(at: i)
    }

    /**
    * Get a read only list of all found cameras
    */
    func getCameraList() -> Array<FLIRIdentity> {
        return foundCameraIdentities
    }

    func isConnected() -> Bool {
        return camera.isConnected()
    }

    /**
     * Clear all known network cameras
     */
    func clear() {
        foundCameraIdentities.removeAll()
    }

    func getCppEmulator() -> FLIRIdentity? {
        for foundCameraIdentity in foundCameraIdentities {
            if foundCameraIdentity.deviceId().contains("C++ Emulator") {
                return foundCameraIdentity;
            }
        }
        return nil
    }

    func getFlirOneEmulator() -> FLIRIdentity? {
        for foundCameraIdentity in foundCameraIdentities {
            if foundCameraIdentity.deviceId().contains("EMULATED FLIR ONE") {
                return foundCameraIdentity;
            }
        }
        return nil
    }

    func getFlirOne() -> FLIRIdentity? {
        for foundCameraIdentity in foundCameraIdentities {
            let isFlirOneEmulator: Bool = foundCameraIdentity.deviceId().contains("EMULATED FLIR ONE");
            let isCppEmulator: Bool = foundCameraIdentity.deviceId().contains("C++ Emulator");
            if !isFlirOneEmulator && !isCppEmulator {
                return foundCameraIdentity;
            }
        }
        return nil
     }

    var thermalImageStreamListener: FLIRDataReceivedDelegate {
        func imageReceived() {
            //Will be called on a non-ui thread
            DispatchQueue.main.async {
                func run(){
                    self.camera.withImage(self.handleIncomingImage)
                }
            }
        }
    }

    func close() throws {
        camera.disconnect()
    }

    var handleIncomingImage: FLIRThermalImage {
        let thermalImage: FLIRThermalImage
        
        let image = thermalImage.getImage().cgImage
        let msxBitmap = thermalImage.getImage().cgImage?.bitmapInfo

        let x: Int = image!.width / 2;
        let y: Int = image!.height / 2;
        
        thermalImage.setTemperatureUnit(TemperatureUnit.FAHRENHEIT);
        let temperature: Double = thermalImage.getValueAt(CGPoint(x:x, y:y));

        streamDataListener.bytes(msxBitmap: msxBitmap!);
        streamDataListener.temperature(temperature: temperature);
    }

    func sdkVersion() -> String {
        return "SDK Version Mac"
    }
}
