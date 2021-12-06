// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/Character.h"
#include "cWizard.generated.h"

UCLASS()
class /*GAMED_API*/ AcWizard : public ACharacter
{
	GENERATED_UCLASS_BODY()

		// Name of the Sprite component
		static FName SpriteComponentName;


public:
	
	/** The main skeletal mesh associated with this Character (optional sub-object). */
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* Sprite;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CamComp;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* RotComp;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ShotPosComp;


	//Sprite Variables..........................................
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* IdleAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* RunAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* JumpAnim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animations)
		class UPaperFlipbook* DesiredAnim;

	//End Sprite vars..........................................

	//State

	const int IDLE = 10;
	const int RUN = 11;
	const int JUMP = 12;


	int STATE = IDLE;
	bool vNewState = true;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DoLanded();
	void DoJumped();
	void DoStopJump();
	void UpdateStates();
	void UpdateAnimations();
	void HorizontalMovement(float Value);

	// Sets default values for this character's properties
	AcWizard();


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns Sprite subobject **/
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }
	FORCEINLINE class USpringArmComponent* GetSpringArm() const { return SpringArm; }
	FORCEINLINE class UCameraComponent* GetCam() const { return CamComp; }
	FORCEINLINE class USceneComponent* GetRot() const { return RotComp; }
	FORCEINLINE class UArrowComponent* GetShot() const { return ShotPosComp; }
};
