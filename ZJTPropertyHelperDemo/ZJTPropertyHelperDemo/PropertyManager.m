//
//  PropertyManager.m
//  ZJTPropertyHelperDemo
//
//  Created by coin on 11/30/15.
//  Copyright © 2015 ZJTSoft. All rights reserved.
//

#import "PropertyManager.h"

@implementation PropertyManager

/**
 *  @author PatrickCoin, 15-12-01 10:12:12
 *
 *  implementation of Logined
 */
BOOL_PROP_IMPL(Logined)

/**
 *  @author PatrickCoin, 15-12-01 10:12:12
 *
 *  implementation of Text
 */
STRING_PROP_IMPL(Text)

+(instancetype)sharedIncetance
{
    static PropertyManager *incetance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
                  {
                      incetance = [[PropertyManager alloc] init];
                  });
    
    return incetance;
}

@end
