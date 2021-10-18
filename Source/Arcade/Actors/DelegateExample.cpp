// Copyright Badsardines 2021.


#include "Arcade/Actors/DelegateExample.h"
#include "Components/SphereComponent.h"

// Sets default values
ADelegateExample::ADelegateExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));

	Root->SetSphereRadius(200.f);
	Root->SetHiddenInGame(false);

	RootComponent = Root;
}

// Called when the game starts or when spawned
void ADelegateExample::BeginPlay()
{
	Super::BeginPlay();

	// Bind OnSphereColliderBeginOverlap function to the delegate
	Root->OnComponentBeginOverlap.AddDynamic(this, &ADelegateExample::OnSphereColliderBeginOverlap);
}

// Called every frame
void ADelegateExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ADelegateExample::OnSphereColliderBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Parameters description:

	/*
	 *  The first param: OverlappedComponent
	 *	- is the component that got overlapped in this case is my USphereComponent.
	 */

	/*
	 *	The second param: OtherActor
	 *	- is the actor that overlapping the collider  
	 */

	/*
	 *	The third param: OtherComp
	 *	- is the component that doing the overlapping if that makes sense lol, 
	 *	  e.g if an UStaticMeshComponent is overlapping this actor (ADelegateExample)
	 *	  so the OverlappedComponent would be the UStaticMeshComponent.  	
	 */

	/*
	 *	The fourth param: OtherBodyIndex
	 *	- is just the component index ( not sure about this one though )
	 */

	/*
	 *	The fifth param: bFromSweep
	 *	- i have no idea about this one
	 */

	/*
	 *	the sixth param: SweepResult
	 *	- Contains FHitResult so I can do SweepResult.GetActor()->GetLocation();
	 *	  something like that, you get the idea.	
	 */
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Something is overlapping me");
}
