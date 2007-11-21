/*
 * Copyright (c) 2007, Michael Feathers, James Grenning and Bas Vodde
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

///////////////////////////////////////////////////////////////////////////////
//
// TESTRESULT.H
//
// A TestResult is a collection of the history of some test runs.  Right now
// it just collects failures.  Really it just prints the failures.
//
///////////////////////////////////////////////////////////////////////////////



#ifndef D_TestResult_h
#define D_TestResult_h

class Failure;
class TestOutput;
class Utest;

class TestResult
{
  public:
    TestResult (TestOutput&);
    virtual ~TestResult();
  
    virtual void testsStarted ();
	virtual void setCurrentTest(Utest* test);
    virtual void testsEnded ();


    virtual void countTest();
    virtual void countRun();
    virtual void countCheck();
    virtual void countFilteredOut();
    virtual void countIgnored();
    virtual void addFailure (const Failure& failure);

    int getTestCount() const {return testCount;}
    int getRunCount() const {return runCount;}
    int getCheckCount() const {return checkCount;}
    int getFilteredOutCount() const {return filteredOutCount;}
    int getIgnoredCount() const {return ignoredCount;}
    int getFailureCount() const {return failureCount;}

	double getTotalExecutionTime() const;
	void setTotalExecutionTime(double exTime);
  private:
	virtual long GetPlatformSpecificTimeInMillis();

    TestOutput& output;
    int testCount;
    int runCount;
    int checkCount;
    int	failureCount;
    int filteredOutCount;
    int ignoredCount;
    double totalExecutionTime;
    long timeStarted;
  };

#endif
