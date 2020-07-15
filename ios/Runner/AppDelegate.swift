import UIKit
import Flutter

@UIApplicationMain
@objc class AppDelegate: FlutterAppDelegate {
    
    var navigationController: UINavigationController!
    
    override func application(
        _ application: UIApplication,
        didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        let controller : FlutterViewController = window?.rootViewController as! FlutterViewController
        
        linkNativeCode(controller: controller)
        
        GeneratedPluginRegistrant.register(with: self)
        
        self.navigationController = UINavigationController(rootViewController: controller)
        self.window.rootViewController = self.navigationController
        self.navigationController.setNavigationBarHidden(true, animated: false)
        self.window.makeKeyAndVisible()
        
        return super.application(application, didFinishLaunchingWithOptions: launchOptions)
    }
}

extension AppDelegate {
    
    func linkNativeCode(controller: FlutterViewController) {
        setupMethodChannelForCamera(controller: controller)
    }
    
    private func setupMethodChannelForCamera(controller: FlutterViewController) {
        
        let cameraChannel = FlutterMethodChannel.init(name: "com.nationwide.thermal_poc/flir", binaryMessenger: controller.binaryMessenger)
        
        cameraChannel.setMethodCallHandler { (call, result) in
            
            if call.method == "sdkVersion" {
                // let vc = UIStoryboard.init(name: "Main", bundle: .main)
                //         .instantiateViewController(withIdentifier: "CameraViewController") as! CameraViewController
                // if let arguments = call.arguments as? String {
                //     vc.surveyHash = arguments
                // }
                // vc.surveyResult = result
                // self.navigationController.pushViewController(vc, animated: true)
            }
        }
    }
}