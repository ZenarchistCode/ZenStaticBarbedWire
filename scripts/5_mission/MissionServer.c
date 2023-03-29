modded class MissionServer
{
	// Store damage zones
	ref array<ref AreaDamageLoopedDeferred_NoVehicle> StaticBarbedWireDamageZones;

	// Called when server mission initializes
	override void OnInit()
	{
		super.OnInit();

		if (GetZenStaticBarbedWireConfig().DumpObjects)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DumpStaticBarbedWireObjects, 20000, false);
		}
		else
		if (GetZenStaticBarbedWireConfig().TurnedOn)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetupStaticBarbedWireDamageZones, 20000, false);
		}
	}

	// Sets up the barbed wire damage zones
	private void SetupStaticBarbedWireDamageZones()
	{
		StaticBarbedWireDamageZones = new array<ref AreaDamageLoopedDeferred_NoVehicle>;
		ZenStaticBarbedWireType wireType;

		foreach (ZenStaticBarbedWireObject wirePos : GetZenStaticBarbedWireConfig().WirePositions)
		{
			// Get wire type
			wireType = GetZenStaticBarbedWireConfig().GetWireType(wirePos.TypeName);

			if (!wireType)
			{
				Print("[ZenStaticBarbedWire] Error: No wire type found for config'd wire object: " + wirePos.TypeName);
				continue;
			}

			// If this wire type is disabled, skip it.
			if (!wireType.TurnedOn)
				continue;

			foreach (vector loc : wirePos.Locations)
			{
				// Get objects within 0.5 meter of the config'd vector
				array<Object> objectsNearWire = new array<Object>;
				GetGame().GetObjectsAtPosition(loc, 0.5, objectsNearWire, null);

				for (int x = 0; x < objectsNearWire.Count(); x++)
				{
					// Prepare classname(s)
					string debugName = "";
					string className = "";

					// Get classname(s)
					debugName = objectsNearWire[x].GetDebugNameNative();
					className = objectsNearWire[x].ClassName();

					// Convert to lower
					debugName.ToLower();
					className.ToLower();

					// If found object is our wire type, create the damage zone
					if (debugName.Contains(wirePos.TypeName) || className.Contains(wirePos.TypeName))
					{
						// Create damage zone for barbed wire cutting players
						AreaDamageLoopedDeferred_NoVehicle areaDamage = new AreaDamageLoopedDeferred_NoVehicle(objectsNearWire[x]);
						areaDamage.SetDamageComponentType(AreaDamageComponentTypes.HITZONE);
						areaDamage.SetLoopInterval(wireType.LoopInterval);
						areaDamage.SetDeferDuration(wireType.DeferDuration);
						areaDamage.SetExtents(wireType.MinExtents.ToVector(), wireType.MaxExtents.ToVector());
						areaDamage.SetHitZones(wireType.DamageZones);
						areaDamage.SetAmmoName(wireType.AmmoName);
						areaDamage.Spawn();
						StaticBarbedWireDamageZones.Insert(areaDamage);
					}
				};
			}
		}
	}

	// Scan all map objects and dump positions of relevant ones
	private void DumpStaticBarbedWireObjects()
	{
		// Get all objects on the map
		array<Object> objectsOnMap = new array<Object>;
		GetGame().GetObjectsAtPosition(Vector(0, 0, 0), 50000, objectsOnMap, null);
		int objCount = 0;

		foreach (ZenStaticBarbedWireType wireType : GetZenStaticBarbedWireConfig().WireTypes)
		{
			string type = wireType.TypeName;
			type.ToLower();

			// Prepare this object
			ZenStaticBarbedWireObject wireObj = new ZenStaticBarbedWireObject;
			wireObj.TypeName = type;
			array<vector> objLocations = new array<vector>;

			// Cycle through all map objects
			for (int x = 0; x < objectsOnMap.Count(); x++)
			{
				// Prepare classname(s)
				string debugName = "";
				string className = "";

				// Get classname(s)
				debugName = objectsOnMap[x].GetDebugNameNative();
				className = objectsOnMap[x].ClassName();

				// Convert to lower
				debugName.ToLower();
				className.ToLower();

				// If map object is the droid we're looking for, add it to the array
				if (debugName.Contains(type) || className.Contains(type))
				{
					objLocations.Insert(objectsOnMap[x].GetPosition());
					objCount++;
				}
			}

			// Save this object type & all its locations
			wireObj.Locations = objLocations;
			GetZenStaticBarbedWireConfig().WirePositions.Insert(wireObj);
		}

		// Save found objects and disable object dump for next restart
		GetZenStaticBarbedWireConfig().DumpObjects = false;
		GetZenStaticBarbedWireConfig().Save();

		// Clear array
		objectsOnMap.Clear();

		// Setup zones
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetupStaticBarbedWireDamageZones, 5000, false);
	}
}