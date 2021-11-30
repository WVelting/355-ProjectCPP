// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"


ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(FName("TheRoot"));
	TheRoot->SetupAttachment(RootComponent);

	TheHinge = CreateDefaultSubobject<USceneComponent>(FName("TheHinge"));
	TheHinge->SetupAttachment(TheRoot);

	TheMeshDoor = CreateDefaultSubobject<UStaticMeshComponent>(FName("TheMeshDoor"));
	TheMeshDoor->SetupAttachment(TheHinge);

	TheMeshFrame = CreateDefaultSubobject<UInstancedStaticMeshComponent>(FName("TheMeshFrame"));
	TheMeshFrame->SetupAttachment(TheRoot);

	DoorTimelineComp = CreateDefaultSubobject<UTimelineComponent>(FName("DoorTimelineComp"));


	ConstructorHelpers::FObjectFinder<UStaticMesh> TheCubeMesh(TEXT("/Game/Art/Meshes/1M_Cube"));
	if (TheCubeMesh.Succeeded())
	{
		TheMeshDoor->SetStaticMesh(TheCubeMesh.Object);
		TheMeshFrame->SetStaticMesh(TheCubeMesh.Object);
	}
	

}

void ADoor::UpdateTimelineComp(float Output)
{
	FRotator DoorNewRotation = FRotator(0, Output, 0);
	TheHinge->SetRelativeRotation(DoorNewRotation);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();

	UpdateFunctionFloat.BindDynamic(this, &ADoor::UpdateTimelineComp);

	if (DoorTimelineFloatCurve) DoorTimelineComp->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
	
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::OnConstruction(const FTransform& xform)
{
	Super::OnConstruction(xform);

	TheMeshDoor->SetWorldScale3D(FVector(WidthOfDoor, DepthOfDoor, HeightOfDoor) / 100);

	TheMeshDoor->SetRelativeLocation(FVector(WidthOfDoor/2, 0, HeightOfDoor / 2));

	TheHinge->SetRelativeLocation(FVector(-WidthOfDoor / 2, 0, 0));

	TheMeshFrame->AddInstance(FTransform(FRotator(0, 0, 0), FVector(WidthOfDoor/2 + DepthOfDoor/2, 0, HeightOfDoor/2), FVector(DepthOfDoor, DepthOfDoor*2, HeightOfDoor)/100));
	TheMeshFrame->AddInstance(FTransform(FRotator(0, 0, 0), FVector(-WidthOfDoor / 2 - DepthOfDoor + DepthOfDoor / 2, 0, HeightOfDoor / 2), FVector(DepthOfDoor, DepthOfDoor * 2, HeightOfDoor) / 100));
	TheMeshFrame->AddInstance(FTransform(FRotator(0, 0, 0), FVector(0, 0, HeightOfDoor + DepthOfDoor/2), FVector(WidthOfDoor + DepthOfDoor*2, DepthOfDoor * 2, DepthOfDoor) / 100));

}

void ADoor::Interact()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Player wants to Interact");

	DoorTimelineComp->Play();
}

