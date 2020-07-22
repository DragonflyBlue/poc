import UIKit
import Flutter

@UIApplicationMain
@objc class AppDelegate: FlutterAppDelegate {

    override func application(
    _ application: UIApplication,
    didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?
    ) -> Bool {
        let controller : FlutterViewController = window?.rootViewController as! FlutterViewController
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
        let cameraChannel = FlutterMethodChannel.init(name: "com.nationwide.thermal_poc/flir", binaryMessenger: controller.binaryMessenger)
        let vc = CameraHandler()
        cameraChannel.setMethodCallHandler { (call, result) in          
            if call.method == "sdkVersion" {
                cameraChannel.invokeMethod("sdkVersionReturn", arguments: vc.sdkVersion());
            }
            if call.method == "cleanAll" {
                if vc.isConnected() vc.disconnect()
                if !vc.getCameraList().isEmpty() vc.clear()
            }
            // if call.method == "connect" {
            //   connect(vc.getFlirOne());
            // }
            // if call.method == "disconnect" {
            //     vc.disconnect();
            //     result.success(true);
            // }
            // if call.method == "discover" {
            //     startDiscovery();
            // }
            // if call.method == "startStream" {
            //   DispatchQueue.main.async {
            //     @Override
            //     public void run() {
            //       // Call the desired channel message here.
            //       try {
            //           vc.startStream(streamDataListener);
            //       } catch (Exception e) {
            //           Log.d("Fatal error", e.getMessage());
            //       }
            //     }
            //   });
            // }
            // if call.method == "stopStream" {
            //   DispatchQueue.main.async {
            //     @Override
            //     public void run() {
            //       // Call the desired channel message here.
            //       try {
            //           vc.stopStream();
            //       } catch (Exception e) {
            //           Log.d("Fatal error", e.getMessage());
            //       }
            //     }
            //   });
            // }
        }
    }

  // private void startDiscovery() {
  //     cameraHandler.startDiscovery(discoveryEventListener, discoveryStatusListener);
  // }

  // private void stopDiscovery(){
  //     cameraHandler.stopDiscovery(discoveryStatusListener);
  // }

  // private void connect(Identity identity) {
  //     //We don't have to stop a discovery but it's nice to do if we have found the camera that we are looking for
  //     stopDiscovery();

  //     if(connectedIdentity != null) {
  //         new Handler(Looper.getMainLooper()).post(new Runnable(){
  //         @Override
  //         public void run(){
  //             channel.invokeMethod("connected", true);
  //         }
  //         });
  //     }

  //     if(identity == null){
  //         return;
  //     }

  //     connectedIdentity = identity;

  //     if (UsbPermissionHandler.isFlirOne(identity)) {
  //         usbPermissionHandler.requestFlirOnePermisson(identity, getApplicationContext(), permissionListener);
  //     } else {
  //         doConnect(identity);
  //     }

  // }

  // private void doConnect(Identity identity) {
  //     new Thread(new Runnable(){
  //     @Override
  //     public void run(){
  //         try {
  //         cameraHandler.connect(identity, connectionStatusListener);

  //         new Handler(Looper.getMainLooper()).post(new Runnable(){
  //             @Override
  //             public void run(){
  //             channel.invokeMethod("connected", true);
  //             }
  //         });
                  
  //         } catch (IOException e) {

  //         new Handler(Looper.getMainLooper()).post(new Runnable(){
  //             @Override
  //             public void run(){
  //             channel.invokeMethod("connected", false);
  //             }
  //         });
  //         }
  //     }
  //     }).start();
  // }

  // private UsbPermissionHandler.UsbPermissionListener permissionListener = new UsbPermissionHandler.UsbPermissionListener() {
  //     @Override
  //     public void permissionGranted(Identity identity) {
  //         doConnect(identity);
  //     }

  //     @Override
  //     public void permissionDenied(Identity identity) {
  //         stopDiscovery();
  //         cameraHandler.clear();
  //     }

  //     @Override
  //     public void error(UsbPermissionHandler.UsbPermissionListener.ErrorType errorType, final Identity identity) {
          
  //     }
  // };

  // private final CameraHandler.StreamDataListener streamDataListener = new CameraHandler.StreamDataListener() {
  //     @Override
  //     public void temperature(Double temperature) {
  //     try {
  //         new Handler(Looper.getMainLooper()).post(new Runnable() {
  //         @Override
  //         public void run() {
  //             channel.invokeMethod("temperature", temperature);
  //         }
  //         });
  //         // msxBitmap.recycle();
  //     } catch (Exception e) {
  //     }
  //     }

  //     @Override
  //     public void bytes(Bitmap msxBitmap){
  //     ByteArrayOutputStream stream = new ByteArrayOutputStream();
  //     msxBitmap.compress(Bitmap.CompressFormat.JPEG, 100, stream);
  //     byte[] byteArray = stream.toByteArray();
  //     new Handler(Looper.getMainLooper()).post(new Runnable() {
  //         @Override
  //         public void run() {
  //         channel.invokeMethod("streamBytes", byteArray);
  //         }
  //     });
  //     msxBitmap.recycle();
  //     }

  //     @Override
  //     public void onStreamStopped(){
  //     new Handler(Looper.getMainLooper()).post(new Runnable() {
  //         @Override
  //         public void run() {
  //         channel.invokeMethod("streamFinished", true);
  //         }
  //     });
  //     }
  // };

  // private DiscoveryEventListener discoveryEventListener = new DiscoveryEventListener() {
  //     @Override
  //         public void onCameraFound(Identity identity) {
  //         cameraHandler.add(identity);

  //         new Handler(Looper.getMainLooper()).post(new Runnable() {
  //             @Override
  //             public void run() {
  //             // Call the desired channel message here.
  //             channel.invokeMethod("discovered", true);
  //             }
  //         });
  //         }

  //         @Override
  //         public void onDiscoveryError(CommunicationInterface communicationInterface, ErrorCode errorCode) {
          
  //         }
  // };

  // private CameraHandler.DiscoveryStatus discoveryStatusListener = new CameraHandler.DiscoveryStatus() {
  //     @Override
  //     public void started(){};

  //     @Override
  //     public void stopped(){};
  // };

  // private ConnectionStatusListener connectionStatusListener = new ConnectionStatusListener(){
  //     @Override
  //     public void onDisconnected(ErrorCode errorCode){
  //     new Handler(Looper.getMainLooper()).post(new Runnable(){
  //         @Override
  //         public void run(){
  //         channel.invokeMethod("disconnected", true);
  //         }
  //     });
  //     }
  // };

  // @Override
  // protected void onDestroy(){
  //     super.onDestroy(); 
  //     cameraHandler.disconnect();
  // }

  // @Override
  // protected void onStop(){
  //     super.onStop(); 
  //     cameraHandler.disconnect();
  // }
}
