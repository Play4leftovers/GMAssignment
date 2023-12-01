// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GMAssignment/Demonstrator.h"
#include "CollisionDemonstrator.generated.h"

UENUM(Blueprintable)
enum ECollisionType
{
	PlaneCollider,
	SphereCollider
};

UCLASS(BlueprintType, Blueprintable)
class GMASSIGNMENT_API ACollisionDemonstrator
	: public ADemonstrator
{
	GENERATED_BODY()

	UPROPERTY()
	USphereComponent* SphereComponent;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionType> CollisionType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Mass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MoveSpeed;	
	
	ACollisionDemonstrator();
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override;

	void AddForce(const FVector& Force);
	void Step(const float DeltaTime);
	void AddImpulse(const FVector& Force);

	float GetRadius() const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ApplyGravity;

	//Defines how much energy is lost between each impact. 1 is no energy lost, 0 is all energy lost
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float Bounciness = 1.0f;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FVector Acceleration;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FVector Velocity;

	UPROPERTY()
	bool Impacted = false;
};
