What Is This?

This mod makes non-player placed barbed wire dangerous by adding Barbed Wire damage zones to them which act like player-placed barbed wire.

If a player walks into these 'static' barbed wire objects they will be cut and their clothes will be damaged.

Check out the attached video to see what I mean.

Unfortunately, due to apparent limitations with the game engine, you can't turn all barbed wire fences into damage zones as it seems to crash the server if there are too many damage zones in a small area (eg. the hundreds of NW airfield fences). 

But considering very few players ever climb onto high barbed wire fences it shouldn't matter. Most barbed wire fences are disabled in this mod by default to prevent server crashes, but you can turn them on in the config file if you want to try them.

Only the barbed wire road blocks are turned on by default, which seem to work fine on Chernarus and Livonia as they aren't very common unlike the fences that surround military areas.

Certain smaller maps might work fine with all fences enabled, like Namalsk perhaps, which is why I included all barbed wire fences in the config but left most of them turned off by default. Feel free to play around with them if you're running a smaller map.

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