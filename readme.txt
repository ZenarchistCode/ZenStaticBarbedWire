What Is This?

This mod makes non-player placed barbed wire dangerous by adding Barbed Wire damage zones to them which act like player-placed barbed wire.

If a player walks into these 'static' barbed wire objects they will be cut and their clothes will be damaged.

Check out the attached video to see what I mean.

There is a JSON config that allows you to specify damage zones for various game objects, including how often they damage the player.

Installation Instructions:

Install this mod like any other mod - copy it into your server folder and add it to your mods list. Make sure to copy the .bikey into your server keys if you're not using a server management tool like OmegaManager which does that automatically.

This mod should theoretically work fine as a server-side only mod, but if you have any issues then add it to your server's mod pack.

When you run the mod for the first time a default JSON config will be created in your server profile: %server_root%/profiles/Zenarchist/ZenStaticBarbedWire.json

This JSON file will include the config for each barbed wire object type and also all of their positions on the map. It should work fine with custom-placed objects through the DayZ Editor so long as the object classnames match the ones in the config file.

I recommend using the DayZ Diag tools with Trigger debug boxes enabled to add barbed wire zones to custom objects (edit the MinExtends and MaxExtents to shape the zone). Don't ask me how to do this, find someone much smarter than me to help as I barely managed myself lol.

Repack & Source Code:

You can repack this mod if you like, and do anything else you want with it for that matter. Just keep in mind my future updates and improvements won't be applied so make sure to check back for new versions if you notice any bugs. The source code is on my GitHub at www.zenarchist.io

Enjoy!