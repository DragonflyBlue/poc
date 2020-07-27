import UIKit
import Flutter

@UIApplicationMain
@objc class AppDelegate: FlutterAppDelegate {
    var connectedIdentity: FLIRIdentity? = nil
    let vc: CameraHandler = CameraHandler()
    var cameraChannel: FlutterMethodChannel
        
    override func application(
    _ application: UIApplication,
    didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?
    ) -> Bool {
        let controller : FlutterViewController = window?.rootViewController as! FlutterViewController
        cameraChannel = FlutterMethodChannel.init(name: "com.nationwide.thermal_poc/flir", binaryMessenger: controller.binaryMessenger)
        
        linkNativeCode(controller: controller)
        GeneratedPluginRegistrant.register(with: self)
        return super.application(application, didFinishLaunchingWithOptions: launchOptions)
    }
}

extension AppDelegate {
    func linkNativeCode(controller: FlutterViewController) {
        setupMethodChannelForCamera(controller: controller)
    }
    
    private func setupMethodChannelForCamera(controller: FlutterViewController) {
        cameraChannel.setMethodCallHandler { (call, result) in          
            if call.method == "sdkVersion" {
                self.cameraChannel.invokeMethod("sdkVersionReturn", arguments: self.vc.sdkVersion());
            }
            if call.method == "cleanAll" {
                if self.vc.isConnected() { self.vc.disconnect() }
                if !self.vc.getCameraList().isEmpty { self.vc.clear() }
            }
            if call.method == "connect" {
                self.connect(identity: self.vc.getFlirOne()!);
            }
            if call.method == "disconnect" {
                self.vc.disconnect();
                result(true);
            }
            if call.method == "discover" {
                self.startDiscovery();
            }
            if call.method == "startStream" {
                DispatchQueue.main.async {
                    // Call the desired channel message here.
                    func run(){
                        self.vc.startStream(listener: self.streamDataListener)
                    }
                }
            }
            if call.method == "stopStream" {
                DispatchQueue.main.async {
                    // Call the desired channel message here.
                    func run(){
                        self.vc.stopStream();
                    }
                }
            }
        }
    }

    func startDiscovery() {
        self.vc.startDiscovery(cameraDiscoveryListener: discoveryEventListener, discoveryStatus: DiscoveryStatus.self as! DiscoveryStatus);
    }

    func stopDiscovery(){
        self.vc.stopDiscovery(discoveryStatus: DiscoveryStatus.self as! DiscoveryStatus)
    }

    func connect(identity: FLIRIdentity!) {
        //We don't have to stop a discovery but it's nice to do if we have found the camera that we are looking for
        self.stopDiscovery();

        if connectedIdentity != nil {
            DispatchQueue.main.async {
                func run(){
                    self.cameraChannel.invokeMethod("connected", arguments: true);
                }
            }
        }

        if identity == nil {
            return;
        }

        self.connectedIdentity = identity;
        self.doConnect(identity: identity);
    }

    func doConnect(identity: FLIRIdentity) {
        DispatchQueue.main.async {
            func run(){
                do {
                    try self.vc.connect(identity: identity, connectionStatusListener: self.connectionStatusListener);
                    self.cameraChannel.invokeMethod("connected", arguments: true);
                } catch {
                    self.cameraChannel.invokeMethod("connected", arguments: false);
                }
            }
        }
    }

    var streamDataListener: StreamDataListener {
        func temperature(temperature: Double) {
            DispatchQueue.main.async {
                func run(){
                    self.cameraChannel.invokeMethod("temperature", arguments: temperature);
                }
            }
        }

        func bytes(msxBitmap: CGBitmapInfo){
            let byteArray: UInt32 = msxBitmap.rawValue
            DispatchQueue.main.async {
                func run(){
                    self.cameraChannel.invokeMethod("streamBytes", arguments: byteArray);
                }
            }
        }

        func onStreamStopped(){
            DispatchQueue.main.async {
                func run(){
                    self.cameraChannel.invokeMethod("streamFinished", arguments: true);
                }
            }
        }
    }

    var discoveryEventListener: FLIRDiscoveryEventDelegate {
        func cameraFound(_ cameraIdentity: FLIRIdentity) {
            self.vc.add(identity: cameraIdentity);
            DispatchQueue.main.async {
                // Call the desired channel message here.
                func run(){
                    self.cameraChannel.invokeMethod("discovered", arguments: true);
                }
            }
        }
    }

    var connectionStatusListener: FLIRRemoteDelegate {
        func onDisconnected(_ camera: FLIRCamera, withError: Error?) {
            DispatchQueue.main.async {
                func run(){
                    self.cameraChannel.invokeMethod("disconnected", arguments: true);
                }
            }
        }
    }

    override
    func applicationWillTerminate(_ application: UIApplication) {
        super.applicationWillTerminate(application);
        vc.disconnect();
    }

    override
    func applicationWillResignActive(_ application: UIApplication) {
        super.applicationWillResignActive(application);
        vc.disconnect();
    }
}
