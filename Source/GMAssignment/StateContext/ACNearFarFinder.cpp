// Fill out your copyright notice in the Description page of Project Settings.


#include "ACNearFarFinder.h"
#include "GMAssignment/StateContext/ContextHelper.h"
#include "GMAssignment/StateContext/StateContextDemonstrator.h"

// Sets default values for this component's properties
UACNearFarFinder::UACNearFarFinder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACNearFarFinder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UACNearFarFinder::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(const auto StateContextDemonstratorParent = Cast<AStateContextDemonstrator>(GetOwner()))
	{
		for(const auto Actor : StateContextDemonstratorParent->Demonstrators)
		{
			if(const auto TargetDemonstrator = Cast<AStateContextDemonstrator>(Actor))
			{
				if(StateContextDemonstratorParent == TargetDemonstrator)
					continue;
				
				const auto RelativeContext = UContextHelper::GetRelativeContext(StateContextDemonstratorParent, TargetDemonstrator);
				if(UContextHelper::FlagPredicate(RelativeContext, ERelativeContext::Near))
					TargetDemonstrator->SetActorHiddenInGame(false);
				
				else
					TargetDemonstrator->SetActorHiddenInGame(true);
			}
		}
	}
}

