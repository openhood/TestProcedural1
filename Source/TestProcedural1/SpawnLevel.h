// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProcTree.h"
#include "SpawnLevel.generated.h"

UCLASS()
class TESTPROCEDURAL1_API ASpawnLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float generateX(float oldUsedX);
	float generateY(float oldUsedY);
	bool isUsed(TArray<float> &oldArray, float numCheck);
	float distanceBetween(float inOne, float inTwo);
	bool isOneGreater(float inOne, float inTwo);
private:
	TArray<float> oldX;
	TArray<float> oldY;
	float newX;
	float newY;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Possible Object One")
	TSubclassOf<AProcTree> treeOne;

	UPROPERTY(EditDefaultsOnly, Category = "Possible Object One")
	TSubclassOf<AProcTree> treeTwo;

	UPROPERTY(EditDefaultsOnly, Category = "Possible Object One")
	TSubclassOf<AProcTree> treeTree;

	
};
