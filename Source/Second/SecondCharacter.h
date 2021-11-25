// Write By qianqianjun

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "GameFramework/Character.h"
#include "SecondCharacter.generated.h"

UCLASS(config=Game)
class ASecondCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	bool IsSpeedUp;
	bool IsGunOnHand;
public:
	ASecondCharacter();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	// 添加一把枪
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Mesh)
	USkeletalMeshComponent* Gun;
	// 添加一个大炮
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Mesh)
	USkeletalMeshComponent* Cannon;
	// 添加子弹生成处
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Mesh)
	USceneComponent* BulletLocation;
	// 添加炸弹生成处
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Mesh)
	USceneComponent* Bomb;
	// 这个类用于模拟炸弹，手雷等投掷物体
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=GamePlay)
	TSubclassOf<class AProjectile> ProjectileClass;
	// 添加开火声音
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=GamePlay)
	USoundBase* FireSound;
	// 添加开火动画
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=GamePlay)
	UAnimMontage* FireAnimation;
	// 模式切换
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=GamePlay)
	bool AimMode;
	// 设置最大行走速度
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=GamePlay)
	float MaxWalkSpeed;
protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ThrowBomb();
	
	void MoveForward(float Value);
	
	void MoveRight(float Value);
	
	void TurnAtRate(float Rate);
	
	void LookUpAtRate(float Rate);
	
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);
	
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	void SpeedUp();
	
	UFUNCTION(BlueprintCallable)
	void SwitchMode();

	UFUNCTION(BlueprintCallable)
	void SwitchWeapon();

	UFUNCTION(BlueprintCallable)
	void SetRotationSetting();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

