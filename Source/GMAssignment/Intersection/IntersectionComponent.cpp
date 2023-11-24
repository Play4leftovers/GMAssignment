// Fill out your copyright notice in the Description page of Project Settings.


#include "IntersectionComponent.h"

#include "IntersectionSystem.h"


// Sets default values for this component's properties
UIntersectionComponent::UIntersectionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	// ...
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
	DrawDebugSphere(
			GetWorld(),
			GetOwner()->GetActorLocation(),
			Radius,
			16,
			Color
			);
}

