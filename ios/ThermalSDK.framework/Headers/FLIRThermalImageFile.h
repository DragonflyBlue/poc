//
//  FLIRThermalImageFile.h
//
//  Copyright © 2019 Flir Systems. All rights reserved.
//

#ifndef FLIRThermalImageFile_h
#define FLIRThermalImageFile_h
#endif 

#import "FLIRThermalImage.h"

/**
 *  Describes a file on the physical file system, which contains a ThermalImage.
 *  Moreover it contains additional data, which helps to analyze and interpret the image.
 */
@interface FLIRThermalImageFile : FLIRThermalImage

/**
 *  Opens an thermal image from the specified file.
 *
 *  @param fileName Path to file.
 *  @return 0 if image was opened -1 if failed
 */
-(int) open: (NSString *) fileName;

/**
 *  Check if the file contains thermal data.
 *
 *  @param fileName  Path to file.
 */
-(bool) isThermalImage:(NSString *) fileName;


/**
 *  Gets an absolute path to the file this image was loaded from.
 */
-(NSString *) getAbsolutePath;


/**
 *  Gets an opened file's name.
 */
-(NSString *) getFileName;

/**
 *  Gets a date when the image was taken.
 */
-(NSDate *) getDateTaken;

/**
 *  Saves current object to file.
 */
-(void) save;

@end




