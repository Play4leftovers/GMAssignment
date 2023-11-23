// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderSystem.h"

void UColliderSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UColliderSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void UColliderSystem::RegisterDemonstrator(UColliderComponent* Collider)
{
}

void UColliderSystem::UnregisterDemonstrator(UColliderComponent* Collider)
{
}
