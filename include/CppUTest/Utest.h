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
// TEST.H
//
// This file contains the Test class along with the macros which make effective
// in the harness.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef D_UTest_h
#define D_UTest_h


#include <math.h>
#include "SimpleString.h"
#include "TestInstaller.h"

/*! \brief UTest.h
 * \ingroup someGroup
 *
 * Something about UTest.h
 *
 * \see TEST_GROUP
 * \see TEST
 */

class TestResult;

class Utest
  {
  public:

    Utest(const char* groupName,
         const char* testName,
         const char* fileName,
         int lineNumber);

    virtual ~Utest();

    virtual void testBody(){};

    virtual void run (TestResult& result);
    virtual void executePlatformSpecificTestBody();
    virtual SimpleString getFormattedName() const;

		virtual Utest* addTest(Utest* test);
    virtual Utest *getNext () const;
    virtual bool isLast () const;
    virtual int  countTests();

    bool shouldRun(const SimpleString& groupFilter, const SimpleString& nameFilter) const;
    const SimpleString getName() const;
	const SimpleString getGroup() const;
    const SimpleString getFile() const;
    int getLineNumber() const;

    virtual void setup();
    virtual void teardown();

    static TestResult* getTestResult();
    static Utest* getCurrent();

    virtual bool assertTrue(bool condition, const char* conditionString, const char* fileName, int lineNumber);
    virtual bool assertCstrEqual(const char* expected, const char* actual, const char* fileName, int lineNumber);
    virtual bool assertLongsEqual(long expected, long actual, const char* fileName, int lineNumber);
    virtual bool assertDoublesEqual(double expected, double actual, double threshold, const char* fileName, int lineNumber);
    virtual void fail(const char* text, const char* fileName, int lineNumber);
	
	void setFileName(const char* fileName);
	void setLineNumber(int lineNumber);
	void setGroupName(const char* groupName);
	void setTestName(const char* testName);
  protected:
	
	Utest();
	
    Utest(const char* groupName,
         const char* testName,
         const char* fileName,
         int lineNumber, Utest* nextTest);

    virtual SimpleString getMacroName() const
      {
        return "TEST";
      }

  private:

    const char* group_;
    const char* name_;
    const char* file_;
    int	lineNumber_;
    Utest *next_;
    static TestResult* testResult_;
    static Utest* currentTest_;
  };

class NullTest : public Utest
  {
  public:
    explicit NullTest();
    virtual ~NullTest();

    void testBody()
    {}
		
		static NullTest& instance();
		
		virtual int  countTests();
		virtual Utest*getNext () const;
		virtual bool isLast () const;
  private:

    NullTest(const NullTest&);
    NullTest& operator=(const NullTest&);

  };

#endif
