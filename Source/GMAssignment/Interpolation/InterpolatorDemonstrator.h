// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GMAssignment/Demonstrator.h"
#include "InterpolatorDemonstrator.generated.h"

UCLASS()
class GMASSIGNMENT_API AInterpolatorDemonstrator : public ADemonstrator
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Duration = 0.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCurveFloat* Curve = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (MakeEditWidget = true))
	FVector TargetPosition;
	
protected:

	float Time = 0.f;
	float CurrentValue = 0;
	float T = 0;

	FVector Origin;
	FVector Goal;
	
public:
	// Sets default values for this actor's properties
	AInterpolatorDemonstrator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Reset();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
