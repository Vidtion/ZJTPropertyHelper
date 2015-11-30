//
//  ZJTPropertyHelper.h
//  zCounter
//
//  Created by Patrick Zhu on 13-7-5.
//  Copyright (c) 2013年 ZJTSoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZJTPropertyHelper : NSObject
{
    
}

-(id) getExtra:(NSString*) key;
-(NSNumber*)getNumberExtra:(NSString*) key;
-(int) getIntExtra:(NSString*) key defalutValue:(int)value;
-(BOOL) getBoolExtra:(NSString*) key defalutValue:(BOOL)value;
-(float) getFloatExtra:(NSString*) key defalutValue:(float)value;
-(long long) getLongLongExtra:(NSString*) key defalutValue:(long long)value;
-(NSString*) getStringExtra:(NSString*) key;

-(id) setExtra:(NSString*) key value:(id) value;
-(id) setExtra:(NSString*) key intValue:(int) value;
-(id) setExtra:(NSString*) key floatValue:(float) value;
-(id) setExtra:(NSString*) key boolValue:(BOOL) value;
-(id) setExtra:(NSString*) key stringValue:(NSString*) value;
-(id) setExtra:(NSString*) key longLongValue:(long long) value;

@end

#define TYPE_PROP_DEF(name, ptype) -(ptype)get##name; \
                                    -(ZJTPropertyHelper*)set##name:(ptype)value;

#define INT_PROP_DEF(name)  TYPE_PROP_DEF(name, int)
#define INT_PROP_IMPL(name) -(int)get##name { \
                                return [self getIntExtra:@"d_"#name defalutValue:0]; \
                            } \
                                -(ZJTPropertyHelper*)set##name:(int)value { \
                                [self setExtra:@"d_"#name intValue:value]; \
                                return self; \
                            }


#define FLOAT_PROP_DEF(name)  TYPE_PROP_DEF(name, float)
#define FLOAT_PROP_IMPL(name) -(float)get##name { \
                                    return [self getFloatExtra:@"d_"#name defalutValue:0]; \
                                } \
                                -(ZJTPropertyHelper*)set##name:(float)value { \
                                    [self setExtra:@"d_"#name floatValue:value]; \
                                    return self; \
                                }

#define BOOL_PROP_DEF(name)   TYPE_PROP_DEF(name, BOOL)
#define BOOL_PROP_IMPL(name)  -(BOOL)get##name { \
                                    return [self getBoolExtra:@"d_"#name defalutValue:NO]; \
                                } \
                                -(ZJTPropertyHelper*)set##name:(BOOL)value { \
                                    [self setExtra:@"d_"#name boolValue:value]; \
                                    return self; \
                                }

#define LONGLONG_PROP_DEF(name)   TYPE_PROP_DEF(name, long long)
#define LONGLONG_PROP_IMPL(name)  -(long long)get##name { \
return [self getLongLongExtra:@"d_"#name defalutValue:0]; \
} \
-(ZJTPropertyHelper*)set##name:(long long)value { \
[self setExtra:@"d_"#name longLongValue:value]; \
return self; \
}

#define STRING_PROP_DEF(name)   TYPE_PROP_DEF(name, NSString*)
#define STRING_PROP_IMPL(name)  -(NSString*)get##name { \
                                    return [self getStringExtra:@"d_"#name]; \
                                } \
                                -(ZJTPropertyHelper*)set##name:(NSString*)value { \
                                    [self setExtra:@"d_"#name stringValue:value]; \
                                    return self; \
                                }

#define OBJ_PROP_DEF(name)   TYPE_PROP_DEF(name, id)
#define OBJ_PROP_IMPL(name)  -(id)get##name { \
return [self getExtra:@"d_"#name]; \
} \
-(ZJTPropertyHelper*)set##name:(id)value { \
[self setExtra:@"d_"#name value:value]; \
return self; \
}

#define ARRAY_PROP_DEF(name)   TYPE_PROP_DEF(name, NSArray*)
#define ARRAY_PROP_IMPL(name)  -(NSArray*)get##name { \
return [self getExtra:@"d_"#name]; \
} \
-(ZJTPropertyHelper*)set##name:(NSArray*)value { \
[self setExtra:@"d_"#name value:value]; \
return self; \
}

