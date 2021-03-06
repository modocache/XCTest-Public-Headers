//
// Copyright (c) 2013-2014 Apple Inc. All rights reserved.
//
// Copyright (c) 1997-2005, Sen:te (Sente SA).  All rights reserved.
//
// Use of this source code is governed by the following license:
// 
// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:
// 
// (1) Redistributions of source code must retain the above copyright notice, 
// this list of conditions and the following disclaimer.
// 
// (2) Redistributions in binary form must reproduce the above copyright notice, 
// this list of conditions and the following disclaimer in the documentation 
// and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL Sente SA OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
// OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Note: this license is equivalent to the FreeBSD license.
// 
// This notice may not be removed from this file.

#import <XCTest/XCAbstractTest.h>

/*!
 * @class XCTestRun
 * A test run collects information about the execution of a test. Failures in explicit
 * test assertions are classified as "expected", while failures from unrelated or
 * uncaught exceptions are classified as "unexpected".
 */
@interface XCTestRun : NSObject {
#ifndef __OBJC2__
@private
    XCTest * _test;
    NSTimeInterval _startDate;
    NSTimeInterval _stopDate;
    NSUInteger _executionCount;
    NSUInteger _failureCount;
    NSUInteger _unexpectedExceptionCount;
#endif
}

/*!
 * @method +testRunWithTest:
 * Class factory method for the XCTestRun class.
 *
 * @param test An XCTest instance.
 *
 * @return A test run for the provided test.
 */
+ (id)testRunWithTest:(XCTest *)test;

/*!
 * @method -initWithTest:
 * Designated initializer for the XCTestRun class.
 *
 * @param test An XCTest instance.
 *
 * @return A test run for the provided test.
 */
- (id)initWithTest:(XCTest *)test;

/*!
 * @property test
 * The test instance provided when the test run was initialized.
 */
@property (readonly, strong) XCTest *test;

/*!
 * @method -start
 * Start a test run. Must not be called more than once.
 */
- (void)start;

/*!
 * @method -stop
 * Stop a test run. Must not be called unless the run has been started. Must not be called more than once.
 */
- (void)stop;

/*!
 * @property startDate
 * The time at which the test run was started, or nil.
 */
@property (readonly, copy) NSDate *startDate;

/*!
 * @property stopDate
 * The time at which the test run was stopped, or nil.
 */
@property (readonly, copy) NSDate *stopDate;

/*!
 * @property totalDuration
 * The number of seconds that elapsed between when the run was started and when it was stopped.
 */
@property (readonly) NSTimeInterval totalDuration;

/*!
 * @property testDuration
 * The number of seconds that elapsed between when the run was started and when it was stopped.
 */
@property (readonly) NSTimeInterval testDuration;

/*!
 * @property testCaseCount
 * The number of tests in the run.
 */
@property (readonly) NSUInteger testCaseCount;

/*!
 * @property executionCount
 * The number of test executions recorded during the run.
 */
@property (readonly) NSUInteger executionCount;

/*!
 * @property failureCount
 * The number of test failures recorded during the run.
 */
@property (readonly) NSUInteger failureCount;

/*!
 * @property unexpectedExceptionCount
 * The number of uncaught exceptions recorded during the run.
 */
@property (readonly) NSUInteger unexpectedExceptionCount;

/*!
 * @property totalFailureCount
 * The total number of test failures and uncaught exceptions recorded during the run.
 */
@property (readonly) NSUInteger totalFailureCount;

/*!
 * @property hasSucceeded
 * YES if all tests in the run completed their execution without recording any failures, otherwise NO.
 */
@property (readonly) BOOL hasSucceeded;

/*!
 * @method -recordFailureWithDescription:inFile:atLine:expected:
 * Records a failure in the execution of the test for this test run. Must not be called
 * unless the run has been started. Must not be called if the test run has been stopped.
 *
 * @param description The description of the failure being reported.
 *
 * @param filePath The file path to the source file where the failure being reported
 * was encountered.
 *
 * @param lineNumber The line number in the source file at filePath where the
 * failure being reported was encountered.
 *
 * @param expected YES if the failure being reported was the result of a failed assertion,
 * NO if it was the result of an uncaught exception.
 *
 */
- (void)recordFailureWithDescription:(NSString *)description inFile:(NSString *)filePath atLine:(NSUInteger)lineNumber expected:(BOOL)expected;

@end
