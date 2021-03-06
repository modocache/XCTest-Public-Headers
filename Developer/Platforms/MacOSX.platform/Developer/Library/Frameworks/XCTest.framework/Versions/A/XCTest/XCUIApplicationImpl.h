//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, XCAccessibilityElement, XCUIApplicationProcess;

@interface XCUIApplicationImpl : NSObject
{
    NSString *_path;
    NSString *_bundleID;
    XCUIApplicationProcess *_currentProcess;
}

@property(retain, nonatomic) XCUIApplicationProcess *currentProcess; // @synthesize currentProcess=_currentProcess;
@property(readonly, copy) NSString *bundleID; // @synthesize bundleID=_bundleID;
@property(readonly, copy) NSString *path; // @synthesize path=_path;
@property(nonatomic) long long activationPolicy;
- (void)waitForQuiescence;
- (void)terminate;
- (void)launchWithArguments:(id)arg1 environment:(id)arg2 usingXcode:(BOOL)arg3;
- (void)_waitForLaunchProgressViaProxy:(id)arg1;
- (void)_waitForLaunchTokenFromReceipt:(id)arg1;
@property(nonatomic) unsigned long long state;
@property(nonatomic) int processID;
@property(readonly) XCAccessibilityElement *accessibilityElement;
- (void)dealloc;
- (id)initWithPath:(id)arg1 bundleID:(id)arg2;

@end

