//
//  FLIRCameraImport.h
//
//  Copyright © 2019 Flir Systems. All rights reserved.
//
//  Initialize and perform import (list and import images).

#ifndef FLIRCameraImport_h
#define FLIRCameraImport_h
#endif

/**
 *  Delegate to return events when files are found on a camera.
 */
@protocol FLIRCameraImportEventDelegate <NSObject>

/**
 *  This event is raised when a file is imported from the camera to the device.
 *
 *  @param event The event is the path to a new file. Encoded as a UTF8String
 */
-(void)fileAdded:(id)event;

/**
 *  This event is raised when error occurs when downloading a file.
 *
 *  @param event The event is the path to the file that had an error. Encoded as a UTF8String
 */
-(void)fileError:(id)event;

/**
 *  This event is raised when error occurs when downloading a file.
 *
 *  @param e Dictionary with error information
 */
-(void)importError:(NSDictionary *) e;


/**
 *  This event is raised to show the progress of bytes downloaded from the device.
 *
 *  @param progress The progress is an int showing the number of bytes downloaded this moment.
 *  @param number   The number is the position in the NSMutableArray (pathsList) sent with StartImport.
 */
-(void)fileProgress:(int)progress forFileNumber:(int) number;

@end

/**
 *  Objects returned by -(NSArray *) listImages:(NSString *)ipAddress;
 *
 */

@interface  FLIRFileObject : NSObject
/** The name of the file, without the path (like Unix's basename)  */
@property (nonatomic) NSString *name;
/** The full URL for this file */
@property (nonatomic) NSString *url;
/** The time this file was last changed */
@property (nonatomic) NSDate *time;
/** The file size in bytes */
@property (nonatomic) long long size;
/** True if this file object represents a directory, false otherwise */
@property (nonatomic) bool isDirectory;
/** groupId */
@end



/**
 *  This class facilitates importing images from Camera.
 */
@interface FLIRCameraImport : NSObject

/**
*  Gets all Flir files from path.
*
*  @param path The file path.
*
*  @return A dictionary with two arrays consisting of file information.
*          Use the dictionary key fileNameList to get an array with file names.
*          And the dictionary key fileSizeList to get an array with file sizes.
*/

-(NSMutableDictionary*) getImages:(NSString *)path __attribute__((deprecated));

/**
 *  Import files from camera.
 *
 *  @param pathsList List of files to import. Array of NSStrings or Array of FLIRFileObject
 *  @param destPath  Destination path.
 *
 *  @return TRUE if all is OK.
 */
-(BOOL) startImport:(NSArray *)pathsList withDestPath:(NSString *) destPath;

/**
 *  Cancels the import session
 */
- (void) cancelImport;
/**
 *  A delegate to handle the events in FLIRCameraImportEventDelegate.
 */
@property (nonatomic,weak) id delegate;

/**
 *  List all Flir files from default active folder in camera.
 *
 *  @param ipAddress Camera ipaddress.
 *
 *  @return Array with FLIRFileObjects.
 */

-(NSArray *) listImages:(NSString *)ipAddress;

/**
 *  List all Flir files from folder in camera.
 *
 *  @param ipAddress Camera ipaddress.
 *  @param workFolder folder, if nil use default active folder in camera.
 *
 *  @return Array with FLIRFileObjects.
 */

-(NSArray *) listImages:(NSString *)ipAddress workFolder:(NSString *) folder;

/**
 * Gets workfolders as a list of folders from the specified camera.
 *
 * @return Returns workfolders as a list of folders from the camera. List may be empty.
 */
-(NSArray *) listWorkfolders:(NSString *)ipAddress;

@end
