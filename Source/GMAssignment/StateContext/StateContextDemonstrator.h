// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GMAssignment/Demonstrator.h"
#include "StateContextDemonstrator.generated.h"

/**
 * 
 */
UCLASS()
class GMASSIGNMENT_API AStateContextDemonstrator : public ADemonstrator
{
	GENERATED_BODY()
public:
	AStateContextDemonstrator();
	
	virtual void Tick(float DeltaTime) override;

	virtual bool ShouldTickIfViewportsOnly() const override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State", meta = (Bitmask, BitmaskEnum = "/Script/GMAssignment.ERelativeContext"))
		int32 Context;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Context")
		TArray<AActor*> Demonstrators;
};
