@objc public class CameraHandler: NSObject {
    private static final String TAG = "CameraHandler";

    // private StreamDataListener streamDataListener;

    // public interface StreamDataListener {
    //     public void temperature(Double temperature);
    //     public void bytes(Bitmap msxBitmap);
    //     public void onStreamStopped();
    // }

    //Discovered FLIR cameras
    LinkedList<Identity> foundCameraIdentities = new LinkedList<>();

    //A FLIR Camera
    private Camera camera;


    // public interface DiscoveryStatus {
    //     void started();
    //     void stopped();
    // }

    public CameraHandler() {
        camera = new Camera();
    }

    // /**
    //  * Start discovery of USB and Emulators
    //  */
    // public void startDiscovery(DiscoveryEventListener cameraDiscoveryListener, DiscoveryStatus discoveryStatus) {
    //     DiscoveryFactory.getInstance().scan(cameraDiscoveryListener, CommunicationInterface.USB);
    //     discoveryStatus.started();
    // }

    // /**
    //  * Stop discovery of USB and Emulators
    //  */
    // public void stopDiscovery(DiscoveryStatus discoveryStatus) {
    //     DiscoveryFactory.getInstance().stop(CommunicationInterface.USB);
    //     discoveryStatus.stopped();
    // }

    // public void connect(Identity identity, ConnectionStatusListener connectionStatusListener) throws IOException {
    //     camera.connect(identity, connectionStatusListener);
    // }

    public void disconnect() {
        if (camera == null) {
            return;
        }
        if (camera.isGrabbing()) {
            stopStream();
        }
        camera.disconnect();
    }

    // /**
    //  * Start a stream of {@link ThermalImage}s images from a FLIR ONE or emulator
    //  */
    // public void startStream(StreamDataListener listener) {
    //     streamDataListener = listener;
    //     camera.subscribeStream(thermalImageStreamListener);
    // }

    // /**
    //  * Stop a stream of {@link ThermalImage}s images from a FLIR ONE or emulator
    //  */
    // public void stopStream() {
    //     camera.unsubscribeAllStreams();
    //     streamDataListener.onStreamStopped();
    // }

    // /**
    //  * Add a found camera to the list of known cameras
    //  */
    // public void add(Identity identity) {
    //     foundCameraIdentities.add(identity);
    // }

    // public Identity get(int i) {
    //     return foundCameraIdentities.get(i);
    // }

    // /**
    //  * Get a read only list of all found cameras
    //  */
    // public List<Identity> getCameraList() {
    //     return Collections.unmodifiableList(foundCameraIdentities);
    // }

    public boolean isConnected() {
        return camera.isConnected();
    }

    /**
     * Clear all known network cameras
     */
    public void clear() {
        foundCameraIdentities.clear();
    }

    // public Identity getCppEmulator() {
    //     for (Identity foundCameraIdentity : foundCameraIdentities) {
    //         if (foundCameraIdentity.deviceId.contains("C++ Emulator")) {
    //             return foundCameraIdentity;
    //         }
    //     }
    //     return null;
    // }

    // public Identity getFlirOneEmulator() {
    //     for (Identity foundCameraIdentity : foundCameraIdentities) {
    //         if (foundCameraIdentity.deviceId.contains("EMULATED FLIR ONE")) {
    //             return foundCameraIdentity;
    //         }
    //     }
    //     return null;
    // }

    // public Identity getFlirOne() {
    //     for (Identity foundCameraIdentity : foundCameraIdentities) {
    //         boolean isFlirOneEmulator = foundCameraIdentity.deviceId.contains("EMULATED FLIR ONE");
    //         boolean isCppEmulator = foundCameraIdentity.deviceId.contains("C++ Emulator");
    //         if (!isFlirOneEmulator && !isCppEmulator) {
    //             return foundCameraIdentity;
    //         }
    //     }

    //     return null;
    // }

    // private void withImage(Camera.Consumer<ThermalImage> functionToRun) {
    //     camera.withImage(functionToRun);
    // }


    // /**
    //  * Called whenever there is a new Thermal Image available, should be used in conjunction with {@link Camera.Consumer}
    //  */
    // private final ThermalImageStreamListener thermalImageStreamListener = new ThermalImageStreamListener() {
    //     @Override
    //     public void onImageReceived() {
    //         Log.d("Themal", "image received");


    //         //Will be called on a non-ui thread
    //         new Handler(Looper.getMainLooper()).post(() -> {
    //             try {

    //                 camera.withImage(handleIncomingImage);
    //             } catch (Exception e) {

    //                 Log.d("Thermal", "Error: thermal image error: " + e);
    //             }
    //         });
    //     }
    // }

    // public void close() throws Exception {
    //     camera.close();
    // }

    // /**
    //  * Function to process a Thermal Image and update UI
    //  */
    // private final Camera.Consumer<ThermalImage> handleIncomingImage = new Camera.Consumer<ThermalImage>() {
    //     @Override
    //     public void accept(ThermalImage thermalImage) {
    //         //Will be called on a non-ui thread,
    //         // extract information on the background thread and send the specific information to the UI thread
    //         Bitmap msxBitmap;
    //         {   
    //             final List<Palette> palettes = PaletteManager.getDefaultPalettes();
    //             thermalImage.setPalette(palettes.get(0));
    //             thermalImage.getFusion().setFusionMode(FusionMode.THERMAL_ONLY);
    //             msxBitmap = BitmapAndroid.createBitmap(thermalImage.getImage()).getBitMap();
    //         }



    //         Double temperature;
    //         {
    //             int x = msxBitmap.getWidth() / 2;
    //             int y = msxBitmap.getWidth() / 2;
    //             thermalImage.setTemperatureUnit(TemperatureUnit.CELSIUS);
    //             temperature =  thermalImage.getValueAt(new Point(x, y));
    //         }

    //         streamDataListener.bytes(msxBitmap);
    //         streamDataListener.temperature(temperature);
    //     }
    // }

    func sdkVersion() -> String {
        return "SDK Version Mac"
    }
}