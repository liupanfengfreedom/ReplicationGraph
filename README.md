# ReplicationGraph
[/Script/OnlineSubsystemUtils.IpNetDriver]
ReplicationDriverClassName="/Game/CustomReplicationGraphBP.CustomReplicationGraphBP_C"

AI on client side check the delta distance with serverside every 2s if the delta distance is bigger than 50m then server force broadcast it location to all client, this is in case AI is culled by grid 
![Snipaste_2022-01-12_00-44-28](https://user-images.githubusercontent.com/22150066/148985194-5a8e4e85-30e8-41f1-94c8-f472d1bbfe37.png)
