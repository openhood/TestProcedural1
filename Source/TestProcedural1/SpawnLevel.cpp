// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnLevel.h"


// Sets default values
ASpawnLevel::ASpawnLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	newX = 0.f;
	newY = 0.f;
	oldX.SetNum(100);
	oldY.SetNum(100);
}

// Called when the game starts or when spawned
void ASpawnLevel::BeginPlay()
{
	Super::BeginPlay();
	for (int32 i = 0; i < 100; i++)
	{
		newX = generateX(newX);
		newY = generateY(newY);
		oldX[i] = newX;
		oldY[i] = newY;
		const UWorld* world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = Instigator;
			FVector newVec;
			newVec.Set(newX, newY, 15.f);
			int32 num = FMath::RandRange(0, 2);
			if (num == 0)
			{
				AActor* newActor = GetWorld()->SpawnActor<AProcTree>(treeOne, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else if (num == 1)
			{
				AActor* newActor = GetWorld()->SpawnActor<AProcTree>(treeTwo, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else
			{
				AActor* newActor = GetWorld()->SpawnActor<AProcTree>(treeTree, newVec, FRotator::ZeroRotator, spawnParams);
			}
		}
	}
}

// Called every frame
void ASpawnLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float ASpawnLevel::generateX(float oldUsedX) {
	float passBack = 0.f;
	passBack = FMath::RandRange(-500, 500);
	passBack = passBack + oldUsedX;
	if (passBack < -500.f || passBack > 500.f)
	{
		passBack = generateX(oldUsedX);
	}
	if (!isUsed(oldX, passBack))
	{
		passBack = generateX(oldUsedX);
	}
	return passBack;
}

float ASpawnLevel::generateY(float oldUsedY) {
	float passBack = 0.f;
	passBack = FMath::RandRange(-500, 500);
	passBack = passBack + oldUsedY;
	if (passBack < -500.f || passBack > 500.f)
	{
		passBack = generateY(oldUsedY);
	}
	if (!isUsed(oldY, passBack))
	{
		passBack = generateY(oldUsedY);
	}
	return passBack;
}

bool ASpawnLevel::isUsed(TArray<float> &oldArray, float numCheck) {
	bool flag = true;
	for (int32 i = 0; i < oldArray.Num(); i++)
	{
		if (distanceBetween(oldArray[i], numCheck) < 5.f)
		{
			flag = false;
		}
	}
	return flag;
}

float ASpawnLevel::distanceBetween(float inOne, float inTwo) {
	float passBack = 0.f;
	bool flag = isOneGreater(inOne, inTwo);
	if (flag == true)
	{
		passBack = inOne - inTwo;
	}
	else
	{
		passBack = inTwo - inOne;
	}
	return passBack;
}

bool ASpawnLevel::isOneGreater(float inOne, float inTwo) {
	bool flag = true;
	if (inOne <= inTwo)
	{
		flag = false;
	}
	return flag;
}