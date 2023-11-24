// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IntersectionComponent.h"
#include "Subsystems/WorldSubsystem.h"
#include "IntersectionSystem.generated.h"

/**
 * 
 */
UCLASS()
class GMASSIGNMENT_API UIntersectionSystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<UIntersectionComponent*> IntersectionComponents;
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Tick(float DeltaTime) override;
	
	void RegisterIntersector(UIntersectionComponent* Intersector);
	void UnregisterIntersector(UIntersectionComponent* Intersector);
	
	virtual TStatId GetStatId() const override;
};