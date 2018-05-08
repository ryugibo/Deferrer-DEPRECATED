// Copyright 2018 ryugibo. All Rights Reserved.

#pragma once

#include "CoreMiscDefines.h"

/**
*
*/
template<typename Predicate>
class DEFERRER_API FDefer
{
public:
	FDefer(Predicate DeferredFunction)
		: _DeferredFunction(DeferredFunction)
	{
	}
	~FDefer()
	{
		_DeferredFunction();
	}

private:
	Predicate _DeferredFunction;
};

template<typename Predicate>
static FDefer<Predicate> DeferLambda(Predicate DeferredFunction)
{
	return FDefer<Predicate>(DeferredFunction);
}

#define DEFER_LAMBDA(lambda) auto ANONYMOUS_VARIABLE(_defer_) = DeferLambda(lambda)
#define DEFER(code) DEFER_LAMBDA([&](){code})
