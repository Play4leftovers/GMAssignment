#include "StateContextDemonstrator.h"
AStateContextDemonstrator::AStateContextDemonstrator()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AStateContextDemonstrator::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
}

bool AStateContextDemonstrator::ShouldTickIfViewportsOnly() const
{
	return false;
}