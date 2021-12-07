// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Spawnable = nullptr;

	TheRoot = CreateDefaultSubobject<USceneComponent>(FName("The Root"));
	TheRoot->SetupAttachment(RootComponent);

	TheTarget = CreateDefaultSubobject<UStaticMeshComponent>(FName("The Target"));
	TheTarget->SetupAttachment(TheRoot);

	PlatformSpawn = CreateDefaultSubobject<USceneComponent>(FName("Platform Spawnpoint"));
	PlatformSpawn->SetupAttachment(TheTarget);

	TheCollider = CreateDefaultSubobject<UBoxComponent>(FName("The Collider"));
	TheCollider->SetupAttachment(TheTarget);
	TheCollider->SetBoxExtent(FVector(TargetWidth + 50, TargetDepth + 300, TargetHeight + 50) / 2);

	ConstructorHelpers::FObjectFinder<UStaticMesh>TargetMesh(TEXT("/Game/Art/Meshes/1M_Cube"));

	if (TargetMesh.Succeeded()) TheTarget->SetStaticMesh(TargetMesh.Object);

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();

	TheCollider->OnComponentBeginOverlap.AddDynamic(this, &ATarget::OnOverlapBegin);
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::OnConstruction(const FTransform& xform)
{
	TheTarget->SetWorldScale3D(FVector(TargetWidth, TargetDepth, TargetHeight) / 100);
	TheTarget->SetRelativeLocation(FVector(TargetWidth / 2, 0, TargetHeight / 2));

	

}

void ATarget::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, TEXT("Actor Overlapped!"));
	if (Spawnable)
	{
		if (CanSpawnPlatform)
		{
		if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, TEXT("Spawnables Loaded"));

		FVector pos = PlatformSpawn->GetComponentLocation();

		GetWorld()->SpawnActor<AActor>(Spawnable, pos, FRotator(0,0,0));

		CanSpawnPlatform = false;

		}
	
	}

}

