// Fill out your copyright notice in the Description page of Project Settings.


#include "IntersectionSystem.h"

void UIntersectionSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UIntersectionSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void UIntersectionSystem::RegisterIntersector(UIntersectionComponent* Intersector)
{
}

void UIntersectionSystem::UnregisterIntersector(UIntersectionComponent* Intersector)
{
}
