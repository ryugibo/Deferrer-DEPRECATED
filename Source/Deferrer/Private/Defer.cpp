// Copyright 2018 ryugibo. All Rights Reserved.

#include "Defer.h"

#include "AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDeferTest, "Utility.Defer Test", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool FDeferTest::RunTest(const FString& Parameters)
{

	{// Check run defer function
		bool bCheckDeferFunction = false;

		{
			DEFER(
				// Called 2nd.
				bCheckDeferFunction = true;
			);

			// Called 1st.
			bCheckDeferFunction = false;
		}

		TestTrue("bCheckDeferFunction", bCheckDeferFunction);
	}

	{// Check run multiple defer function order
		bool bCheckMultipleFunction = false;

		{
			DEFER(
				// Called 3rd.
				bCheckMultipleFunction = true;
			);
			DEFER(
				// Called 2nd.
				bCheckMultipleFunction = false;
			);

			// Called 1st.
			bCheckMultipleFunction = false;
		}

		TestTrue("bCheckMultipleFunction", bCheckMultipleFunction);
	}

	return true;
}
