// Fill out your copyright notice in the Description page of Project Settings.


#include "InterpolatorDemonstrator.h"


// Sets default values
AInterpolatorDemonstrator::AInterpolatorDemonstrator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInterpolatorDemonstrator::BeginPlay()
{
	Super::BeginPlay();
	Origin = GetActorLocation();
	Goal = Origin + TargetPosition;
}

// Called every frame
void AInterpolatorDemonstrator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Time += DeltaTime;
	Time = FMath::Clamp(Time, 0, Duration);
	T = Time / Duration;
	T = FMath::Abs(FMath::PerlinNoise1D(T)*2);
	CurrentValue = Curve->FloatCurve.Eval(T);
	
	const auto MoveVector = FMath::Lerp(Origin, Goal, CurrentValue);
	
	SetActorLocation(MoveVector);

	if(Time >= Duration)
	{
		Reset();
	}
}

void AInterpolatorDemonstrator::Reset()
{
	Time = 0.f;
	CurrentValue = 0.f;
}


