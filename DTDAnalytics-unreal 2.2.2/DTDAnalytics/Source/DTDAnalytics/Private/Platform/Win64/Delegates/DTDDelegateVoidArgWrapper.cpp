// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateVoidArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

DTDDelegateVoidArgWrapper::DTDDelegateVoidArgWrapper(const FDTDAnalyticsInitializationCompleteDelegate *del)
{
    this->del = del;
}

DTDDelegateVoidArgWrapper::~DTDDelegateVoidArgWrapper()
{
    delete del;
}

void DTDDelegateVoidArgWrapper::Call() const
{
    del->ExecuteIfBound();
}

#endif