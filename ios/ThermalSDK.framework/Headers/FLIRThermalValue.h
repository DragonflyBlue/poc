//
//  ThermalValue.h
//  FLIR Thermal SDK
//
//  Copyright © 2019 FLIR Systems. All rights reserved.
//

#import <Foundation/Foundation.h>

/**  Specifies the supported temperature units. */
typedef NS_ENUM(NSUInteger, TemperatureUnit)
{
    /** The Celsius temperature scale was previously known as the centigrade scale. */
    CELSIUS,
    /** Units in Fahrenheit. */
    FAHRENHEIT,
    /** The Kelvin scale is a thermodynamic (absolute) temperature scale where absolute zero, the theoretical absence of all thermal energy, is zero (0 K). */
    KELVIN,
    /** Signal is the actual value from the IR image not converted to a temperature. A signal value is not absolute; comparison between signal values from different images can be misleading. */
    SIGNAL
};

/**
 *  The possible ThermalValueStates.
 */
typedef NS_ENUM(NSUInteger, ThermalValueState) {
//typedef enum : NSUInteger {
    /** Value is invalid or could not be calculated. */
    Invalid,
    /** Value is OK. */
    Ok,
    /** Value is too high. */
    Overflow,
    /** Value is too low. */
    Underflow,
    /** Value is outside image. */
    Outside,
    /** Value is unreliable. */
    Warning,
    /** Value is not yet calculated, unstable image after restart/case change. */
    Unstable,
    /** Value is OK + compensated with a reference temperature delta. */
    Delta,
}; // ThermalValueState;


/**
 *  This class represents an IR value with additional information.
 */
@interface FLIRThermalValue : NSObject

/**
 * Initialize an "OK" thermal value with specified temperature value and unit
 *
 * @param value Temperature value.
 * @param unit Temperature unit.
 */
- (instancetype)initWithValue:(double) value andUnit:(TemperatureUnit) unit;

/**
 *  Gets the value.
 */
@property (readonly) double value;

/**
 *  Gets the temperature unit of the value.
 */
@property (readonly) TemperatureUnit unit;

/**
 *  Gets the state of the value.
 */
@property (readonly) ThermalValueState state;

@end
