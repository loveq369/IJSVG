//
//  IJSVGCommand.h
//  IconJar
//
//  Created by Curtis Hard on 30/08/2014.
//  Copyright (c) 2014 Curtis Hard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IJSVGPath.h"

typedef NS_ENUM( NSInteger, IJSVGCommandType ) {
    IJSVGCommandTypeAbsolute,
    IJSVGCommandTypeRelative
};

@class IJSVGCommand;

@protocol IJSVGCommandProtocol <NSObject>

@required
+ (void)runWithParams:(CGFloat *)params
           paramCount:(NSInteger)count
      previousCommand:(IJSVGCommand *)command
                 type:(IJSVGCommandType)type
                 path:(IJSVGPath *)path;

+ (NSInteger)requiredParameterCount;

@end

@interface IJSVGCommand : NSObject {
    NSString * commandString;
    NSString * string;
    NSString * command;
    CGFloat * parameters;
    NSInteger parameterCount;
    NSMutableArray * subCommands;
    NSInteger requiredParameters;
    IJSVGCommandType type;
    IJSVGCommand * previousCommand;
    Class<IJSVGCommandProtocol> commandClass;
}

@property ( nonatomic, copy ) NSString * string;
@property ( nonatomic, copy ) NSString * commandString;
@property ( nonatomic, copy ) NSString * command;
@property ( nonatomic, assign ) CGFloat * parameters;
@property ( nonatomic, assign ) NSInteger parameterCount;
@property ( nonatomic, assign ) NSInteger requiredParameters;
@property ( nonatomic, assign ) IJSVGCommandType type;
@property ( nonatomic, retain ) NSMutableArray * subCommands;
@property ( nonatomic, assign ) Class<IJSVGCommandProtocol> commandClass;
@property ( nonatomic, assign ) IJSVGCommand * previousCommand;

- (id)initWithCommandString:(NSString *)commandString;

+ (void)registerClass:(Class)aClass
           forCommand:(NSString *)command;
+ (NSDictionary *)registeredCommandClasses;
+ (Class<IJSVGCommandProtocol>)commandClassForCommandLetter:(NSString *)str;

@end
