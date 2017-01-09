// Copyright NoOneEver 3001

#include "Escape.h"
#include "OpenDoor.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{

	Super::BeginPlay();

	Owner = GetOwner();

}


void UOpenDoor::OpenDoor() 
{

	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));

}


void UOpenDoor::CloseDoor()
{

	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));

}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );



	if (getTotalMassOfActorsOnPlate() > 30.f) //TODO MAKE INTO PARAM
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}


	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) 
	{
		CloseDoor();
	}

}

float UOpenDoor::getTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (const auto& Actor : OverlappingActors) 
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on Pressure Plate"), *Actor->GetName());
	}

	return TotalMass;
}

