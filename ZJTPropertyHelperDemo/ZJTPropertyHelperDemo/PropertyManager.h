//
//  PropertyManager.h
//  ZJTPropertyHelperDemo
//
//  Created by coin on 11/30/15.
//  Copyright © 2015 ZJTSoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZJTPropertyHelper.h"

@interface PropertyManager :ZJTPropertyHelper

/**
 *  @author PatrickCoin, 15-11-30 18:11:52
 *
 *  BOOL type
 */
BOOL_PROP_DEF(Logined)

/**
 *  @author PatrickCoin, 15-11-30 18:11:05
 *
 *  NSString type
 */
STRING_PROP_DEF(Text)

+(instancetype)sharedIncetance;

@end
