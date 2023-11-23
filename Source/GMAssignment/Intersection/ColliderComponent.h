// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ColliderComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMASSIGNMENT_API UColliderComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Radius;
public:
	// Sets default values for this component's properties
	UColliderComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:
	
	virtual void DrawShape(const FColor Color);
};
