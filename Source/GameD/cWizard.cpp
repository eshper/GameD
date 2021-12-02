// Fill out your copyright notice in the Description page of Project Settings.


#include "cWizard.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"


// Sets default values
AcWizard::AcWizard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(AcWizard::MeshComponentName))

{
	Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(AcWizard::SpriteComponentName);
	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->SetupAttachment(GetCapsuleComponent());
		static Fname FCollisionProfileName(TEXT("CharacterMesh"));
		Sprite->SetCollisionProfileName(FCollisionProfileName);
		Sprite->SetGenerateOverlapEvents(false);
		Sprite->SetFlipbook(IdleAnim);
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	SpringArm->TargetArmLength = 900.0f;
	SpringArm->RelativeRotation = FRotator(0.0f, -90.0f, 0.0f);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bAbsoluteRotation = true;

	CamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CamComp"));
}	



// Called when the game starts or when spawned
void AcWizard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcWizard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AcWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

