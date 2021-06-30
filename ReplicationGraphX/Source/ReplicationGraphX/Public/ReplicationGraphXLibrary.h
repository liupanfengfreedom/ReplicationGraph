// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReplicationGraphXLibrary.generated.h"

/**
 * 
 */
UCLASS()
class REPLICATIONGRAPHX_API UReplicationGraphXLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Network")
		static void SetTeamForPlayerController(APlayerController* Player, FName TeamName);

	UFUNCTION(BlueprintCallable, Category = "Network")
		static void AddDependentActor(AActor* ReplicatorActor, AActor* DependentActor);

	UFUNCTION(BlueprintCallable, Category = "Network")
		static void RemoveDependentActor(AActor* ReplicatorActor, AActor* DependentActor);

	UFUNCTION(BlueprintCallable, Category = "Network")
		static void ChangeOwnerAndRefreshReplication(AActor* ActorToChange, AActor* NewOwner);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", Category = "Network"))
		static class UReplicationGraphV* FindLocusReplicationGraph(const UObject* WorldContextObject);
};
