#import <Foundation/Foundation.h>
#import "TaggedObject.h"

typedef enum {
    CheckStatusOk = 1,
    CheckStatusFail = 2,
    CheckStatusUndetermined = 0
} CheckStatus;

@interface Check : TaggedObject

@property (nonatomic, assign) NSUInteger runInterval;

- (id)initWithName:(NSString *)name
           command:(NSString *)command
     directoryPath:(NSString *)directoryPath;

- (NSString *)name;
- (NSString *)command;

- (void)startImmediately:(BOOL)immediately;
- (void)stop;
- (BOOL)isRunning;

- (CheckStatus)status;
- (BOOL)isChanging;

- (NSArray *)info;
- (NSURL *)url;
@end

@interface Check (KVO)
- (void)addObserverForRunning:(id)observer;
- (void)removeObserverForRunning:(id)observer;
@end

@interface Check (Image)
+ (NSString *)statusImageNameForCheckStatus:(CheckStatus)status changing:(BOOL)changing;
@end

@interface Check (Debugging)
- (NSString *)executedCommand;
- (NSString *)stdOut;
- (NSString *)stdErr;
@end
