//
//  FlintAPIConfig.h
//  FlintConnect
//
//  Created by Nidhi on 3/11/15.
//  Copyright (c) 2015 Flint. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, FlintConfigurationEnvironment) {
  EnvironmentStaging,
  EnvironmentProduction,
};

@interface FlintAPIConfig : NSObject

#pragma mark - Service Option

/**
 *  The API Key to start the flint service
 */
@property (copy, nonatomic) NSString *APIKey;

/**
 *  The environment on which flint service run against
 *  Default is staging
 */
@property (assign, nonatomic) FlintConfigurationEnvironment environment;

/**
 *  If username and password is specified, on startup, flint service will attempt to authenticate the user
 */
@property (copy, nonatomic) NSString *username;

/**
 *  If username and password is specified, on startup, flint service will attempt to authenticate the user
 */
@property (copy, nonatomic) NSString *password;

/**
 *  If an sso token is specified, on startup, flint service will attempt to authenticate the user
 */
@property (copy, nonatomic) NSString *ssoToken;

#pragma mark - Convenient Accessor

/**
 *  The unique identifier for the authenticated account
 */
@property (copy, nonatomic, readonly) NSString *accountUid;

/**
 *  The authentication token
 */
@property (copy, nonatomic, readonly) NSString *authToken;

/**
 *  The shared config instance used by the flint service
 *
 *  @return the shared instance
 */
+ (instancetype)sharedInstance;

@end
