//
//  TDFSDPersistenceSetting.h
//  Pods
//
//  Created by 开不了口的猫 on 2017/9/17.
//
//

#import <Foundation/Foundation.h>
@class TDFSDFunctionModel;

typedef NS_ENUM(NSUInteger, SDMessageRemindType) {
    SDMessageRemindTypeAPIRecord     =  0,
    SDMessageRemindTypeSystemLog     =  1,
};

@interface TDFSDPersistenceSetting : NSObject <NSCoding>

+ (instancetype)sharedInstance;

@property (nonatomic, strong, readonly) NSArray<TDFSDFunctionModel *> *functionList;
@property (nonatomic, strong, readonly) NSArray<NSDictionary<NSString *, id> *> *settingList;

//===================================================================================
//                              OPTIONAL SETTING ITEMS
//===================================================================================

/**
 a setting which decides the type of the remind number. default is SDMessageRemindTypeAPIRecord
 */
@property (nonatomic, assign) SDMessageRemindType messageRemindType;


/**
 a flag to tell the log viewer whether should catch API records. default is YES
 */
@property (nonatomic, assign) BOOL allowCatchAPIRecordFlag;


/**
 a flag to tell the log viewer whether should monitor system logs. default is YES
 */
@property (nonatomic, assign) BOOL allowMonitorSystemLogFlag;
/**
 when log viewer receives a system log message data, we create buffer according to given max-size,
 if over, will cut out the data to given max-size. default is 1MB, just be avaliable for iOS 10.0+
 */
@property (nonatomic, assign) ssize_t limitSizeOfSingleSystemLogMessageData  NS_CLASS_AVAILABLE_IOS(10_0);


/**
 a flag to tell the crash captor whether should capture crash. default is YES
 */
@property (nonatomic, assign) BOOL allowCrashCaptureFlag;
/**
 a flag to tell the crash captor whether need cache crash-log to local file,
 cached file can be look over again in history-list. default is YES
 */
@property (nonatomic, assign) BOOL needCacheCrashLogToSandBox;


/**
 a flag to tell the performance monitor whether should monitor lags which may occurred by UI Thread. default is YES
 */
@property (nonatomic, assign) BOOL allowUILagsMonitoring;
/**
 when a lag has occurred, it is captured if the transaction's delayed response time,
 which is dispatched to the main thread, exceeds this threshold. default is `0.2s`
 */
@property (nonatomic, assign) NSTimeInterval  tolerableLagThreshold;
/**
 a flag to tell the performance monitor whether should monitor application CPU usage. default is YES
 */
@property (nonatomic, assign) BOOL allowApplicationCPUMonitoring;
/**
 a flag to tell the performance monitor whether should monitor application Memory usage. default is YES
 */
@property (nonatomic, assign) BOOL allowApplicationMemoryMonitoring;
/**
 a flag to tell the performance monitor whether should monitor device screen fps. default is YES
 */
@property (nonatomic, assign) BOOL allowScreenFPSMonitoring;
/**
 when fps is monitoring, if fps value exceeds this threshold,
 fps component will born a warnning for user. default is `30`
 */
@property (nonatomic, assign) NSUInteger fpsWarnningThreshold;
/**
 a flag to tell the performance monitor whether should monitor the error caused by wild pointer. default is NO
 In addition, when restart app, the value will restored to 'NO' automatically
 */
@property (nonatomic, assign) BOOL allowWildPointerMonitoring;
/**
 we use the establishment of a no-dealloc target pool to manage, we will kill all targets in pool when the pool size exceeds this threshold, default is 10MB
 */
@property (nonatomic, assign) size_t maxZombiePoolCapacity;

@end