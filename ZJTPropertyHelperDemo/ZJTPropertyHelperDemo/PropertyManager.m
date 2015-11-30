//
//  PropertyManager.m
//  ZJTPropertyHelperDemo
//
//  Created by coin on 11/30/15.
//  Copyright © 2015 ZJTSoft. All rights reserved.
//

#import "PropertyManager.h"

@implementation PropertyManager

BOOL_PROP_IMPL(Logined)
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
