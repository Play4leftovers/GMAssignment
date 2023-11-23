// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColliderComponent.h"
#include "Subsystems/WorldSubsystem.h"
#include "ColliderSystem.generated.h"

/**
 * 
 */
UCLASS()
class GMASSIGNMENT_API UColliderSystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<UColliderComponent*> ColliderComponents;
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Tick(float DeltaTime) override;
	
	void RegisterDemonstrator(UColliderComponent* Collider);
	void UnregisterDemonstrator(UColliderComponent* Collider);
};
