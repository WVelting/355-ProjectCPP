// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"

#include "Target.generated.h"

UCLASS()
class FUNPROJECT_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USceneComponent* TheRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* PlatformSpawn;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* TheTarget;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UBoxComponent* TheCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Dimensions")
		float TargetHeight = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Dimensions")
		float TargetDepth = 25;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Dimensions")
		float TargetWidth = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawnables")
		TSubclassOf<AActor> Spawnable;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool CanSpawnPlatform=true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& xform) override;

};
