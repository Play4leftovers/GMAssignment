// Fill out your copyright notice in the Description page of Project Settings.


#include "IntersectionSystem.h"

void UIntersectionSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UIntersectionSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for(const auto IntersectorA : IntersectionComponents)
	{
		for(const auto IntersectorB : IntersectionComponents)
		{
			if(IntersectorA == IntersectorB)
				continue;
			
			const auto Diff = IntersectorA->GetOwner()->GetActorLocation() - IntersectorB->GetOwner()->GetActorLocation();
			const auto RadiusSum = IntersectorA->Radius + IntersectorB->Radius;
			const auto IntersectionBoolean = Diff.Dot(Diff) <= RadiusSum * RadiusSum;
			
			if(IntersectionBoolean)
			{
				IntersectorA->DrawShape(FColor::Red);
				IntersectorB->DrawShape(FColor::Red);
			}
			else
			{
				IntersectorA->DrawShape(FColor::Green);
				IntersectorB->DrawShape(FColor::Green);
			}
		}
	}
}

void UIntersectionSystem::RegisterIntersector(UIntersectionComponent* Intersector)
{
	if(!IntersectionComponents.Contains(Intersector))
		IntersectionComponents.Add(Intersector);
}

void UIntersectionSystem::UnregisterIntersector(UIntersectionComponent* Intersector)
{
	if(IntersectionComponents.Contains(Intersector))
		IntersectionComponents.Remove(Intersector);
}

TStatId UIntersectionSystem::GetStatId() const
{
	return GetStatId();
}
