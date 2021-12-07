// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "FallingPlatform.generated.h"

UCLASS()
class FUNPROJECT_API AFallingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFallingPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class USceneComponent* TheRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* ThePlatform;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UBoxComponent* TheCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Dimensions")
	float PlatformHeight = 50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Dimensions")
	float PlatformWidth = 300;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Dimensions")
	float PlatformDepth = 300;

	UPROPERTY(EditAnywhere)
	class UCurveFloat* TimeToFall;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UTimelineComponent* PlatformTimelineComp;

	FOnTimelineFloat UpdateFunctionFloat;

	UFUNCTION()
	void UpdateTimelineComp(float Output);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& xform) override;

};
