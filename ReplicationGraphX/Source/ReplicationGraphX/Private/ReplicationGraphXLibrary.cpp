// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplicationGraphXLibrary.h"
#include "ReplicationGraphV.h"

void UReplicationGraphXLibrary::SetTeamForPlayerController(APlayerController* Player, FName TeamName)
{
	if (UReplicationGraphV* LocusGraph = FindLocusReplicationGraph(Player))
	{
		LocusGraph->SetTeamForPlayerController(Player, TeamName);
		return;
	}

	UE_LOG(LogLocusReplicationGraph, Warning, TEXT("LocusReplicationGraph not found"));
}

void UReplicationGraphXLibrary::AddDependentActor(AActor* ReplicatorActor, AActor* DependentActor)
{
	if (UReplicationGraphV* LocusGraph = FindLocusReplicationGraph(ReplicatorActor))
	{
		LocusGraph->AddDependentActor(ReplicatorActor, DependentActor);
		return;
	}

	UE_LOG(LogLocusReplicationGraph, Warning, TEXT("LocusReplicationGraph not found"));
}

void UReplicationGraphXLibrary::RemoveDependentActor(AActor* ReplicatorActor, AActor* DependentActor)
{
	if (UReplicationGraphV* LocusGraph = FindLocusReplicationGraph(ReplicatorActor))
	{
		LocusGraph->RemoveDependentActor(ReplicatorActor, DependentActor);
		return;
	}

	UE_LOG(LogLocusReplicationGraph, Warning, TEXT("LocusReplicationGraph not found"));
}

void UReplicationGraphXLibrary::ChangeOwnerAndRefreshReplication(AActor* ActorToChange, AActor* NewOwner)
{
	if (UReplicationGraphV* LocusGraph = FindLocusReplicationGraph(ActorToChange))
	{
		LocusGraph->ChangeOwnerOfAnActor(ActorToChange, NewOwner);
		return;
	}

	UE_LOG(LogLocusReplicationGraph, Warning, TEXT("LocusReplicationGraph not found"));
}

UReplicationGraphV* UReplicationGraphXLibrary::FindLocusReplicationGraph(const UObject* WorldContextObject)
{
	if (WorldContextObject)
	{
		if (UWorld* World = WorldContextObject->GetWorld())
		{
			if (UNetDriver* NetworkDriver = World->GetNetDriver())
			{
				if (UReplicationGraphV* LocusGraph = NetworkDriver->GetReplicationDriver<UReplicationGraphV>())
				{
					return LocusGraph;
				}
			}
		}
	}

	return nullptr;
}