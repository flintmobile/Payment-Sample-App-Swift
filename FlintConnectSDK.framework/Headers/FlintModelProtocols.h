//
//  FlintModelProtocols.h
//  FlintConnect
//
//  Created by PC on 3/24/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#ifndef FlintConnect_FMCModelProtocols_h
#define FlintConnect_FMCModelProtocols_h

@protocol FlintTransformerErrorDetector <NSObject>

/**
 *  Transform value with error reporting
 *
 *  @param value the value to be transformed
 *  @param error any error occur during transformation
 *
 *  @return the transformed value
 */
- (id)transformValue:(id)value error:(NSError **)error;

@optional

/**
 *  Reverse transform value when applicable
 *
 *  @param value the value to be reversely transformed
 *  @param error any error occur during transformation
 *
 *  @return the reversely transformed value
 */
- (id)reverseTransformValue:(id)value error:(NSError **)error;

@end

#endif
