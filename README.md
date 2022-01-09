# ReplicationGraph
[/Script/OnlineSubsystemUtils.IpNetDriver]
ReplicationDriverClassName="/Game/CustomReplicationGraphBP.CustomReplicationGraphBP_C"

AI on client side check the delta distance with serverside every 2s if the delta distance is bigger than 50m then server force broadcast it location to all client, this is in case AI is culled by grid 
