//
//  FlintImageStabilizer.h
//  FlintConnect
//
//  Created by PC on 4/20/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class FlintImageStabilizer;

typedef NS_ENUM(NSInteger, FlintImageStabilizerMode) {
  ImageStabilizerModeAutoFocus,
  ImageStabilizerModeStableTimeReached,
};

@protocol FlintImageStabilizerDelegate <NSObject>

@optional

/**
 *  The focus is 'in' when the max displacement is below vibrationThreshold
 *  It is 'out' when the max displacement is above vibrationThreshold + tolerance ammount
 *
 *  @param imageStabilizer the stabilizer
 *  @param isFocus         YES for in focus and NO for out focus
 */
- (void)imageStabilizer:(FlintImageStabilizer *)imageStabilizer temporaryStable:(BOOL)isStable;

/**
 *  Delegate fired when image stablizer aquired stability within defined settings
 *  Giving the IS for the option to stop update directly from this method
 *
 *  @param imageStabilizer the stabilizer
 */
- (void)imageStabilizierAquiredStability:(FlintImageStabilizer *)imageStabilizer;

@end

@interface FlintImageStabilizer : NSObject

- (instancetype)initWithDevice:(AVCaptureDevice *)captureDevice;

/**
 *  when vibration go below the vibrationThreshold and stay within the vibrationTolerance
 *  for longer than the minStableInterval,
 *  stability status will be reported.
 *  Increase this value will make the stabilizer acquire focus lock (not stability) easier and vice versa
 *  Default to 2.5
 */
@property (assign, nonatomic) double vibrationThreshold;

/**
 *  when vibration go below the vibrationThreshold and stay within the vibrationTolerance
 *  for longer than the minStableInterval,
 *  stability status will be reported.
 *  Increaase this value will make the stabilizer stay in focus lock longer and vice versa
 *  Default to 0.15 (15 %)
 */
@property (assign, nonatomic) double vibrationTolerance;

/**
 *  when vibration go below the vibrationThreshold and stay within the vibrationTolerance
 *  for longer than the minStableInterval,
 *  stability status will be reported.
 *  Decrease this value will shorter the time it takes to report stability status. 
 *  However, the shorter the time is, the less accuracy you might have. 
 *  This should be set to be long enough for the camera to aquire focus
 *  Default to 1 second
 */
@property (assign, nonatomic) NSTimeInterval minStableInterval;

/**
 *  During the time of focus lock, if enableAutoFocus is set to YES, stability status will be reported
 *  As soon as focus is acquired on the hardward device even though the minStableInterval may not be reached yet
 *  Default to YES
 */
@property (assign, nonatomic) BOOL enableAutoFocus;

/**
 *  when stability 's reached, this flag give us the report on how stability is acquired
 */
@property (assign, nonatomic) FlintImageStabilizerMode stableMode;

/**
 *  Delegate for call back when stability aquired
 */
@property (weak, nonatomic) id<FlintImageStabilizerDelegate>delegate;

/**
 *  determine if stability update is running
 *
 *  @return YES if it is running, NO otherwise
 */
- (BOOL)isUpdatingStability;

/**
 *  Start checking for stable state. When the stable level aquired, the delegate will be fired
 *  Duplicate call to this method resolve in no effect, just give warning
 */
- (void)startStabilityUpdate;

/**
 *  Stop checking for stable state.
 *  When stability status acquired, this is called automatically
 */
- (void)stopStabilityUpdate;

@end
