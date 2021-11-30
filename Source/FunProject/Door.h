// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UObject/ConstructorHelpers.h"

#include "Door.generated.h"



UCLASS()
class FUNPROJECT_API ADoor : public AActor
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

	
	//collider

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& xform) override;

};
