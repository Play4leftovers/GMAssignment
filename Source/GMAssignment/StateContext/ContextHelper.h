// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// Check if a mask has a single flag
#define TEST_BIT(Bitmask, Bit) (((Bitmask) & (1 << static_cast<int32>(Bit))) > 0)

// Check if a mask contains another mask
#define TEST_BITS(Bitmask, Bits) (((Bitmask) & Bits) == Bits)

// Set a specific bit
#define SET_BIT(Bitmask, Bit) (Bitmask |= 1 << static_cast<int32>(Bit))

// Clear a specific bit
#define CLEAR_BIT(Bitmask, Bit) (Bitmask &= ~(1 << static_cast<int32>(Bit)))

#include "CoreMinimal.h"
#include "ERelativeContext.h"
#include "GMAssignment/Constant.h"
#include "GMAssignment/StateContext/StateContextDemonstrator.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ContextHelper.generated.h"

/**
 * 
 */
UCLASS()
class GMASSIGNMENT_API UContextHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Context", meta=(DefaultToSelf = Target))
	static int32 GetRelativeContext(const AActor* Target, const AActor* Other)
	{
		int32 ReturnContext = 0;

		const auto TargetLocation = Target->GetActorLocation();
		const auto OtherLocation = Other->GetActorLocation();
		const auto Direction = OtherLocation - TargetLocation;

		const auto Distance = Direction.Length();
		if(Distance > GContextRange)
			SET_BIT(ReturnContext, ERelativeContext::Far);
		else
			SET_BIT(ReturnContext, ERelativeContext::Near);

		return ReturnContext;
	}

	// Used for checking a group of flags
	UFUNCTION(BlueprintCallable, Category = "Context")
	static bool ContextPredicate(const int32 Test, const int32 Value)
	{
		return TEST_BITS(Test, Value);
	}

	// Used for checking a single flag
	UFUNCTION(BlueprintCallable, Category = "Context")
	static bool FlagPredicate(const int32 Test, const int32 Value)
	{
		return TEST_BIT(Test, Value);
	}	
};
