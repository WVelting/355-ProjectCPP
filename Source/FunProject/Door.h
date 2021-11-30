// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UObject/ConstructorHelpers.h"
#include "InteractableObject.h"
#include "Components/TimelineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "Door.generated.h"



UCLASS()
class FUNPROJECT_API ADoor : public AActor, public IInteractableObject
{
	GENERATED_BODY()

	
public:	
	ADoor();
	
	//scene component for root
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class USceneComponent* TheRoot;

	//scene component for hinge
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* TheHinge;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* TheBox;*/
	
	// mesh for door
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UStaticMeshComponent* TheMeshDoor;
	
	//mess for door frame
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UInstancedStaticMeshComponent* TheMeshFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	float WidthOfDoor = 200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	float HeightOfDoor = 300;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Settings")
	float DepthOfDoor = 25;

	UPROPERTY(EditAnywhere)
	UCurveFloat* DoorTimelineFloatCurve;

	UPROPERTY(EditAnywhere)
	bool DoorOpen;

	
	//collider

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UTimelineComponent* DoorTimelineComp;

	FOnTimelineFloat UpdateFunctionFloat;

	UFUNCTION()
	void UpdateTimelineComp(float Output);

	UPROPERTY(EditAnywhere, Category = "Door Settings")
	bool IsDoorFlipped = false;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& xform) override;
	virtual void Interact();

};
