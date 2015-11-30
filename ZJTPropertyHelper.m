//
//  ZJTPropertyHelper.m
//  zCounter
//
//  Created by Patrick Zhu on 13-7-5.
//  Copyright (c) 2013年 ZJTSoft. All rights reserved.
//

#import "ZJTPropertyHelper.h"

@implementation ZJTPropertyHelper

-(id) init
{
    self = [super init];
    if (self) {        
    }
    return self;
}

-(id) getExtra:(NSString*) key{
    id value = [[NSUserDefaults standardUserDefaults] objectForKey:key];
    if(value == nil || (NSNull*) value == [NSNull null])
        return nil;
    return value;
}

-(NSNumber*)getNumberExtra:(NSString*) key {
    NSNumber* num = (NSNumber*)[self getExtra:key];
    return num;
}

-(int) getIntExtra:(NSString*) key defalutValue:(int)value{
    NSNumber* num = [self getNumberExtra:key];
    if(!num)
        return value;
    return [num intValue];
}

-(BOOL) getBoolExtra:(NSString*) key defalutValue:(BOOL)value{
    NSNumber* num = [self getNumberExtra:key];
    if(!num)
        return value;
    return [num boolValue];
}

-(float) getFloatExtra:(NSString*) key defalutValue:(float)value{
    NSNumber* num = [self getNumberExtra:key];
    if(!num)
        return value;
    return [num floatValue];
}

-(long long) getLongLongExtra:(NSString*) key defalutValue:(long long)value {
    NSNumber* num = [self getNumberExtra:key];
    if(!num)
        return value;
    return [num longLongValue];
}

-(NSString*) getStringExtra:(NSString*) key{
    return [self getExtra:key];
}

-(id) setExtra:(NSString*) key value:(id) value
{
    [[NSUserDefaults standardUserDefaults] setObject:value forKey:key];
    return self;
}

-(id) setExtra:(NSString*) key intValue:(int) value {
    return [self setExtra:key value:[NSNumber numberWithInt:value]];
}

-(id) setExtra:(NSString*) key floatValue:(float) value{
    return [self setExtra:key value:[NSNumber numberWithFloat:value]];
}

-(id) setExtra:(NSString*) key boolValue:(BOOL) value{
    return [self setExtra:key value:[NSNumber numberWithBool:value]];
}

-(id) setExtra:(NSString*) key stringValue:(NSString*) value{
    return [self setExtra:key value:value];
}

-(id) setExtra:(NSString*) key longLongValue:(long long) value {
    return [self setExtra:key value:[NSNumber numberWithLongLong:value]];
}

@end
