// Fill out your copyright notice in the Description page of Project Settings.


#include "IntersectionComponent.h"
#include "IntersectionSystem.h"


// Sets default values for this component's properties
UIntersectionComponent::UIntersectionComponent()
{
}

// Called when the game starts
void UIntersectionComponent::BeginPlay()
{
	Super::BeginPlay();
	const auto Subsystem = GetWorld()->GetSubsystem<UIntersectionSystem>();
	Subsystem->RegisterIntersector(this);
}

void UIntersectionComponent::DrawShape(const FColor Color)
{
	if(Drawn) return;
	
	Drawn = true;

	if(Color == FColor::Green)
		GetOwner()->SetActorHiddenInGame(true);
	else
	{
		GetOwner()->SetActorHiddenInGame(false);
	}
	
	DrawDebugSphere(
			GetWorld(),
			GetOwner()->GetActorLocation(),
			Radius,
			16,
			Color
			);
}

